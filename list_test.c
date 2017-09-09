#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){

	list* curr = create_list();
	char* one = "First";
	char* two = "Second";
	char* three = "Third";
	char* f = "Four";
	add_to_list(curr, one);
	add_to_list(curr, two);
	add_to_list(curr, three);
	add_to_list(curr, f);
	print_list(curr);
	printf("removing 1\n");
	remove_from_list(curr);
	print_list(curr);
	printf("removing again\n");
	remove_from_list(curr);
	print_list(curr);
	printf("flushing\n");
	flush_list(curr);
	print_list(curr);
	printf("adding data\n");
	add_to_list(curr, f);
	print_list(curr);
	printf("removing\n");
	remove_from_list(curr);
	print_list(curr);
	printf("freeing\n");
	free_list(curr);
	print_list(curr);

	return 0;
}