#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dictionary.h"
#include "data.h"


/* dictionary.c

Created by Ken Liem and Leo Brooks on the 09/08/2023

Functions that involve the actions of a dictionary
(an abstract linked list data type).

*/


// Creates a dictionary from the information given in the input file
dict_t* create_dictionary(FILE *infile) {
    dict_t *dict;
    dict = malloc(sizeof(*dict));
    assert(dict);

    // Passes the header line, as we don't need it 
    char header[MAX_LINE_LEN + 1];
    fgets(header, MAX_LINE_LEN + 1, infile);
    
    node_t *current = dict;
    node_t *previous;
    // Assign nodes in the dictionary to cafes while there is input
    while((current -> cafe_info = create_cafe(infile)) != NULL) {
        current -> next = malloc(sizeof(*(current -> next)));
        assert(current -> next);
        previous = current;
        current = current -> next;
    }

    // Frees the extra node that we created from previous input
    free(current);
    previous -> next = NULL;
    return dict;
}

// Frees every node and information in the dictionary
void free_dictionary(dict_t *dict) {
    node_t* previous;
    node_t* current = dict;
    // Traverse the dictionary, freeing data and nodes until none exist
	while(current != NULL) {
        node_t* previous = current;
        current = current -> next;
        cafe_t* cafe = previous -> cafe_info;
        free(cafe -> building_address);
        free(cafe -> clue_small_area);
	    free(cafe -> business_address);
   	    free(cafe -> trading_name);
   	    free(cafe -> industry_description);
   	    free(cafe -> seating_type);
	    free(cafe);
        free(previous);
	}
	free(current);
}

