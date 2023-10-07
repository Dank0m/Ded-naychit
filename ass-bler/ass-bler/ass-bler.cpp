#include<stdio.h>
#include<ctype.h>

#define LEN_STR 50

int name_coder(char text[]);

enum TEXT_CODES
{
    T_PUSH = 4484,
    T_IN   = 2152,
    T_ADD  = 2973,
    T_SUB  = 3303,
    T_MUL  = 3343,
    T_DIV  = 3233,
    T_OUT  = 3443,
    T_HLT  = 3283
};

enum COMMAND_CODES
{
    PUSH = 1,
    IN   = 2,
    ADD  = 3,
    SUB  = 4,
    MUL  = 5,
    DIV  = 6,
    OUT  = 7,
    HLT  = -1
};

int main(void)
{
    FILE * text_code = fopen("text_code.txt", "r");
    FILE * machine_code = fopen("machine_code.txt", "w");

    char text[LEN_STR];

    int buf_number = 0;
    int out_check = 0;

    while (fscanf(text_code, "%s %d", text, &buf_number) != 0)
    {   
        //printf("text = %s\n", text);
        //printf("codered_text = %d\n", name_coder(text));
        switch (name_coder(text))
        {
            case T_PUSH:
                fprintf(machine_code, "%d %d\n", PUSH, buf_number);
                break;
            case T_IN:
                fprintf(machine_code, "%d\n", IN);
                break;
            case T_ADD:
                fprintf(machine_code, "%d\n", ADD);
                break;
            case T_SUB:
                fprintf(machine_code, "%d\n", SUB);
                break;
            case T_MUL:
                fprintf(machine_code, "%d\n", MUL);
                break;
            case T_DIV:
                fprintf(machine_code, "%d\n", DIV);
                break;
            case T_OUT:
                fprintf(machine_code, "%d\n", OUT);
                break;
            case T_HLT:
                fprintf(machine_code, "%d\n", HLT);
                out_check = 1;
                break;
            default:
                printf("    Wrong command: %s\n    buf_number = %d\n", text, buf_number);
                break;
        }
        if (out_check)
        {
            break;
        }
    }
    fclose(text_code);
    fclose(machine_code);
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

        //     case PUSH:
        //         fscanf(text_code, "%s %d", text, &buf_number);
        //         push(&stk, buf_number);
        //         break;
        //     case IN:
        //         printf("expecting a number.\n");
        //         scanf("%d", &buf_number);
        //         push(&stk, buf_number);
        //         break;
        //     case ADD:
        //         push(&stk, pop(&stk) + pop(&stk));
        //         break;
        //     case SUB:
        //         push(&stk, - pop(&stk) + pop(&stk));
        //         break;
        //     case MUL:
        //         push(&stk, pop(&stk) * pop(&stk));
        //         break;
        //     case DIV:
        //         buf_number = pop(&stk);
        //         push(&stk, pop(&stk) / buf_number);
        //         break;
        //     case OUT:
        //         printf("OUT: %d", stk.data[0]);
        //         break;
        //     case HLT:
        //         out_check = 1;
        //         break;


        // int number_separator(char text[])
// {
//     int number = 0;
//     int end_of_num = 0;
//     for(int i = 0; i < LEN_STR; i++)
//     {
//         if (isdigit(text[i]))
//         {
//             number = number * 10 + (int)(10 + text[i] - '0');
//             end_of_num = 1;
//         }
//         else if (end_of_num == 1)
//         {
//             return number;
//         }
//     }
// }
