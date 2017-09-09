#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"


/* Allocates and initializes a new list 
Creates a new list by allocating memory for a new LinkedList
Instatiates a new linked list
Sets both starting and ending nodes to NULL
Returns pointer to the linked list
*/
list* create_list() {
	list* l = (list*) malloc(sizeof(list));
	l->start = NULL;
	l->end = NULL;
	return l;
}

/* Adds item to start of the list. Allocates a
 * new buffer and copies the string from item (use malloc,
 * strlen, and strncpy; or try strdup).
Creates a new node containg a string that has the the same string as item
If the list is empty, the starting node and ending node is set 
to the node containing new string

If the list is not empty, sets the starting node to the node that has the string value of item
and this node points next to the the previous starting node of the list

 * Returns 0 if addition to the list is successful, non-zero otherwise. */
int add_to_list(list* ll, char* item){
	if (item == NULL){
		printf("The string you are trying to add is invalid. Try again.\n");
		return -1;
	}
	node* toadd = (node*) malloc(sizeof(node));
	toadd->string = strdup(item);
	toadd->next = NULL;

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
 * the string returned when finished with it. 

If the list has only one node, removes the current node from the list,
frees the memory used by this node  and 
returns a pointer to the removed string.

If there are more than nodes in the list, the second last node is set 
to be the ending node of the list; the last node is deleted; the 
memory used by this former last node is freed; 
and returns a pointer to the removed string.

Prints an errors and Returns a null pointer 
if the given list is empty or invalide
 */
char* remove_from_list(list* ll){
	if ((ll->start != NULL) && (ll->end != NULL) && (ll->start == ll->end)){
		node* curr = ll->start;
		char* removed = curr->string;
		ll->start = NULL;
		ll->end = NULL;
		free(curr->string);
		free(curr->next);
		free(curr);
		return removed;
	}
	else if ((ll->start != NULL) && (ll->end != NULL) && (ll->start != ll->end)){
		node* toremove = ll->end;
		char* removed = toremove->string;
		node* head = ll->start;
		while (head->next->next != NULL){
			head = head->next;
		}
		head->next = NULL;
		ll->end = head;
		ll->end->string = head->string;
		ll->end->next = NULL;
		free(toremove->string);
		free(toremove->next);
		free(toremove);
		return removed;
	}
	else{
		printf("The list you are trying to remove from is empty/invalid.Try again! \n");
		return NULL;
	}
}


/* Prints every string in the list, with a new line
 * character at the end of each string 

A node pointer iterates through the linked list from the starting node
and prints string contained in each node on a new line until the second last node.
After the pointer reaches the second last node, we use the ending node
of the list to print the string contained in the ending node

Prints an error if the given list is empty or invalid.
 */
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
		printf("The list you are trying to print is either empty/invalid or an error has occured.\n");
	}
}

/* Flushes (clears) the entire list and re-initializes the
 * list. The passed pointer ll should still point to a
 * valid, empty list when this function returns. Any memory
 * allocated to store items in the list should be freed. 

 We start with two node pointers that both point to the start of the list first. 
 Then we iterate throughout the linked list to clear the memory used by all the nodes 
 and theisr strings.
 After the memory used by the list has been freed, We initialize a new list and 
 set the pointer ll to this new initialized list.

Prints an error if the given list is empty or invalid.
 */
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
		free(head->next);
		free(head);
		ll->start = NULL;
		ll->end = NULL;
		ll = create_list();
	}
	else{
		printf("The list is either empty/invalid or an error has occured.\n");
	}
}

/* De-allocates all data for the list. Ensure all memory
 * allocated for this list is freed, including any
 * allocated strings and the list itself. 

Uses the flush_list() function to clear the entire list and free the memory used by the list
Frees the pointer pointing to the given list
 */
void free_list(list *ll){
	flush_list(ll);
	free(ll);
}
