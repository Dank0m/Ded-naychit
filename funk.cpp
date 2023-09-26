#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "funk.hpp"

int pop(stack *stk)
{
    assert(stk->capacity != 0);

    stk->capacity--;
    if ((stk->capacity >= 1) && ((stk->len) % (stk->capacity) == 0) && ((stk->len) / (stk->capacity) == 4))
    {
        data_reductX4(stk);
    }
    return(stk->data[stk->capacity]);
}

void push(stack *stk, Elemen_t pushelement)
{
    if (stk->capacity >= stk->len)
        data_increaseX2(stk);
    stk->capacity++;
    stk->data[stk->capacity - 1] = pushelement;
}

void struct_ctor(stack *stk)
{
    stk->data               = (Elemen_t *)malloc(5);
    stk->len                = 5;
    stk->capacity   = 0;

    assert(stk->data != NULL);
}

void struct_dtor(stack *stk)
{
    assert(stk->data != NULL);

    free(stk->data);
}

void data_increaseX2(stack *stk)
{
    Elemen_t * pred_ind = stk->data;

    stk->data               = (Elemen_t *)realloc(pred_ind, stk->len * 2);
    stk->len                = stk->len * 2;

    if (pred_ind != stk->data)
        free(pred_ind);

    assert(stk->data != NULL);
}

void data_reductX4(stack *stk)
{
    Elemen_t * pred_ind     = stk->data;
    stk->data               = (Elemen_t *)realloc(pred_ind, stk->len / 4);
    stk->len                = stk->len / 4;
    if (pred_ind != stk->data)
        free(pred_ind);

    assert(stk->data != NULL);
}

void print_stack(stack *stk)
{
    printf("capacity = %d, " 
           "len = %d, "
           "data_pointer = %p ", 
            stk->capacity, stk->len, stk->data);
    for (int i = 0; i < stk->capacity; i++)
    {
        printf("data[%d] = %d\n", i, stk->data[i]);
    }
}