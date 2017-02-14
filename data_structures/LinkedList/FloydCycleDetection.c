/*PROGRAM TO FIND CYCLES IN LINKED LISTS*/

# include "LinkedList.h"
# include <stdio.h>
# include <stdlib.h>

int detect_cycle(struct node ** head_ref) {

		struct node *turtle = (*head_ref);
		struct node *hare   = (*head_ref);

		int cycle = 0;
		while( hare && turtle && (hare->next)) {

				hare = hare->next->next;
				turtle = turtle->next;

				if(hare == turtle)
						return 1;
		}

		return 0;
}

int main() {

		int iffound = 0;
		struct node *first = (struct node *) malloc(sizeof(struct node));
		first->next = (struct node *)malloc(sizeof(struct node));
		first->next->next  =(struct node *) malloc(sizeof(struct node));
		//first->next->next->next = first->next;
		first->next->next-next = NULL;
		iffound = detect_cycle(&first);

		if(iffound)
				printf("Found");
		else
				printf("NOT FOUND");
		return 0;
}