#ifndef PROCESSING_H
#define PROCESSING_H

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dictionary.h"

#define MAX_FIELD_LEN 128

char *read_user_input();
void process_query(dict_t *dict, FILE *outfile);
int find_cafe(dict_t *dict, char* query, FILE *outfile);
void fprint_cafe(cafe_t *cafe, FILE *outfile);

#endif
