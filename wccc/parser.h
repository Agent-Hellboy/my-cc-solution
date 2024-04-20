#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>


struct WcInfo {
    int byte_size;
    int line_count;
    int word_count;
    int char_count;
};

void counts(FILE *file, struct WcInfo *wc_info);
struct WcInfo readFileContent(FILE *file);

#endif /* PARSER_H */
