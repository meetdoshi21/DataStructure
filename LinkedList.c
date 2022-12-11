/******************************************************************************

Author: Meet Doshi
First Release : 11 December 2022

This is program to create linked list , add data in linked list and display the linked list

*******************************************************************************/



#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

// Define data type using struct
typedef struct Node
{
    int data;
    struct Node* next;
} tNODE;

// Fucntion Declartion 
void createList(tNODE **pphead,int* arrayData);
void printList(tNODE *phead);
void addNode(tNODE **pphead,int index,int value);

//main function
int main()
{
    int list[7] = {1,2,3,4,6,8,10};
    tNODE *head = NULL;
    createList(&head,list);
    printList(head);
    addNode(&head,1,420);
     printList(head);
     addNode(&head,0,69);
     printList(head);

    return 0;
}

// Function : Create linked list 
// Input : reference to head, array of data 

void createList(tNODE **pphead,int* arrayData)
{
    tNODE *prevNode = NULL;
    tNODE *newNode = NULL;
    for( int i = 0 ; i < 7 ; i++)
    {
    // memory allocation for newNode
    newNode = malloc(sizeof(tNODE));
    if(newNode == NULL)
    {
        printf("no memory space in system");
        return;
    }
    // store the data in Node
    newNode->data = arrayData[i];
    // Provide memory for head allocation
    if ( i == 0)
    {
        *pphead = newNode;
        (*pphead)->next = NULL;
        prevNode = *pphead;
        continue;
    }
    else
    {
        prevNode->next = newNode;
        prevNode = prevNode->next;
        newNode->next = NULL;
    }
    }
}
// Fucntion : display the linked list
// Input : reference to head of linked list
void printList(tNODE *phead)
{
    tNODE* currentNode = NULL;
    currentNode = phead;
    while(currentNode != NULL)
    {
    printf(" %d -> ", currentNode->data);
    currentNode = currentNode->next;
    }
    printf("\n Linked list display completed \n");
}


// Fucntion : add data at specific location inlinked list
// Input :  head of linked list , location and value of data
void addNode(tNODE **pphead,int index, int value)
{
 
   tNODE * newNode = NULL;
   tNODE *prevNode = NULL;
   prevNode = *pphead;
   newNode  = malloc(sizeof(tNODE));
   if(newNode != NULL)
   {
       newNode->data = value;
   }
   else
   {
       printf(" No memory space avaiable");
   }
   if (index == 0 )
   {
       newNode->next  = (*pphead);
      *pphead = newNode;
      
   }
   else{
   for(int i = 1 ; i < index ; i++)
   {
       prevNode = prevNode->next;
   }
    newNode->next = prevNode->next;
    prevNode->next = newNode;
   }  
}




