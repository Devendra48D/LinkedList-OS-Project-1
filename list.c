#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


/* Allocates and initializes a new list 
Creates a new list by allocating memory for a new LinkedList*/
list* create_list() {
	list* l = (list*) malloc(sizeof(list));
	l->start = NULL;
	l->end = NULL;
	return l;
}

/* Adds item to start of the list. Allocates a
 * new buffer and copies the string from item (use malloc,
 * strlen, and strncpy; or try strdup).
 * Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item){
	node* toadd = (node*) malloc(sizeof(node));
	toadd->string = strdup(item);
	toadd->next = NULL;
	//toadd->prev = NULL;

	if (ll->start == NULL){
		ll->start = toadd;
		ll->end = toadd;
	}
	else {
		toadd->next = ll->start;
		ll->start = toadd;
	}
	if (strncmp(ll->start->string, item, strlen(item)) == 0){
		return 0;
	}
	else{
		return strncmp(ll->start->string, item, strlen(item));
	}
}

/* Removes the string from the end of the list and
 * returns a pointer to it. The caller is expected to free
 * the string returned when finished with it. */
char* remove_from_list(list* ll){
	if ((ll->start != NULL) && (ll->end != NULL) && (ll->start == ll->end)){
		node* curr = ll->start;
		node* removed = curr->string;
		ll->start = NULL;
		ll->end = NULL;
		free(curr->string);
		free(curr);
		return removed;
	}
	else if ((ll->start != NULL) && (ll->end != NULL) && (ll->start != ll->end)){
		node* curr = ll->end;
		node* removed = curr->string;
		free(curr->string);
		free(curr);
		node* head = ll;
		while (head->next->next != NULL){
			head = head->next;
		}
		head->next = NULL;
		ll->end = head;
		ll->end->string = head->string;
		ll->end->next = NULL;
		return removed;
	}
	else{
		printf("The list is invalid.Try again! \n");
	}
}


/* Prints every string in the list, with a new line
 * character at the end of each string */
void print_list(list *ll){
	node* curr = ll->start;
	if (ll->start != NULL){
		//traverse till the second last string in the list
		while (curr->next != NULL){
			printf("%s\n", curr->string);
			curr = curr -> next;
		}
		//print the last string in the list
		printf("%s\n", ll->end->string);
	}
	else{
		printf("The list is either empty/invalid or an error has occured.\n");
	}
}

/* Flushes (clears) the entire list and re-initializes the
 * list. The passed pointer ll should still point to a
 * valid, empty list when this function returns. Any memory
 * allocated to store items in the list should be freed. */
void flush_list(list* ll){
	node* curr = ll->start;
	node* head = ll->start;
	if (ll->start != NULL){
		while (head->next != NULL){
			curr = head;
			head = head->next;
			free(curr->string);
			free(curr);
		}
		free(head->string);
		free(head);
		ll->start = NULL;
		ll->end = NULL;
	}
	else{
		printf("The list is either empty/invalid or an error has occured.\n");
	}
}

/* De-allocates all data for the list. Ensure all memory
 * allocated for this list is freed, including any
 * allocated strings and the list itself. */
void free_list(list *ll){
	flush_list(ll);
	free(ll);
}
