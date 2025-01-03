#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TABLE_SIZE 128
#define DOMAIN 1000 

struct Node
{
    int key;
    struct Node *next;
};

struct LinkedList
{
    struct Node *head;
};

typedef struct HashTable
{
    struct LinkedList *table;
    int size;
} HashTable;

// Function prototypes
// Linked List
struct Node *Create_Node(int key);
struct Node *List_Search(struct LinkedList *L, int key);
void List_Insert(struct LinkedList *L, struct Node *x);
void List_Delete(struct LinkedList *L, struct Node *x);
void List_Traversal(struct Node *head);
// Hash
HashTable *Create_Hash(int size);
int hash(int key, int size);
void Hash_Insert(HashTable *hashTable, int key);
void Hash_Delete(HashTable *hashTable, int key);
struct Node *Hash_Search(HashTable *hashTable, int key);
void Hash_Display(HashTable *hashTable);

// Main function for testing
int main(void)
{
    HashTable *hashTable = Create_Hash(TABLE_SIZE);
    // testing operations
    // ---------inserting------------

    // inserting numbers between 0 to 99
    for (int i = 0; i < DOMAIN; i++)
        Hash_Insert(hashTable, i);

    Hash_Display(hashTable);

    // ---------searching------------

    // struct Node *found = Hash_Search(hashTable, 15);

    // if (found)
    // {
    //     printf("Key %d found in the hash table.\n", found->key);
    // }
    // else
    // {
    //     printf("Key 15 not found in the hash table.\n");
    // }

    // ---------deleting------------

    // Hash_Delete(hashTable, 15);
    // Hash_Display(hashTable);

    // Hash_Delete(hashTable, 50);

    // // freeing the memory allocated to the hash setup
    // free(hashTable->table);
    // free(hashTable);

    return 0;
}

// Creates a node for a key
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

void List_Insert(struct LinkedList *L, struct Node *x)
{
    x->next = L->head;
    L->head = x;
}

void List_Delete(struct LinkedList *L, struct Node *x)
{
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


// Create|Initilizing the hash table
HashTable *Create_Hash(int size)
{
    HashTable *hashTable = (HashTable *)malloc(sizeof(HashTable));
    hashTable->table = (struct LinkedList *)malloc(size * sizeof(struct LinkedList));
    hashTable->size = size;

    for (int i = 0; i < size; i++)
    {
        hashTable->table[i].head = NULL;
    }

    return hashTable;
}

// ceil(m(kA mod 1))
int hash(int key, int size)
{
    double A = (sqrt(5) - 1) / 2;
    return ceil(TABLE_SIZE*(fmod(key * A, 1.0)));
}                                                                             

// h(k) = k^2 mod |m|
// int hash(int key, int size)
// {
//     return (key * key) % size;
// }

// Insert a key into the hash table
void Hash_Insert(HashTable *hashTable, int key)
{
    int index = hash(key, hashTable->size);
    struct Node *newNode = Create_Node(key);
    List_Insert(&hashTable->table[index], newNode);
}

// Delete a key from the hash table
void Hash_Delete(HashTable *hashTable, int key)
{
    int index = hash(key, hashTable->size);
    struct Node *node = List_Search(&hashTable->table[index], key);
    if (node != NULL) // if the node exists in the linkedlist
        List_Delete(&hashTable->table[index], node);
}

// Search for a key in the hash table
struct Node *Hash_Search(HashTable *hashTable, int key)
{
    int index = hash(key, hashTable->size);
    struct Node *node = List_Search(&hashTable->table[index], key);
    return node;
}

// Display the hash table
void Hash_Display(HashTable *hashTable)
{
    for (int i = 0; i < hashTable->size; i++)
    {
        struct Node *current = hashTable->table[i].head;
        printf("[%d]:", i);
        List_Traversal(current);
    }
}
