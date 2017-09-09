#### README ####

Devendra Shah
devendra.shah@bison.howard.edu

### How to Build and Run this Program ###
1. Run the Makefile using 'make' command in the terminal. 
2. This creates a binary executable called list_test4.
3. Run the executable using './list_test4' command in terminal.
4. In order to test new scenarios, make changes to the 'list_test.c' file and repeat steps 1 to 3. 
5. You can run the command 'make clean' in terminal if you want to delete the executable.

Note: When you run the program, in some test cases, there are some case where we are printing or freeing lists after the list has been flushed or they are empty. In these cases, there will be an errror printed on the screen. This is expected behavior. 

### A brief description of the pieces of this assignment ###
1. List.c -  Contains definitions of the functions and comments for this project
2. List.h - Contains struct definitions, typedefs and function prototypes for this project
3. List_test.c - Contains test cases for this project
4. Makefile - Contains commandline commands for the makefile

### Challenges that I overcame ###
1. I had to refresh my memory of the C syntax and go through the book to make sure that I have a clear understanding of the libraries, pointers and C programming language
2. Deciding to use a singly linked list or doubly linked list. Initially I started with a doubly linked list but later switched to singly linked list in order to avoid further complexity in the program
3. I had a hard time figuring out how to solve the problem of segmentation fault in the functions remove_from_list() and flush_list(). I figured out a solution after many attempts to implement these functions by using two pointers. 

### Notes on resources and/or discussions ###
1. I used to the book provided on Piazza to review C concepts and syntax. The link to the book is "http://cslibrary.stanford.edu/101/".

