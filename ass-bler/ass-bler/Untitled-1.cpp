#include<stdio.h>
#include<ctype.h>

int name_coder(char text[]);

#define LEN_STR 50


int main(void)
{
    printf("PUSH = %d\n"
           "IN = %d\n"
           "ADD = %d\n"
           "SUB = %d\n"
           "MUL = %d\n"
           "DIV = %d\n"
           "OUT = %d\n"
           "HLT = %d\n", 
    name_coder("push"),
    name_coder("in"),
    name_coder("add"),
    name_coder("sub"),
    name_coder("mul"),
    name_coder("div"),
    name_coder("sin"),
    name_coder("cos"),
    name_coder("sqr"),
    name_coder("out"),
    name_coder("hlt"));
    return 0;
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