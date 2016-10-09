/*
Yikai Wang
Period 4 Systems
*/

#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; }; //protoype struct

void print_list( struct node *n ) {
	struct node *front = n;
	while( front ) { //while not a NULL value
		printf( "%d -> ", front->i );
		front = front->next;
	}

	printf( "END\n" );
}

struct node* insert_front( struct node *prev, int data ) {
	struct node *start = (struct node *)malloc(sizeof(struct node)); //new node
	start->i = data; //insert data
	start->next = prev;
	return start;
}

struct node* free_list( struct node* start ) {
	struct node* iterate = start;
	while( iterate ) { //if not a null
		free( iterate );
		iterate = iterate->next;
	}

	return start;
}

void main() {
	/*
	int i = 0;
	int *p = &i;
	*p = 1;
	printf( "i: %d\n", i );
	printf( "p: %d\n", *p );
	*/

	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->i = 15;
	struct node *o = (struct node *)malloc(sizeof(struct node));
	o->i = 20;
	n->next = o;

	//struct node *front = n;
	//printf( "%d\n", (front->next == NULL));

	printf( "Testing: print_list:\n" );
	print_list(n);

	printf( "\nAdding nodes to the front:\n");
	
	printf("Adding: 10\n");
	n = insert_front( n, 10 );

	printf("Adding: 5\n");
	n = insert_front( n, 5 );

	printf("Adding: 0\n");
	n = insert_front( n, 0 );

	printf( "Testing: print_list (again):\n" );
	print_list(n);

	printf("\nFreeing the list...\n");
	n = free_list(n);

	printf("Is the beginning of the list null? %d\n", (n == NULL) );

	printf("Testing: print_list (yet again):\n");
	print_list(n);
}