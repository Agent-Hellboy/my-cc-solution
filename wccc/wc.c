#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include <stdbool.h>
#include <bits/getopt_core.h>

int main(int argc, char *argv[]) {
    int opt;
    // Check if a non-option argument (file name) is present
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-l|-c|-w|-m] filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc < 3) {
        perror("Error: Missing file argument.");
        exit(EXIT_FAILURE);
    }

    char *filename;
    // Extract the file name
    filename = argv[2];

    FILE *ftr = fopen(filename,"r");
    if (ftr == NULL) {
        perror("Error: Unable to open file");
        exit(EXIT_FAILURE);
    }

    struct WcInfo wc_info = readFileContent(ftr);
    while ((opt = getopt(argc, argv, "l:w:c:m")) != -1) {
        switch (opt) {
            case 'l':
                printf("\t %d \t %s", wc_info.line_count+1, filename);
                break;
            case 'w':
                printf("\t %d \t %s", wc_info.word_count, filename);
                break;
            case 'c':
                printf("\t %d \t %s", wc_info.char_count, filename);
                break;
            case 'm':
                printf("\t %d \t %d \t %d %s",wc_info.line_count,wc_info.word_count,wc_info.char_count, filename);
                break;
        }
    }

    fclose(ftr);
    return 0;
}
