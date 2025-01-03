#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int key;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
};

struct Node *Create_Node(int key);
struct Node *List_Search(struct LinkedList *L, int key);
void List_Beginning_Insert(struct LinkedList *L, struct Node *x);
void List_End_Insert(struct LinkedList *L, struct Node *x);
bool List_Membership(struct LinkedList *L, struct Node *x);
void List_Delete(struct LinkedList *L, struct Node *x);

void List_Traversal(struct Node *head);

int main(void)
{
    struct LinkedList *L = (struct LinkedList *)malloc(sizeof(struct LinkedList));
    L->head = NULL;
    struct Node *x1 = Create_Node(10);
    struct Node *x2 = Create_Node(20);
    struct Node *x3 = Create_Node(30);
    struct Node *x4 = Create_Node(40);
    List_Beginning_Insert(L, x1);
    List_Beginning_Insert(L, x2);
    List_Beginning_Insert(L, x3);
    List_End_Insert(L, x4);
    List_Delete(L, x1);
    List_Traversal(L->head);
}

struct Node *Create_Node(int key)
{
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->key = key;
    newnode->next = NULL;
    return newnode;
}

struct Node *List_Search(struct LinkedList *L, int k)
{
    struct Node *x = L->head;
    {
        x = x->next;
    }
    return x;
}

void List_Beginning_Insert(struct LinkedList *L, struct Node *x)
{
    x->next = L->head;
    L->head = x;
}

void List_End_Insert(struct LinkedList *L, struct Node *x)
{
    x->next = NULL;
    if (L->head == NULL)
    {
        L->head = x;
    }
    else
    {
        struct Node *curr = L->head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = x;
    }
}

bool List_Membership(struct LinkedList *L, struct Node *x)
{
    struct Node *temp = L->head;
    while (temp != x && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        return false;
    }
    return true;
}

void List_Delete(struct LinkedList *L, struct Node *x)
{
    if (!(List_Membership(L, x)))
    {
        return;
    }
    if (L->head == x)
    {
        L->head = x->next;
    }
    else
    {
        struct Node* prev = L->head;
        while (prev->next != x)
        {
            prev = prev->next;
        }
        prev->next = x->next;
    }
}

void List_Traversal(struct Node *head)
{
    struct Node *temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->key);
        temp = temp->next;
    }
    printf("NULL\n");
}
