/*
Yikai Wang
Period 4 Systems
*/

#include <stdio.h>
#include <stdlib.h>

struct node { int i; struct node *next; };

void print_list( struct node *n ) {
	struct node *front = n;
	while( front ) {
		printf( "%d -> ", front->i );
		front = front->next;
	}

	printf( "END\n" );
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

	print_list(n);
}