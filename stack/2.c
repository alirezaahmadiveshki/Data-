#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// struct point
// {
//     int x;
//     int y;
// };

// #define ROWS 2
// #define COLS 2

typedef struct{
    int *list;
    int MAXSIZE;
    int top;
}Stack;

void stack_initilizer(Stack *s);
void show_stack(Stack *s);
int stack_pop(Stack *s);
void stack_push(Stack *s);

// void show_std(Student *s);

int main(void)
{
    Stack *s;
    s = (Stack *)malloc(sizeof(Stack));
    s->list = (int *)malloc(sizeof(int) * 20);
    stack_initilizer(s);
    for(int i = 0; i < 5; i++)
    {
        s->top++;
        s->list[i] = i*10;
    };

    show_stack(s);
    int poped = stack_pop(s);
    printf("poped: %d\n", poped);
    show_stack(s);
    free(s->list);
    free(s);
    

    // int matrix[ROWS][COLS] = {0};

    // for (int i = 0; i < ROWS; i++)
    // {
    //     for (int j = 0; j < COLS; j++)
    //     {
    //         printf("matrix[%d][%d]= ", i, j);
    //         scanf("%d", &matrix[i][j]);
    //     }
    // }
    // printf("--------------------------\n");

    // for (int i = 0; i < ROWS; i++)
    // {
    //     for (int j = 0; j < COLS; j++)
    //     {
    //         printf("matrix[%d][%d]: %d\n", i, j, matrix[i][j]);
    //     }
    // }
    // -----------------------------------
    // Student *s1;
    // s1 = (Student *)malloc(1 * sizeof(Student));
    // s1->id = 4014013007;
    // s1->avg = 15;
    // s1->name = (char *)malloc(20 * sizeof(char));
    // strcpy(s1->name, "alirezw");
    // strcpy(s1->family_name, "Ahmadi");
    // strcpy(s1->university, "isfahan university");
    // strcpy(s1->field_of_study, "computer science");
    // show_std(s1);
    // Student b = *s1;
    // strcpy(b.name, "ali");
    // show_std(s1);
    // show_std(&b);
    // free(s1->name);
    // free(s1);
    // -------------------------------------
    // struct point p1;
    // p1.x = 1;
    // p1.y = 1;
    // struct point p2 = {2, 2};
    // printf("(%d, %d)\n", p2.x, p2.y);
    //
    // struct point p3 = {
    //     .x = 3,
    //     .y = 3
    // };
    // printf("(%d, %d)\n", p3.x, p3.y);
    return 0;
}

void stack_initilizer(Stack *s)
{
    s->top = -1;
    s->MAXSIZE = 30;
}

int stack_pop(Stack *s)
{
    if (s->top = -1)
    {
        return "underflow; given stack is empty";
    }
    else{
        s->top = s->top - 1;
        return s->list[s->top + 1];
    }
}

void show_stack(Stack *s)
{
    printf("top index is: %d\n", s->top);
    printf("the MAXSIZE is: %d\n", s->MAXSIZE);
    for(int i = 0; i <= s->top; i++)
    {
        printf("---------\n");
        printf("%d\n", s->list[i]);
    };
}

// void show_std(Student *s)
// {
//     printf("id: %ld\n", s->id);
//     printf("full name: %s %s\n", s->name, s->family_name);
//     printf("university: %s\n", s->university);
//     printf("field of study: %s\n", s->field_of_study);
// };
