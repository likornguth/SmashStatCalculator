#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

struct Node *addFront(struct List *list, void *data){

        struct Node *front = malloc(sizeof(struct Node)); // sizeof(Node) = 8+8 = 16
        if(!front){
                return NULL; // allocation successful
        }
        front -> data = data;
        front -> next = list -> head; //front precedes head
        list -> head = front; // front becomes new head

        return front;
}

void traverseList(struct List *list, void (*f)(void *)){
       
        struct Node *currentNode = list -> head;
        while(currentNode){
                f(currentNode -> data);
                currentNode = currentNode -> next;
        }      
}

struct Node *findNode(struct List *list, const void *dataSought, int (*compar)(const void *, const void *)){
        struct Node *currentNode = list -> head;
       
        while(currentNode){
                void *currentData = currentNode -> data;
                if(compar(currentData,dataSought) == 0){
                                return currentNode;
                        }
                else{
                        currentNode = currentNode -> next;
                }
        } 
        return currentNode; // failure      
}
