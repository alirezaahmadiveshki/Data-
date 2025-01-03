#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int head;
    int tail;
    int *list;
    int length;
} queue;

void queue_init(queue *q);
void show_queue(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);

int main(void)
{
    queue *my_queue;
    my_queue = (queue *)malloc(sizeof(queue));
    queue_init(my_queue);
    my_queue->list = (int *)malloc((my_queue->length) * sizeof(int));
    // -------------------------
    show_queue(my_queue);
    enqueue(my_queue, 10);
    show_queue(my_queue);
    enqueue(my_queue, 20);
    show_queue(my_queue);
    dequeue(my_queue);
    show_queue(my_queue);
    dequeue(my_queue);
    show_queue(my_queue);
    dequeue(my_queue);
    show_queue(my_queue);

    // ------------------------
    free(my_queue->list);
    free(my_queue);
    return 0;
}

void queue_init(queue *q)
{
    q->head = 0;
    q->tail = 0;
    q->length = 5;
}

void show_queue(queue *q)
{
    int head = q->head;
    int tail = q->tail;
    printf("Tail index: %d\n", tail);
    printf("Head index: %d\n", head);
    printf("Length: %d\n", q->length);
    if (head > tail)
    {
        int j = 0;
        for (int i = head; i < (tail + q->length)+1; i++)
        {
            j = i%(q->length);
            printf(" %d |", q->list[j]);
        }
    }
    else if (head < tail)
    {
        for (int i = head; i < tail; i++)
        {
            printf(" %d |", q->list[i]);
        }
    }
    else
    {
        printf("empty queue");
    }
    printf("\n");
}

void enqueue(queue *q, int x)
{
    printf("-------------------------------\n");
    int length = q->length;
    printf("enqueue operation: ");
    if (q->head == (q->tail + 1) || (q->tail == length && q->head == 0))
    {
        printf("OVERFLOW!\n");
    }
    else
    {
        printf("succeed!\n");
        q->tail = (q->tail) % 5;
        q->list[q->tail] = x;
        if (q->tail + 1 != q->head)
        {
            q->tail = (q->tail + 1);
        }
    }
    printf("-------------------------------\n");
}

int dequeue(queue *q)
{
    printf("-------------------------------\n");
    printf("dequeue operation: ");
    int head = q->head;
    int tail = q->tail;
    int length = q->length;
    if (head != tail)
    {
        if (head == (length - 1))
        {
            printf("succeed!\n");
            int poped = q->list[head];
            q->head == 0;
            printf("-------------------------------\n");
            return poped;
        }
        else
        {
            printf("succeed!\n");
            int poped = q->list[head];
            q->head++;
            printf("-------------------------------\n");
            return poped;
        }
    }
    else
    {
        printf("UNDERFLOW!\n");
    }
}