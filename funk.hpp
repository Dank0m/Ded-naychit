#pragma once

typedef int Elemen_t;

struct stack
{
    Elemen_t * data;
    int capacity = 0;
    int len = 1;
};

int pop (stack *stk);
void struct_ctor(stack *stk);
void struct_dtor(stack *stk);
void push(stack *stk, Elemen_t pushelement);
void data_increaseX2(stack *stk);
void data_reductX4(stack *stk);
void print_stack(stack *stk);