#include "parser.h"
#include <stdlib.h>
#include <stdbool.h>

void counts(FILE *file, struct WcInfo *wc_info) {
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
        fprintf(stderr, "Error reading file\n");
    }
}




struct WcInfo readFileContent(FILE *file) {
    struct WcInfo wc_info;
    wc_info.byte_size = 0;
    wc_info.char_count = 0;
    wc_info.word_count = 0;
    wc_info.line_count = 0;
    if (file == NULL) {
        fprintf(stderr, "Error: File pointer is NULL\n");
        return wc_info;
    }

    fseek(file, 0, SEEK_END); // Move the file pointer to the end
    long fileSize = ftell(file); // Get the file size

    if (fileSize == -1) {
        perror("Error getting file size");
        fclose(file);
        return wc_info;
    }
    fseek(file, 0, SEEK_SET); // Move the file pointer back to the beginning
    counts(file,&wc_info);

    if (fileSize <= 0) {
        fprintf(stderr, "Error: File is empty or cannot determine file size\n");
        return wc_info;
    }

    wc_info.byte_size = fileSize;
    return wc_info;
}