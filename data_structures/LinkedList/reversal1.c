/*REVERSING A LINKED LIST USING 2 VARIABLES ONLY*/

# include "LinkedList.h"

# define ut uintptr_t

void reverse(struct node ** HEAD) {

		struct node *prev = NULL;
		if(!HEAD)
				return;

		struct node *current = *HEAD;

		/*A ^ B ^ C ^ B ^ A = C
		uintptr_t converts the pointer to unsigned int. returns the value stored inside the pointer.
		this is a general method of swapping pointers.
		*/

		while(current)
				current = (struct node *)((ut)prev ^ (ut)current ^ (ut)current->next ^ (ut) (current->next = prev) ^ (ut) (prev = current));

		*HEAD = prev;	
}

int main() {

		//struct node *temp = NULL;//(struct node *) malloc(sizeof(struct node));
		struct node *HEAD = NULL;

		insert(&HEAD,3); 
		printf("in main %lu\n",(ut)HEAD);
		insert(&HEAD,4); 
		insert(&HEAD,5);

		traverse_link(&HEAD);
		printf("\n\n");
		reverse(&HEAD);
		printf("\n\n");
		traverse_link(&HEAD);
		return 0;
}