#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int pop(stack *stk)
{
    assert(stk->first_free_index != 0);

    stk->first_free_index--;
    if ((stk->first_free_index >= 1) && ((stk->len) % (stk->first_free_index) == 0) && ((stk->len) / (stk->first_free_index) == 4))
    {
        data_reductX4(stk);
    }
    return(stk->data[stk->first_free_index]);
}

void push(stack *stk, Elemen_t pushelement)
{
    if (stk->first_free_index >= stk->len)
        data_increaseX2(stk);
    stk->first_free_index++;
    stk->data[stk->first_free_index - 1] = pushelement;
}

void struct_ctor(stack *stk)
{
    stk->data               = (Elemen_t *)malloc(5);
    stk->len                = 5;
    stk->first_free_index   = 0;

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
    printf("first_free_index = %d, len = %d, data_pointer = %p\n", stk->first_free_index, stk->len, stk->data);
    for (int i = 0; i < stk->first_free_index; i++)
    {
        printf("%d ", stk->data[i]);
    }
    putchar('\n');
}