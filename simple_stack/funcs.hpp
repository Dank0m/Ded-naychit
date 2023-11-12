#pragma once

typedef int Element_t;

struct Stack
{
    Element_t * data;
    int capacity;
    int len;
};


void stack_ctor(struct Stack * stk);
void stack_dtor(struct Stack * stk);
void push(struct Stack * stk, Element_t push_element);
Element_t pop(struct Stack * stk);
void capacity_increase_X2(struct Stack * stk);
void capacity_decrease_X4(struct Stack * stk);
void dump(struct Stack * stk);



