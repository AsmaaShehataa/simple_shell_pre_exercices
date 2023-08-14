#include "env.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	int counter;
	struct node *head, *temp;

	// this is not necessery because we assigned memory already in the linked_path().
	//head = malloc(sizeof(struct node));

	head = linked_path();
	while (head!= NULL) //checking if the head is null or not.
	{
		printf("%s\n", head->dir);
		head = head->next;
	}
	//free(head); //this is not okay because it only frees the last element of the list.

	//free the linked list and dir strings
	while (temp != NULL) //using temp to free mem in here.
	{
		head = temp;
		free(head->dir); //free the dir string
		temp = temp->next; //switching to the next node in the list (because tmp is a node in the list).
		free(head); //free the node
	}
	exit(EXIT_SUCCESS);
}
