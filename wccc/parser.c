#include "parser.h"
#include <stdlib.h>
#include <stdbool.h>

static void counts(FILE *file, struct WcInfo *wc_info) {
    int ch; // Variable to store each character read from the file
    bool in_word = false; // Flag to track if currently inside a word


    // Move character by character until EOF is reached
    while ((ch = fgetc(file)) != EOF) {
        // Process the character (count characters)
        wc_info->char_count++;

        // Check if newline is found
        if (ch == 10){
            wc_info->line_count+=1;
        }
        // Check if the current character is part of a word
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            // If not already inside a word, increment word count and set flag
            if (!in_word) {
                wc_info->word_count++;
                in_word = true;
            }
        } 
        else {
            // If character is not part of a word, reset the flag
            in_word = false;
        }
    }

    // Check for errors during file reading
    if (ferror(file)) {
        perror("Error reading file");
    }
}




struct WcInfo readFileContent(FILE *file) {
    struct WcInfo wc_info;
    wc_info.char_count = 0;
    wc_info.word_count = 0;
    wc_info.line_count = 0;
    if (file == NULL) {
        fprintf(stderr, "Error: File pointer is NULL\n");
        return wc_info;
    }
    counts(file,&wc_info);

    return wc_info;
}