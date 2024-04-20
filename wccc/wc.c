#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include <stdbool.h>
#include <bits/getopt_core.h>

int main(int argc, char *argv[]) {
    int opt;
    char *filename;
    if (optind < argc) {
        // At least one non-option argument present
        filename = argv[optind+1]; 
    } else {
        fprintf(stderr, "Missing file argument.\n");
        return 1;
    }
    FILE *ftr = fopen(filename,"r");
    if (ftr == NULL) {
        fprintf(stderr, "Error: Unable to open file\n");
        return 1;
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
