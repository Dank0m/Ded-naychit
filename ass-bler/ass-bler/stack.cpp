#include <stdio.h>
#include"stack_funcs.hpp"

int main(void)
{
    struct Stack stk;
    stack_ctor(&stk);

    //dump(&stk);
    stack_dtor(&stk);
    return 0;
}


