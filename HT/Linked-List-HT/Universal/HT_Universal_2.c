#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TABLE_SIZE 100
#define DOMAIN 1000 
#define PRIME 997

struct Node
{
    int key;
    struct Node *next;
    struct Node *prev;
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
struct Node *List_Search(struct LinkedList *L, int k);
void List_Insert(struct LinkedList *L, struct Node *x);
void List_Delete(struct LinkedList *L, struct Node *x);
// Hash
HashTable *Create_Hash(int size);
int hash(int key, int size);
void Hash_Insert(HashTable *hashTable, int key);
void Hash_Delete(HashTable *hashTable, int key);
struct Node *Hash_Search(HashTable *hashTable, int key);
void Hash_Display(HashTable *hashTable);

// Main function for testing
int main()
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
    newnode->prev = NULL;
    return newnode;
}

// Searching for a node in the linked list
struct Node *List_Search(struct LinkedList *L, int k)
{
    struct Node *x = L->head;
    while (x != NULL && x->key != k)
    {
        x = x->next;
    }
    return x;
}

// Inserting a node in the linkedlist 
void List_Insert(struct LinkedList *L, struct Node *x)
{
    x->next = L->head;
    if (L->head != NULL)
    {
        L->head->prev = x;
    }
    L->head = x;
    x->prev = NULL;
}

// deleting a node in the linkedlist
void List_Delete(struct LinkedList *L, struct Node *node)
{
    if (node->prev != NULL)
    {
        node->prev->next = node->next;
    }
    else
    {
        L->head = node->next;
    }
    if (node->next != NULL)
    {
        node->next->prev = node->prev;
    }
}

void List_Traversal(struct Node *head)
{
    struct Node *temp = head;
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

// h(a, b, k) = ((ak + b) mod p) mod m
int hash(int key, int size)
{
    srand(time(0));
    // Generate random number in range [min, max]
    int a = (rand() % (PRIME - 1 + 1)) + 1;
    int b = (rand() % (PRIME - 0 + 1)) + 0;
    return (((a*key) + b) % PRIME) % TABLE_SIZE;
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
