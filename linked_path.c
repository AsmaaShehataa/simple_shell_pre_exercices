#include "env.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct node *linked_path(void)
{
	char **patharr;
	int counter;
	char *tmp __attribute__((unused));
	struct node *head, *tail;
	
	head = NULL;
	tail = NULL;
	//this memory allocation is not necessary because the function get_path_arr()
	// allocates memory to the generated array, using this in here can cause memoey
	// allocation errors, because we override the memory given by the function get_path_arr()
	//patharr = malloc(sizeof(patharr));

	patharr = get_path_arr();
	if (!patharr) //checking for errors while returning the path array.
	{
		return (NULL);
	}
	counter = 0; //initializing counter.
	while (patharr[counter] != NULL)
	{
		//allocating memory to the new struct node.
		struct node *new_node = (struct node*) malloc(sizeof(struct node));
		
		if (!new_node)
		{
			//handle memory allocation failure
			fprintf(stderr, "Failure in allocating memory.\n");
			return (NULL);
		}
		//adding the paths to the dir element of the node
		new_node->dir = patharr[counter];
		new_node->next = NULL;

		//adding the node to the list
		if (head == NULL)
		{
			head = new_node; //this is like saying head->dir == new_node->dir
			tail = new_node;
			
		}
		else
		{
			tail->next = new_node;
			tail = new_node;
		}
		counter++;
	}
	free(patharr); //this frees the path array
	return (head); //this return the head.
}
