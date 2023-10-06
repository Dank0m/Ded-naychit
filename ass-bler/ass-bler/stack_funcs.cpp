#include<stdlib.h>
#include<stdio.h>
#include"stack_funcs.hpp"

void stack_ctor(struct Stack * stk)
{
    stk->data = (Element_t *)calloc(5, sizeof(Element_t));
    stk->capacity = 5;
    stk->len = 0;
}

void stack_dtor(struct Stack * stk)
{
    free(stk->data);
}

void push(struct Stack * stk, Element_t push_element)
{
    if (stk->len >= stk->capacity)
    {
        capacity_increase_X2(stk);
    }
    stk->data[stk->len] = push_element;
    stk->len++;
}

Element_t pop(struct Stack * stk)
{
    if (stk->len <= 0)
    {
        return 7e5 + 7;
    }
    stk->len--;
    Element_t deleted_element = stk->data[stk->len];
    stk->data[stk->len] = 0;
    if ((stk->capacity / stk->len) == 4)
    {
        capacity_decrease_X4(stk);
    }
    return deleted_element;
}

void capacity_increase_X2(struct Stack * stk)
{
    stk->data = (Element_t *)realloc(stk->data, stk->capacity * 2 * sizeof(Element_t));
    stk->capacity = stk->capacity * 2;
    for(int i = stk->len; i < stk->capacity; i++)
        stk->data[i] = 0;
}

void capacity_decrease_X4(struct Stack * stk)
{
    stk->data = (Element_t *)realloc(stk->data, stk->capacity / 4);
    stk->capacity = stk->capacity / 4;
}

void dump(struct Stack * stk)
{
    printf("data_pointer = %p\n", stk->data);
    printf( "data:\n");
    for (int i = 0; i < stk->capacity; i++)
        printf("   data[%d] = %d\n", i, stk->data[i]);
    printf("capacity = %d\n", stk->capacity);
    printf("len      = %d\n", stk->len);
}