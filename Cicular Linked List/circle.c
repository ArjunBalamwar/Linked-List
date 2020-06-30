#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

typedef struct node{
    int data;
    struct node * next;
}node;

void add(node**p, int v)
{
    node* newnode = (node*) malloc(sizeof(node));
    newnode->data = v;
    if((*p) == NULL){
        (*p) = newnode;
        newnode->next = (*p);
    }else{
        newnode->next = (*p)->next;
        (*p)->next = newnode;
        (*p) = newnode;
    }
}

void display(node*p)
{
    if(p != NULL){
        node* temp = p->next;
        while(temp!= p)
        {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }else{
        return;
    }
}

void del(node**p, int v)
{
    if((*p) != NULL)
    {
        node*prev = (*p);
        node* temp = (*p)->next;
        if((*p)->next == (*p) && prev == temp)
        {
            free(temp);
            (*p) = NULL;
        }else{
            do{
                if(temp->data == v){
                    prev->next = temp->next;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }while(temp != (*p)->next);

            if(temp != (*p)->next){
                if(temp == (*p)){
                    (*p) = prev;
                }
                    free(temp);
            }
        }
    }
}

void insertAfterVal(node** p, int v, int t)
{
    if((*p) != NULL)
    {
        if((*p)->data == t)
        {
            node*newnode = (node*) malloc(sizeof(node));
            newnode->data = v;
            newnode->next = (*p)->next;
            (*p)->next = newnode;
            (*p) = newnode;
        }else{
            node*temp = (*p)->next;
            do{
                if(temp->data == t){
                    node*newnode = (node*) malloc(sizeof(node));
                    newnode->data = v;
                    newnode->next = temp->next;
                    temp->next = newnode;
                }
                temp = temp->next;
            }while(temp != (*p)->next);
        }
    }
}

void insertAt(node**p, int pos, int v)
{
    node*newnode = (node*) malloc(sizeof(node));
    newnode->data = v;
    if((*p) == NULL)
    {
        (*p) = newnode;
        newnode->next = (*p);
    }else{
        node*temp = (*p);
        int index = 1;
        do{
            if(index == pos){
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            }
            index++;
            temp = temp->next;
        }while(temp != (*p));

        if(temp == (*p) && index != 1){
            newnode->next = temp->next;
            temp->next = newnode;
            (*p) = newnode;
        }
    }
}

void main()
{
    node * first = NULL;

    add(&first, 10);
    add(&first, 20);
    add(&first, 30);
    add(&first, 40);
    add(&first, 50);

    display(first);
    printf("\n\n");


}

