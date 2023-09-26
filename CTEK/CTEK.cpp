#include "funk.cpp"
#include "funk.hpp"

typedef int Elemen_t;

struct stack
{
    Elemen_t * data;
    int first_free_index = 0;
    int len = 1;
};

int main(void)
{
    struct stack stk;
    struct_ctor(&stk);

    struct_dtor(&stk);

    return 0;
}
