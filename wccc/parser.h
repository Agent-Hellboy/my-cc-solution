#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>


struct WcInfo {
    int line_count;
    int word_count;
    int char_count;
};

struct WcInfo readFileContent(FILE *file);

#endif /* PARSER_H */
