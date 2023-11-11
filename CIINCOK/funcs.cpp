#include"funcs.hpp"
#include<stdio.h>
#include<cstdlib>

void list_new(struct list * list)
{
    list->head = NULL;
    list->tail = NULL;
}

struct list_elem * begining_insert(struct list * list, int data)
{
    struct list_elem * new_elem_pointer = (struct list_elem *)malloc(sizeof(struct list_elem));
    new_elem_pointer->data = data;
    if (list->head == NULL && list->tail == NULL)
    {
        new_elem_pointer->next = NULL;
        new_elem_pointer->prev = NULL;
        list->head = new_elem_pointer;
        list->tail = new_elem_pointer;
    }
    else
    {
        list->head->prev = new_elem_pointer;
        new_elem_pointer->next = list->head;
        list->head = new_elem_pointer;
        new_elem_pointer->prev = NULL;
    }
    return new_elem_pointer;
}

struct list_elem * end_insert(struct list * list, int data)
{
    struct list_elem * new_elem_pointer = (struct list_elem *)malloc(sizeof(struct list_elem));
    new_elem_pointer->data = data;
    if (list->head == NULL && list->tail == NULL)
    {
        new_elem_pointer->next = NULL;
        new_elem_pointer->prev = NULL;
        list->head = new_elem_pointer;
        list->tail = new_elem_pointer;
    }
    else
    {
        list->tail->next = new_elem_pointer;
        new_elem_pointer->prev = list->tail;
        list->tail = new_elem_pointer;
        new_elem_pointer->prev = NULL;
    }
    return new_elem_pointer;
}

struct list_elem * before_current_insert(struct list_elem * current, int data)
{
    struct list_elem * new_elem_pointer = (struct list_elem *)malloc(sizeof(struct list_elem));
    new_elem_pointer->data = data;
    
    current->next->prev = new_elem_pointer;
    new_elem_pointer->next = current->next;
    current->next = new_elem_pointer;
    new_elem_pointer->prev = current;

    return new_elem_pointer;
}

struct list_elem * after_current_insert(struct list_elem * current, int data)
{
    struct list_elem * new_elem_pointer = (struct list_elem *)malloc(sizeof(struct list_elem));
    new_elem_pointer->data = data;
    
    current->prev->next = new_elem_pointer;
    new_elem_pointer->prev = current->prev;
    current->prev = new_elem_pointer;
    new_elem_pointer->prev = current;

    return new_elem_pointer;
}

struct list_elem * getp_begining(struct list * list)
{
    return list->head;
}

struct list_elem * getp_end(struct list * list)
{
    return list->tail;
}

struct list_elem * getp_before_current(struct list_elem * current)
{
    return current->prev;
}

struct list_elem * getp_after_current(struct list_elem * current)
{
    return current->next;
}

int elem_delete(struct list * list, struct list_elem * current)
{
    if (current->prev == NULL)
    {
        current->next->prev = NULL;
        list->head = current->next;
        
    }
    else if (current->next == NULL)
    {
        current->prev->next = NULL;
        list->tail = current->prev;
    }
    else
    {
        current->next->prev = current->prev;
        current->prev->next = current->next;
    }
    int data = current->data;
    free(current);
    return data;
}

struct list_elem * search(struct list * list, int data)
{
    if (list->head == NULL && list->tail == NULL)
    {
        return NULL;
    }
    struct list_elem * set_elem = list->head;
    for (; (set_elem->data != data) && (set_elem != NULL); set_elem = set_elem->next);
    return set_elem;
}

struct list_elem * indsearch(struct list * list, int ind)
{
    if (list->head == NULL && list->tail == NULL)
    {
        return NULL;
    }
    struct list_elem * set_elem = list->head;
    for (int i = 0; (i < ind) && (set_elem != NULL); set_elem = set_elem->next, i++);
    return set_elem;
}

void terminal_dump(struct list * list)
{
    printf( "------------\n"
            "head    = %p\n"
            "tail    = %p\n", list->head, list->tail);
    struct list_elem * set_elem = list->head;
    while(set_elem != NULL)
    {
        printf( "------------\n"
                "pointer = %p\n"
                "data    = %d\n"
                "next    = %p\n"
                "prev    = %p\n", set_elem, set_elem->data, set_elem->next, set_elem->prev);
        set_elem = set_elem->next;
    }
    printf("------------\n");
}

void list_delete(struct list * list)
{
    struct list_elem * set_elem = list->head;
    while(set_elem != NULL)
    {
        set_elem = set_elem->next;
        free(set_elem->prev);
    }
    free(list);
}