# include <stdlib.h>
# include <stdio.h>
# include <assert.h>


struct node {

		int data;
		struct node * next;
};


struct node * insert(struct node ** HEAD, int data) {
		
		struct node * newnode = (struct node *) malloc(sizeof(struct node));
		if(!newnode){

				return NULL;
		}
		
		newnode->data = data;
		newnode->next = NULL;

		if(HEAD != NULL) {

				struct node *traverse = (*HEAD);
				while(traverse->next)
						traverse = traverse->next;

				traverse->next = newnode;
				return newnode;

		}

		else {
				
				HEAD = &newnode;
				return newnode;
		}
				
}

int get_data(struct node ** HEAD, int index) {

		int counter = 0;
		struct node * traverse = (*HEAD);
		while(traverse) {

				if(counter == index)
						return traverse->data;

				traverse = traverse->next;
				counter++;
		}

		return -1;
}

void traverse_link(struct node ** HEAD) {

		struct node * traverse = (*HEAD);
		while(traverse) {
				printf("%d -> ",traverse->data);
				traverse = traverse->next;
		}
				
		return;
}

int main() {

		struct node * firstnode = (struct node *) malloc(sizeof(struct node));
		struct node ** HEAD = &firstnode;

		firstnode->data = 2;
		firstnode->next = NULL;
		printf("HELLO");
		insert(HEAD,5);
		insert(HEAD,6);
		insert(HEAD,7);

		traverse_link(HEAD);
		printf("\n%d",get_data(HEAD,1));

		return 0;
}