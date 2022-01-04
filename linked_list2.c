#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    struct node *next;
}NODE;

void printList(NODE *head);
void siraliEkle(NODE **head,int data);
NODE* getNode(int data);


int main(){
    NODE *head = NULL;

    siraliEkle(&head,10);
    printList(head);
    siraliEkle(&head,5);
    printList(head);
    siraliEkle(&head,15);
    printList(head);
    siraliEkle(&head,12);
    printList(head);
    siraliEkle(&head,35);
    printList(head);

    return 0;
}


void printList(NODE *head){ 
    NODE *tmp = head;
    while(tmp != NULL){
        printf("%d ",tmp->x);
        tmp = tmp->next;
    }
    printf("\n");
}

NODE* getNode(int data){
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node->x = data;
    node->next = NULL;
    return node;
}

void siraliEkle(NODE **head, int data){  //head'in degisme ihtimali de var(**) (linked list boşsa)
    NODE *newNode = getNode(data);
    NODE *tmp;
    
    if((*head) == NULL){ //linkli liste boşsa, head degisir
        (*head) = newNode;
    }
    else if((*head)->x > data){  //eklenecek node, ilk elemandan(head)'den kücükse
        newNode->next = (*head);
        (*head) = newNode;
    }
    else{
        tmp = (*head);
        while(tmp->next != NULL && tmp->next->x < data){
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode; 
    }
}
