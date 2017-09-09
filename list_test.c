#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(){
	//Test case with empty list
	printf("Starting of Test Case 1\n");
	printf("\n");
	printf("\n");
	list* A = create_list();
	remove_from_list(A);
	print_list(A);
	flush_list(A);
	free_list(A);
	printf("\n");
	printf("\n");

	//Test case with list containing only one string
	printf("Starting of Test Case 2\n");
	printf("\n");
	printf("\n");
	list*B = create_list();
	char* b = "B-List2";
	add_to_list(B, b);
	print_list(B);
	remove_from_list(B);
	print_list(B);
	add_to_list(B, b);
	print_list(B);
	flush_list(B);
	free_list(B);
	printf("\n");
	printf("\n");

	//Test case with list containing 4 strings	
	printf("Starting of Test Case 3\n");
	printf("\n");
	printf("\n");
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
	printf("\n");
	printf("\n");

	//Test case with list containing 10 strings
	printf("Starting of Test Case 4\n");
	printf("\n");
	printf("\n");
	list* D = create_list();
	char* q = "book";
	char* w = "pen";
	char* e = "eraser";
	char* r = "laptop";
	char* t = "headphone";
	char* y = "bowl";
	char* u = "table";
	char* i = "chair";
	char* o = "screen";
	char* p = "keyboard";
	printf("adding and printing....\n");
	add_to_list(D, q);
	print_list(D);
	printf("adding and printing....\n");
	add_to_list(D, w);
	print_list(D);
	printf("adding and printing....\n");
	add_to_list(D, e);
	print_list(D);
	printf("adding and printing....\n");
	add_to_list(D, r);
	print_list(D);
	printf("adding and printing....\n");
	add_to_list(D, t);
	print_list(D);
	printf("adding and printing....\n");
	add_to_list(D, y);
	print_list(D);
	printf("adding and printing....\n");
	add_to_list(D, u);
	print_list(D);
	printf("adding and printing....\n");
	add_to_list(D, i);
	print_list(D);
	printf("adding and printing....\n");
	add_to_list(D, o);
	print_list(D);
	printf("adding and printing....\n");
	add_to_list(D, p);
	print_list(D);
	printf("removing and printing....\n");
	remove_from_list(D);
	print_list(D);
	printf("removing 5 items and printing....\n");
	remove_from_list(D);
	remove_from_list(D);
	remove_from_list(D);
	remove_from_list(D);
	remove_from_list(D);
	print_list(D);
	printf("flusing and printing....\n");
	flush_list(D);
	print_list(D);
	printf("freeing ........\n");
	free_list(D);
	printf("\n");
	printf("\n");


	printf("starting test case 5........\n");
	list* five = create_list();
	char* a = NULL;
	add_to_list(five, a);
	print_list(five);


	return 0;
}