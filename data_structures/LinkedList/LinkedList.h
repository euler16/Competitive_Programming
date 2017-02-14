# ifndef __LL__
# define __LL__
# include <stdlib.h>
# include <stdio.h>
# include <assert.h>
# include <stdint.h>

# define ut uintptr_t


struct node {

		int data;
		struct node * next;
};



struct node * insert(struct node **head_ref, int data) {
		
		struct node * newnode = (struct node *) malloc(sizeof(struct node));
		if(!newnode)
				return NULL;
		
		newnode->data = data;
		newnode->next = NULL;

		//INSERTION AT TOP
		/*newnode->data = data;
		newnode->next = (*head_ref);
		(*head_ref) = newnode;*/

		if((*head_ref) == NULL) {
				(*head_ref) = newnode;
		}

		else if(head_ref) {
				struct node *current = (*head_ref);
				while(current->next != NULL)
						current = current->next;

				current->next = newnode;
		}

		
		return newnode;	
}

int get_data(struct node ** head_ref, int index) {

		int counter = 0;
		struct node * traverse = (*head_ref);
		while(traverse) {

				if(counter == index)
						return traverse->data;

				traverse = traverse->next;
				counter++;
		}

		return -1;
}

void traverse_link(struct node ** head_ref) {

		printf("INSIDE traverse_link %lu\n",(ut)head_ref);

		if(!head_ref)
				return;
		struct node * traverse = (*head_ref);
		while(traverse) {
				printf("%d -> ",traverse->data);
				traverse = traverse->next;
		}
				
		return;
}

# endif