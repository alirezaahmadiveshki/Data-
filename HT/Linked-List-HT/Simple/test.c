#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 10

typedef struct
{
    int size;
    int data[MAX_HEAP_SIZE];
} Heap;

// Function Prototypes
Heap *Heap_Create();
void swap(int *a, int *b);
void max_heapify(Heap *heap, int i);
void build_max_heap(Heap *heap);

int main(void)
{
    // allocating a memory to the heap
    Heap *heap = Heap_Create();
    heap->data[0] = 3;
    heap->data[1] = 1;
    heap->data[2] = 6;
    heap->data[3] = 5;
    heap->data[4] = 2;
    heap->data[5] = 4;

    build_max_heap(heap);

    printf("Max Heap: ");
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->data[i]);
    }
    printf("\n");

    free(heap);

    return 0;
}

Heap *Heap_Create()
{
    Heap *heap;
    heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 6;
    return heap;
}


void swap(int *a, int *b)
{

}

void max_heapify(Heap *heap, int i)
{

}

void build_max_heap(Heap *heap)
{

}