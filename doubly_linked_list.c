#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    struct node *next;
    struct node *prev;
}NODE;

void printList(NODE *head);
void siraliEkle(NODE **head,int data);
void elemanSil(NODE **head,int data);
NODE* getNode(int data);


int main(){
    NODE *head = NULL;
     
    siraliEkle(&head,400);
    printList(head);
    siraliEkle(&head,40);
    printList(head);
    siraliEkle(&head,4);
    printList(head);
    siraliEkle(&head,450);
    printList(head);
    siraliEkle(&head,50);
    printList(head);

    elemanSil(&head,50);
    printList(head);
    elemanSil(&head,999);
    printList(head);
    elemanSil(&head,4);
    printList(head);
    elemanSil(&head,450);
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
    node->prev = NULL;
    return node;
}

void siraliEkle(NODE **head, int data){  
    NODE *newNode = getNode(data);
    NODE *tmp;
    
    if((*head) == NULL){ 
        (*head) = newNode;
        (*head)->prev = NULL;
    }
    else if((*head)->x > data){  
        newNode->prev = NULL;
        newNode->next = (*head);
        (*head)->prev = newNode;
        (*head) = newNode;
    }
    else{
        tmp = (*head);
        while(tmp->next != NULL && tmp->next->x < data){
            tmp = tmp->next;
        }
        newNode->next = tmp->next;
        tmp->next = newNode;
        newNode->prev = tmp;
        if(newNode->next != NULL){
            newNode->next->prev = newNode;  
        }
    }
}

void elemanSil(NODE **head,int data){
    NODE *tmp;
    NODE *c;

    if((*head)==NULL){
        printf("Linked List bos, silinecek eleman yok");
    }
    else if((*head)->x == data){ 
        tmp = (*head);
        (*head) = (*head)->next;
        printf("%d silindi..\n",data);
        free(tmp);  
        (*head)->prev = NULL;  
    }
    else{
        tmp = (*head);
        while(tmp->next != NULL && tmp->next->x != data){
            tmp = tmp->next;
        }
        if(tmp->next != NULL){  
            c = tmp->next;
            tmp->next = tmp->next->next; 
            if(tmp->next != NULL){  
                tmp->next->prev = tmp;
            }
            printf("%d silindi..\n",data);
            free(c);
        }
        else{
            printf("Silinecek eleman bulunamadi..\n");
        }
    }
}
