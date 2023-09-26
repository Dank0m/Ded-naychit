#include "funk.hpp"

int main(void)
{
    struct stack stk;
    struct_ctor(&stk);

    struct_dtor(&stk);

    return 0;
}
