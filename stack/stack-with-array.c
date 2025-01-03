#include <stdio.h>
#include <string.h>
#include <stdlib.h>
    
typedef struct{
    int *list;
    int MAXSIZE;
    int top;
}Stack;

void stack_initilizer(Stack *s);
void show_stack(Stack *s);
int stack_pop(Stack *s);
void stack_push(Stack *s, int item);

int main(void)
{
    Stack *s;
    s = (Stack *)malloc(sizeof(Stack));
    s->list = (int *)malloc(sizeof(int) * 20);
    stack_initilizer(s);
    int result = stack_pop(s);
    printf("result: %d\n", result);
    // for(int i = 0; i < s->MAXSIZE; i++)
    // {
    //     s->top++;
    //     s->list[i] = i*10;
    // };

    stack_push(s, 0);
    stack_push(s, 1);
    stack_push(s, 2);
    stack_push(s, 3);
    stack_pop(s);
    stack_pop(s);
    stack_pop(s);
    stack_pop(s);



    free(s->list);
    free(s); 

    return 0;
}

void stack_initilizer(Stack *s)
{
    s->top = -1;
    s->MAXSIZE = 3;
}

void stack_push(Stack *s, int item)
{
    printf("push operation: ");
    if (s->top < (s->MAXSIZE-1))
    {
        printf("   succeed\n");
        s->top = s->top + 1;
        s->list[s->top] = item;
    }
    else {
        printf("  overflow\n");
    }
    show_stack(s);
}

int stack_pop(Stack *s)
{
    printf("pop operation: ");
    if (s->top == -1)
    {
        printf(" underflow\n");
        show_stack(s);
        return -1;
    }
    else{
        printf(" succeed\n");
        s->top = s->top - 1;
        show_stack(s);
        return s->list[s->top + 1];
    }
}

void show_stack(Stack *s)
{
    printf("--------------------------------------\n");
    printf("top index is: %d\n", s->top);
    printf("the MAXSIZE is: %d\n", s->MAXSIZE);
    if (-1 == s->top)
    {
        printf("Empty Stack\n");
    }
    else
    {
    for(int i = 0; i <= s->top; i++)
    {
        printf("---------\n");
        printf("%d\n", s->list[i]);
    };
    }
    printf("--------------------------------------\n");
}
