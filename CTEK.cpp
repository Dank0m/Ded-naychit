#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Elemen_t;

struct stack
{
    Elemen_t * data;
    int first_free_index = 0;
    int len = 1;
};

int pop (stack *stk);
void struct_ctor(stack *stk);
void push(stack *stk, Elemen_t pushelement);
void data_increaseX2(stack *stk);
void data_reductX4(stack *stk);
void print_stack(stack *stk);

int main(void)
{
    struct stack stk;
    struct_ctor(&stk);
    print_stack(&stk);
    push(&stk, 400);
    printf("Pushed 400\n");
    push(&stk, 228);
    printf("Pushed 228\n");
    printf("%d", pop(&stk));
    printf("Poped\n");
    print_stack(&stk);
    return 0;
}

int pop(stack *stk)
{
    assert(stk->first_free_index != 0);

    stk->first_free_index--;
    printf("beforeReducted\n");
    if ((stk->len) % (stk->first_free_index - 1) == 0)
    {
        printf("Reducted\n");
        data_reductX4(stk);
    }
    printf("afterReducted\n");
    return(stk->data[stk->first_free_index]);
}

void push(stack *stk, Elemen_t pushelement)
{
    if (stk->first_free_index <= stk->len)
        data_increaseX2(stk);
    stk->first_free_index++;
    stk->data[stk->first_free_index - 1] = pushelement;
}

void struct_ctor(stack *stk)
{
    stk->data = (Elemen_t *)malloc(5);
    stk->len = 5;
    stk->first_free_index = 0;
    assert(stk->data != NULL);
}

void data_increaseX2(stack *stk)
{
    Elemen_t * pred_ind = stk->data;
    stk->data = (Elemen_t *)realloc(pred_ind, stk->len * 2);
    stk->len = stk->len * 2;
    if (pred_ind != stk->data)
        free(pred_ind);
    assert(stk->data != NULL);
}

void data_reductX4(stack *stk)
{
    Elemen_t * pred_ind = stk->data;
    //stk->data = (Elemen_t *)realloc(pred_ind, stk->len / 4);
    //stk->len = stk->len / 4;
    //if (pred_ind != stk->data)
    //    free(pred_ind);
    assert(stk->data != NULL);
}

void print_stack(stack *stk)
{
    printf("data = %p, %p, %d \n", stk->data, stk->data[3], (stk->data[3]));
    for (int i = 0; i < stk->first_free_index; i++)
    {
        printf("%d\n", stk->data[i]);
    }

}
