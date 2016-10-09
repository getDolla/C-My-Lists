/*
Yikai Wang
Period 4 Systems
*/

#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list( struct node *n ) {
	struct node *front = n;
	while( front ) { //while not a NULL value
		printf( "%d -> ", front->i );
		front = front->next;
	}

	printf( "END\n" );
}

struct node* insert_front( struct node *prev, int data ) {
	struct node *start = (struct node *)malloc(sizeof(struct node));
	start->i = data;
	start->next = prev;
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
	n->i = 10;
	struct node *o = (struct node *)malloc(sizeof(struct node));
	o->i = 15;
	n->next = o;

	//struct node *front = n;
	//printf( "%d\n", (front->next == NULL));

	printf( "Testing: print_list:\n" );
	print_list(n);

	printf( "Adding nodes to the front:\n");
	
	printf("Adding: 5\n");
	n = insert_front( n, 5 );

	printf("Adding: 0\n");
	n = insert_front( n, 0 );

	printf( "Testing: print_list (again):\n" );
	print_list(n);
}