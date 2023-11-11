#pragma once

struct list_elem
{
    int data;
    struct list_elem * next; 
    struct list_elem * prev; 
};
struct list
{
    struct list_elem * head; 
    struct list_elem * tail; 
};

void list_new(struct list * list);
struct list_elem * begining_insert(struct list * list, int data);
struct list_elem * end_insert(struct list * list, int data);
struct list_elem * before_current_insert(struct list_elem * current, int data);
struct list_elem * after_current_insert(struct list_elem * current, int data);
struct list_elem * getp_begining(struct list * list);
struct list_elem * getp_end(struct list * list);
struct list_elem * getp_before_current(struct list_elem * current);
struct list_elem * getp_after_current(struct list_elem * current);
int elem_delete(struct list * list, struct list_elem * current);
struct list_elem * search(struct list * list, int data);
struct list_elem * indsearch(struct list * list, int ind);
void terminal_dump(struct list * list);
void list_delete(struct list * list);