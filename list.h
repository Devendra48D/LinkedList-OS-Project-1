#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct node node;
//struct definition for a node
//contains a string and a pointer to the next node
struct node
{
	char *string;
	node* next;
};

typedef struct list list;
//struct definition for a linked list
//containds pointers to the starting and ending nodes
struct list
{
	node* start;
	node* end;
};

/* Allocates and initializes a new list */
list* create_list( );

/* Adds item to start of the list. Allocates a
 * new buffer and copies the string from item (use malloc,
 * strlen, and strncpy; or try strdup).
 * Returns 0 if successful, non-zero otherwise. */
int add_to_list(list* ll, char* item);

/* Removes the string from the end of the list and
 * returns a pointer to it. The caller is expected to free
 * the string returned when finished with it. */
char* remove_from_list(list* ll);

/* Prints every string in the list, with a new line
 * character at the end of each string */
void print_list(list* ll);

/* Flushes (clears) the entire list and re-initializes the
 * list. The passed pointer ll should still point to a
 * valid, empty list when this function returns. Any memory
 * allocated to store items in the list should be freed. */
void flush_list(list* ll);

/* De-allocates all data for the list. Ensure all memory
 * allocated for this list is freed, including any
 * allocated strings and the list itself. */
void free_list(list* ll);
