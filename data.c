#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "data.h"


/* data.c 

Created by Ken Liem and Leo Brooks 09/08/2023

Takes CSV file input of cafe information and stores it
into a structured cafe type.

*/

// Creates a cafe from given input information
cafe_t* create_cafe(FILE *infile) {
    char* information[NUM_FIELDS];

    // Return a null pointer for when there is no more input 
    if(read_cafe_info(infile, information) == NO_INPUT) {
        cafe_t *finished = NULL;
        return finished;
    }

    // Unpack the input information into the given cafe properties
    cafe_t *cafe = malloc(sizeof(*cafe));
      assert(cafe);
    
    cafe -> census_year = atoi(information[0]);
    cafe -> block_id = atoi(information[1]);
    cafe -> property_id = atoi(information[2]);
    cafe -> base_property_id = atoi(information[3]);
    cafe -> building_address = strdup(information[4]);
    cafe -> clue_small_area = strdup(information[5]);
    cafe -> business_address = strdup(information[6]);
    cafe -> trading_name = strdup(information[7]);
    cafe -> industry_code = atoi(information[8]);
    cafe -> industry_description = strdup(information[9]);
    cafe -> seating_type = strdup(information[10]);
    cafe -> number_of_seats =  atoi(information[11]);
    cafe -> longitude = atof(information[12]);
    cafe -> latitude = atof(information[13]);
    
    // All information is now seperate from the array allowing us to free
    for(int k = 0; k< NUM_FIELDS; k++) {
        free(information[k]);
    }

    return cafe;
}

/*
Reads input of cafe information from a CSV file
and seperates the cafe information fields into an array
*/
int read_cafe_info(FILE *infile, char *information[]) {
    char line[MAX_LINE_LEN + 1];
    fgets(line, MAX_LINE_LEN + 1, infile);
    assert(line);
    if(feof(infile)) {
        return NO_INPUT;
    }
   
    char* info;
    int i = 0;
    // Breaks up the CSV information fields which are seperated by commas
    info = strtok(line, ",");

    while (info != NULL && i < NUM_FIELDS) { 

        /* 
        There are cases of fields containing commas, denoted
        by "" around the field. To deal with them read the field
        across multiple sections and them combine them
        */
        if(strchr(info, '\"')) {
            for (int k = 0; k < strlen(info); k++) {
                info[k] = info[k+1];
            }

            // Stores the first section of the field
            char *first = info;
            first = strcat(first, ",");
            // Stores rest of field and combines with the first section
            info = strtok(NULL, "\"");
            int field_len = strlen(first) + strlen(info) + 1;
            information[i] = malloc((field_len) * sizeof(*(information[i])));
            assert(information[i]);
            strcpy(information[i], "");
            strcat(information[i], first);
            strcat(information[i], info);
            info = strtok(NULL, ",");

            
        }

        else {
            int info_len = strlen(info) + 1;
            information[i] = malloc((info_len) * sizeof(*(information[i])));
            assert(information[i]);
            strcpy(information[i], info);
            info = strtok(NULL, ",");
        } 
        i++;
    }
    return SUCCESS;
}



