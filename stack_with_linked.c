#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node *next;
}NODE;

NODE* getNode(int data);
void addFront(NODE **head, int data);
void push(NODE **head, int data);
void pop(NODE **head);
void traverseForward(NODE *head);

int main(){
    NODE *head=NULL;
    traverseForward(head);
    push(&head,10);
    traverseForward(head);
    push(&head,20);
    traverseForward(head);
    push(&head,30);
    traverseForward(head);
    push(&head,40);
    traverseForward(head);
    pop(&head);
    traverseForward(head);
    pop(&head);
    traverseForward(head);
    return 0;
}

NODE* getNode(int data){
	NODE *newNode=(NODE*) malloc(1*sizeof(NODE));
	newNode->data=data;
	newNode->next=NULL;	
	return newNode;
}

void addFront(NODE **head, int data){
	NODE *newNode=getNode(data);
	newNode->next=*head;
	*head=newNode;
}

void push(NODE **head, int data){
	addFront(head,data);
}

void pop(NODE **head){
	NODE *tmp;
	if(*head==NULL){
		printf("Stack is empty\n");
	}else{
		printf("popped element: %d\n",(*head)->data);
		tmp  = *head;
		*head = (*head)->next;
		free(tmp);
	}
	
}

void traverseForward(NODE *head){
	NODE *tmp=head;
	while(tmp!=NULL){
		printf("%d ",tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}
