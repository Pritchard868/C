#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

struct queue{
	int data;
	struct queue *next;
};
struct queue *rear = NULL;
struct queue *front = NULL;

void insert(int val);
int delete_data();
int peek();
void display();

int main(){
	int choice, val;
	do{
		printf("\n\n\t\t=-=-=-=-=-LINKED LIST IMPLEMENTATION OF A QUEUE-=-=-=-=-=-=\n");
		printf("\n\t\t\t\t__________Menu__________\n");
		printf("\n0. Exit");
		printf("\n1. Add to queue");
		printf("\n2. Peek");
		printf("\n3. Display");
		printf("\n4. Delete");
		printf("\n\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 0:	printf("\nGood bye!");
				break;
			case 1:	printf("\nEnter number to add: ");
				scanf("%d", &val);
				insert(val);
				break;
			case 2:	val = peek();
				if(val != -1)
					printf("\nRear = %d", val);
				break;
			case 3:	display();
				break;
			case 4:	val = delete_data();
				if(val != -1)
					printf("\n%d was deleted", val);
				break;
			default: printf("\nInvalid choice, try again");
		}
		printf("\n\n");
	}while(choice != 0);
	return 0;
}
void insert(int val){
	struct queue *newnode;
	if((newnode = (struct queue *)malloc(sizeof(struct queue))) == NULL){
		fprintf(stderr,"Memory allocation error: %s", strerror(errno));
		exit(1);
	}
	newnode->data = val;
	newnode->next = NULL;
	if(front == NULL){
		rear = front = newnode;
		front->next = rear->next = NULL;
	}else{
		rear->next = newnode;
		rear = newnode;
		rear->next = NULL;
	}
}

int peek(){
	int val;
	if(front == NULL || front > rear){
		printf("\nQueue is empty");
		return -1;
	}else{
		val = front->data;
		return val;
	}
}

void display(){
	struct queue *temp;
	if(front == NULL || front > rear){
		printf("\nQueue is empty");
	}
	else{
		temp = front;
		printf("\n");
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}

int delete_data(){
	struct queue *temp;
	int val;
	if(front == NULL){
		printf("\nQueue underflow");
		return -1;
	}else{
		val = front->data;
		temp = front;
		front = front->next;
		free(temp);
		return val;
	}
}
