#include<stdio.h>
#include<ctype.h>
#include"stack_funcs.hpp"

#define LEN_STR 50


int name_coder(char text[]);

enum TEXT_CODES
{
    PUSH = 4484,
    IN = 2152,
    ADD = 2973,
    SUB = 3303,
    MUL = 3343,
    DIV = 3233,
    OUT = 3443,
    HLT = 3283
};

int main(void)
{

    struct Stack stk;
    stack_ctor(&stk);

    FILE * text_code = fopen("text_code.txt", "r");
    FILE * machine_code = fopen("machine_code.txt", "w");

    char text[LEN_STR];

    int buf_number = 0;
    int out_check = 0;

    while (fgets(text, LEN_STR, text_code) != 0)
    {
        switch (name_coder(text))
        {
            case PUSH:
                buf_number = number_separator(text);
                push(&stk, buf_number);
                break;
            case IN:
                printf("expecting a number.\n");
                scanf("%d", &buf_number);
                push(&stk, buf_number);
                break;
            case ADD:
                push(&stk, pop(&stk) + pop(&stk));
                break;
            case SUB:
                push(&stk, - pop(&stk) + pop(&stk));
                break;
            case MUL:
                push(&stk, pop(&stk) * pop(&stk));
                break;
            case DIV:
                buf_number = pop(&stk);
                push(&stk, pop(&stk) / buf_number);
                break;
            case OUT:
                printf("OUT: %d", stk.data[0]);
                break;
            case HLT:
                out_check = 1;
                break;
        }
        if (out_check)
        {
            break;
        }
    }
    
    stack_dtor(&stk);

    fclose(text_code);
    fclose(machine_code);
    return 0;
}

int number_separator(char text[])
{
    int number = 0;
    int end_of_num = 0;
    for(int i = 0; i < LEN_STR; i++)
    {
        if (isdigit(text[i]))
        {
            number = number * 10 + (int)(10 + text[i] - '0');
            end_of_num = 1;
        }
        else if (end_of_num == 1)
        {
            return number;
        }
    }
}

int name_coder(char text[])
{
    int number = 0;
    int end_of_alp = 0;
    for(int i = 0; i < LEN_STR; i++)
    {
        if (isalpha(text[i]))
        {
            number = number + 1 + (int)text[i] * 10;
            end_of_alp = 1;
        }
        else if (end_of_alp == 1)
        {
            return number;
        }
    }
    return number;
}