#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}NODE;

void addFront(NODE **head, int data);
void addLast(NODE **head, int data);
void addMiddle(NODE **head, int data);
void deleteNode(NODE **head, int data);
void deleteFront(NODE **head);
void deleteBack(NODE **head);
void traverseForward(NODE *head);
NODE* getNode(int data);
NODE* searchNode(NODE *head, int data);


int main(){
    NODE *head = NULL;
    NODE *tmp;
    addLast(&head,0);
    traverseForward(head);
    addFront(&head,10);
    traverseForward(head);
    addLast(&head,15);
    traverseForward(head);
    addFront(&head,20);
    traverseForward(head);
    addFront(&head,30);
    traverseForward(head);
    addFront(&head,40);
    traverseForward(head);
    addLast(&head,55);
	traverseForward(head);
    return 0;
}


void traverseForward(NODE *head){
    NODE *tmp = head;
    while(tmp!=NULL){
        printf("%d ",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}

NODE* getNode(int data){
    NODE *newNode = (NODE*)malloc(1*sizeof(NODE));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

NODE* searchNode(NODE *head, int data){
    NODE *tmp = head;
    while(tmp!=NULL && tmp->data!=data){
        tmp = tmp->next;
    }
    return tmp;
}

void addLast(NODE **head,int data){
    NODE *tmp;
    NODE *newNode = getNode(data);

    if(*head==NULL){
        *head = newNode;
    }
    else{
        tmp = *head;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void addFront(NODE **head,int data){
    NODE *newNode = getNode(data);
    newNode->next = *head;
    *head = newNode;
}

void addMiddle(NODE **head,int data){
    NODE *tmp;
    NODE *newNode = getNode(data);

    if(*head==NULL){
        *head = newNode;
    }
    else{
        tmp = *head;
        while(tmp->next!=NULL && tmp->next->data < data){
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

void deleteNode(NODE **head, int data){
    NODE *tmp,*current;
    if((*head)->data == data){
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
        printf("%d silindi",data);
    }
    else{
        current = *head;
        while(current->next!=NULL && current->next->data!=data){
            current = current->next;
        }
        if(current->next!=NULL){
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
            printf("%d silindi",data);
        }
        else{
            printf("Aranan eleman yok");
        }
    }
}

void deleteFront(NODE **head){  //popFront
    NODE *tmp;
    if((*head) == NULL){ 
        tmp = *head;
        *head = (*head)->next;
        tmp = NULL;
    }
}

void deleteBack(NODE **head){   //popBack
    NODE *tmp,*lastNode;
    if(*head != NULL){
        if((*head)->next == NULL){
            *head = NULL;
        }
        else{
            tmp = *head;
            while(tmp->next->next != NULL){
                tmp = tmp->next;
            }
            lastNode = tmp->next;
            tmp->next = NULL;
            free(lastNode);
        }
    }
}
