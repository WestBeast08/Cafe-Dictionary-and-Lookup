#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "dictionary.h"
#include "processing.h"


/* main.c 

Created by Ken Liem and Leo Brooks on 06/08/2023 

This program aims to read a csv based on cafes and then store them
in a dictionary.

Then it will process the user's query of cafe trading name and search the
dictionary for cafes which match this query. The information of the
found cafes will then be stored in an outfile.

It will also print the number of matches from the search to stdout.

To run program:
./dict1 stage datafile outfile < input 

Example:
./dict1 1 tests/dataset_1.csv output.out < tests/test1.in

*/

int main(int argc, char **argv) {
	FILE *infile = fopen(argv[2], "r");
	FILE *outfile = fopen(argv[3], "w"); 
	assert(infile);
	assert(outfile);

	dict_t *dict = NULL;
	dict = create_dictionary(infile);
	process_query(dict, outfile);
	free_dictionary(dict);
	
	fclose(infile);
	fclose(outfile);

	return 0;
}
