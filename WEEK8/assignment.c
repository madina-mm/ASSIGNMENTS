#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
	char data[256];
	struct Node * next;
};

void printlist(struct Node* node){
	printf("Queue: \n");
	while(node !=NULL){
		printf("%s ",node->data);
		node = node -> next;
		if (node !=NULL)
			printf(", ");//to put comma after an element if it's not the last one
	}
	printf("\n");
}

void luckyOne(struct Node** head, char *name){
	struct Node *temp = (*head), *pre;

	if(temp !=NULL && strcmp(temp->data, name) ==0){
		*head = temp->next;
	}

	else {
		while (temp != NULL && strcmp(temp->data, name) !=0) {
			pre = temp;
			temp = temp->next;
		}

		if(temp == NULL){
			printf("The customer is not found \n");
			return;
		}
		pre->next = temp->next;
	}

	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
	struct Node *last = *head ;
	strcpy(newNode->data, temp->data);
	newNode->next = NULL;

	while (last->next !=NULL){
		last = last->next;}
	last->next=newNode;
	free(temp);
	temp = NULL;}

void admit(struct Node **head){
	if(*head == NULL)
	{printf("There is no person in the queue \n");
		return;}
	struct Node* nextNode = (*head)->next;
	printf("%s is admitted\n",(*head)->data);
	free(*head);
	*head=nextNode;
}

void append(struct Node **head, char *name)
{struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
 struct Node *last = *head;
 strcpy(newNode->data, name);
 newNode->next = NULL;

 while(last->next !=NULL)
 {last = last->next;}
 last->next = newNode;}


void delete_list(struct Node** head){
	struct Node* now = *head, *next;
	while (now != NULL)
	{next = now->next;
	 free(now);
	 now=next;}
	*head = NULL;}

int main(){
	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
	strcpy(head->data, "Mary");
	head->next = NULL;
	append(&head, "Victoria");
	append(&head, "Taylor");
	append(&head, "Elizabeth");
	append(&head, "Mark");
	printlist(head);
	char input[256];
	bool quit = 0;


	while(!quit){
		printf("\nEnter a command(press q to quit): ");
		scanf("%s",input);
		if(strcmp(input, "q")==0) 
			quit =1;

		else if(strcmp(input,"admit")==0){
			admit(&head);
		}

		else 
			luckyOne(&head,input);
		printlist(head);
	}

	delete_list(&head);
	return 0;
}
