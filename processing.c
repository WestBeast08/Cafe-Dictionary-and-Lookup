




#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "processing.h"


/* processing.c

Created by Ken Liem and Leo Brooks on 14/08/2023

Involves functions that interact with the query of the user.
Reading and processing queries to search for any matches
in the dictionary. Printing results to various outputs.

*/

// Reads user query string from stdin
char *read_user_input() {
    char *input = malloc(MAX_FIELD_LEN * sizeof(*(input))); 
    assert(input);

    if(scanf("%[^\n]", input) != EOF) {
        getchar();
        return input;
    }

    free(input);
    return NULL;
}

/* 
Reads in a query, searches for matches in the dictionary, and prints search
results to an outfile as well as the number of results to stdout
*/
void process_query(dict_t *dict, FILE* outfile) {
    char *query;
    int locations;

    while(query = read_user_input()) {
        // Information to the outfile
        fprintf(outfile, "%s\n", query);

        // Information to stdout
        printf("%s --> ", query);
        if((locations = find_cafe(dict, query, outfile)) == 0) {
            printf("NOT FOUND\n");
        }
        else {
            printf("%d\n", locations);
        }

        free(query);
    }
}

// Finds cafes from the dictionary matching the query property
int find_cafe(dict_t* dict, char* query, FILE* outfile) {
    node_t* current = dict;
    int found = 0;

    while(current) {
        // In our case, query property is the trading name
        if(strcmp(current -> cafe_info -> trading_name, query) == 0) {
            fprint_cafe(current -> cafe_info, outfile);
            found++;
        }
        current = current -> next;
    }

    return found;
}


// Prints out the cafe's information to the outfile
void fprint_cafe(cafe_t* cafe, FILE* outfile) {
    fprintf(outfile,
        "--> census_year: %d || "
        "block_id: %d || "
        "property_id: %d || "
        "base_property_id: %d || " 
        "building_address: %s || "
        "clue_small_area: %s || "
        "business_address: %s || "
        "trading_name: %s || " 
        "industry_code: %d || " 
        "industry_description: %s || " 
        "seating_type: %s || "
        "number_of_seats: %d || "
        "longitude: %.5f || " 
        "latitude: %.5f || \n",
        cafe -> census_year, cafe -> block_id, cafe -> property_id,
        cafe -> base_property_id, cafe -> building_address,
        cafe -> clue_small_area, cafe -> business_address,
        cafe -> trading_name, cafe -> industry_code,
        cafe -> industry_description, cafe -> seating_type,
        cafe -> number_of_seats, cafe -> longitude, cafe -> latitude);
}
