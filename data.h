#ifndef DATA_H
#define DATA_H

#include <stdio.h>

#define MAX_LINE_LEN 512
#define NUM_FIELDS 14
#define MAX_FIELD_LEN 128
#define NO_INPUT 0
#define SUCCESS 1

typedef struct cafe cafe_t;

struct cafe {
    int census_year;
    int block_id;
    int property_id;
    int base_property_id;
    char* building_address;
    char* clue_small_area;
    char* business_address;
    char* trading_name;
    int industry_code;
    char* industry_description;
    char* seating_type;
    int number_of_seats;
    double longitude;
    double latitude;
};

cafe_t* create_cafe(FILE *infile);
int read_cafe_info(FILE *infile, char *information[]);

#endif
