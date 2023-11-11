#include"funcs.hpp"


int main(void)
{
    struct list list;
    list_new(&list);

    terminal_dump(&list);

    begining_insert(&list, 2);
    begining_insert(&list, 8);

    terminal_dump(&list);

    list_delete(&list);
    return 0;
}
