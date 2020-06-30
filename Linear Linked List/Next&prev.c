#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

typedef struct node{
    struct node * prev;
    int data;
    struct node * next;
}node;

void add(int v, node**p)
{
     node * newNode;
    newNode = (node*)malloc(sizeof(node));
    newNode -> prev = NULL;
    newNode -> data =  v;
    newNode -> next = NULL;
    if(*p == NULL){
        *p = newNode;
    }else{
        node *temp;
        temp = *p;
        while(temp -> next != NULL){
            temp = temp ->next;
        }
        temp -> next = newNode;
        newNode->prev = temp;
    }
}

void displayForward(node*p)
{
    while(p!=NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void displayBackward(node*p)
{
    while(p->next != NULL)
    {
        p = p->next;
    }
    while(p != NULL)
    {
        printf("%d\n", p->data);
        p = p->prev;
    }
}

void insertAfterVal(node*first, int d, int v)
{
    while(first != NULL)
    {
        if(first->data == v)
        {
            node *newnode = (node*) malloc(sizeof(node));
            newnode->prev = first;
            newnode->data = d;
            newnode->next = first->next;
            first->next = newnode;
            if(newnode->next != NULL){
                first = newnode->next;
                first->prev = newnode;
            }
            break;
        }
        first = first->next;
    }
}

void del(node**p, int v)
{
    if((*p) != NULL){
        if((*p)->data == v)
        {
           *p = (*p)->next;
           free((*p)->prev);
        }else{
            node*temp = (*p)->next;
            while(temp != NULL)
            {
                if(temp->data == v)
                {
                    node*linker = temp->prev;
                    linker->next = temp->next;
                    if(temp->next != NULL){
                        linker = linker->next;
                        linker->prev = temp->prev;
                    }
                    free(temp);
                    break;
                }
                temp = temp->next;
            }
        }
    }
}

void insertAt(node**p, int v, int pos)
{
    node*newnode = (node*) malloc(sizeof(node));
    newnode->data = v;
    if(pos == 1){
        newnode->prev = NULL;
        newnode->next = (*p);
        (*p) = newnode;
    }else{
        node*temp = (*p);
        int count = 1;
        while(temp->next != NULL)
        {
            count++;
            if(count == pos){
            newnode->prev = temp;
            newnode->next = temp->next;
            temp->next = newnode;
            temp= newnode->next;
            temp->prev = newnode;
            break;
            }
            temp = temp->next;
        }
        //adding node at the end
        if(temp->next == NULL){
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = NULL;
        }
    }
}

void main()
{
    node * first = NULL;
    node * second = NULL;

    displayForward(first);
    printf("\n\n");



    del(&first, 25);
    displayForward(first);
}
