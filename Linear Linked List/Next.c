#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>

typedef struct node{
    int data;
    struct node * next;
}node;

void add(int v, node **p)
{
    node * newNode;
    newNode = (node*)malloc(sizeof(node));
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
    }
}
void display(node * p)
{
    while(p != NULL){
        printf("%d\n", p -> data);
        p = p -> next;
    }
}

int number(node *p)
{
    int count = 0;
    while(p != NULL){
        count ++;
        p = p -> next;
    }
    return count;
}

int max(node *p)
{
    int max = p -> data;
    while(p != NULL){
        if(max < p->data)
            max = p->data;
            p = p -> next;
    }
    return max;
}

void insert(node *p, int v, int t){
    while(p != NULL){
        node * newNode;
        newNode = (node*)malloc(sizeof(node));
        newNode -> data = v;
        if(p->data == t){
            newNode ->next = p ->next;
            p ->next = newNode;
            break;
        }
        p = p -> next;
    }
}
void rem(node **p, int v){
    node *temp = *p;
    node *t = temp;
    if((*p)->data == v){
        *p = (*p)->next;
    }else{
        while((temp->next)->data != v){
                temp = temp->next;
        }
        temp->next = (temp->next)->next;
        temp = temp ->next;
        free(t);
    }
}

duplicate(node *first)
{
    int v = first->data;
    node *prev = first;
    node *after = prev->next;
    while(first->next != NULL){
        while(after != NULL)
        {
            if(v == after->data)
            {
                prev->next = after->next;
                free(after);
            }
            if(prev->next == NULL){
                break;
            }else{
                prev = prev->next;
                after = prev->next;
            }
        }
    first = first->next;
    v = first->data;
    prev = first;
    after = prev ->next;
    }
}

node *intersection(node*first, node*second){
    node *secHead = second;
    node * inter = NULL;
    node * prev;
    node * temp = inter;
    int flag = 1;
    while(first != NULL)
    {

        while(second != NULL)
        {
            if(first->data == second->data)
            {
                while(temp != NULL && flag == 1)
                {
                    if(temp->data == second->data){
                        flag = 0;
                        break;
                    }
                    temp = temp->next;
                }
                if(flag)
                {
                    node * newnode;
                    newnode = (node*) malloc(sizeof(node));
                    newnode->data = first->data;
                    newnode->next = NULL;
                    if(inter == NULL){
                        inter = newnode;
                        prev = newnode;
                    }else{
                        prev->next = newnode;
                        prev = prev->next;
                    }
                }
            }
            second = second->next;
            temp = inter;
        }
        second = secHead;
        first = first->next;
        flag = 1;
    }
    return inter;
}

node *uni(node*first, node*sec)
{
    int flag = 1, count = 0;
    node *header = NULL;
    node *temp = header;
    node *prev;

    while(first != NULL)
    {
        while(temp != NULL)
        {
            if(temp->data == first->data){
                flag = 0;
                break;
            }
            temp = temp->next;
        }
        if(flag)
        {
            node *newnode;
            newnode = (node*) malloc(sizeof(node));
            newnode->data = first->data;
            newnode->next = NULL;
            if(header == NULL){
                header = newnode;
                prev = newnode;
            }else{
                prev->next = newnode;
                prev = prev->next;
            }
        }
        flag = 1;
        temp = header;
        first = first->next;
    }
    while(sec != NULL)
    {
        while(temp != NULL)
        {
            if(temp->data == sec->data){
                flag = 0;
                break;
            }
            temp = temp->next;
        }
        if(flag)
        {
            node *newnode;
            newnode = (node*) malloc(sizeof(node));
            newnode->data = sec->data;
            newnode->next = NULL;
            prev->next = newnode;
            prev = prev->next;
        }
        flag = 1;
        temp = header;
        sec = sec->next;
    }
    return header;
}

void addplace(node **p, int v, int pos)
{
    node *temp = *p;
    node *newnode = (node*) malloc(sizeof(node));
    newnode->data = v;
    newnode->next = NULL;
    int flag = 1;
    int size;
    if(pos == 1)
    {
        *p = newnode;
        newnode->next = temp;
    }else{
        for(size=2; size<pos; size++)
        {
            temp = temp->next;
            if(temp->next == NULL){
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            newnode->next = temp->next;
            temp->next = newnode;

        }else{

            temp->next = newnode;
            printf("\nNODE ADDED AT THE END OF THE LIST SINCE LIST SIZE IS ONLY %d\n\n", size);
        }
    }
}

void main()
{
    node * first = NULL;
    node * second = NULL;
    add(10, &first);
    add(20, &first);
    add(30, &first);
    add(40, &first);
    display(first);
    printf("\n\n");

    add(30, &second);
    add(11, &second);
    add(10, &second);
    add(15, &second);
    display(second);
    printf("\n\n");

    node * third = uni(first,second);
    display(third);
    printf("\n\n");

    node * fourth = intersection(first,second);
    display(fourth);
    printf("\n\n");

    addplace(&first,100, 7);
    display(first);
    printf("\n\n");

    duplicate(second);
    display(second);
    printf("\n\n");



}
