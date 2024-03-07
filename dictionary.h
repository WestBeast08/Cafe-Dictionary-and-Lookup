#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdio.h>
#include "data.h"

#define MAX_STRING_LEN 128
#define MAX_LINE_LEN 512

typedef struct node node_t;

struct node {
    cafe_t *cafe_info;
    struct node *next;
};

typedef node_t dict_t;

void create_linked_list(FILE *f, node_t *head);
dict_t* create_dictionary(FILE *f);
void free_dictionary(node_t *head);
#endif
