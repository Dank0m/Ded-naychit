#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define LEN_STR 50

// int name_coder(char text[]);

// enum TEXT_CODES
// {
//     T_PUSH = 4484,
//     T_IN   = 2152,
//     T_ADD  = 2973,
//     T_SUB  = 3303,
//     T_MUL  = 3343,
//     T_DIV  = 3233,
//     T_OUT  = 3443,
//     T_HLT  = 3283
// };

enum COMMAND_CODES
{
    HLT  = 0,
    PUSH = 1,
    IN   = 2,
    ADD  = 3,
    SUB  = 4,
    MUL  = 5,
    DIV  = 6,
    OUT  = 7,
    COMMANDS_COUNTS
};

int main(void)
{
    FILE * text_code = fopen("text_code.txt", "r");
    FILE * machine_code = fopen("machine_code.txt", "w");

    const char * commands[] = {"hlt", "push", "in", "add", "sub", "mul", "div", "out"};

    char text[LEN_STR];

    int buf_number = 0;

    int command_defined = 0;
    int halt_reached = 0;

    while (fscanf(text_code, "%s", text))
    {   
        command_defined = 0;
        printf("text = %s\n", text);

        for(int command_code = 0; command_code < COMMANDS_COUNTS; command_code++)
        {
            if (strcmp(text, commands[command_code]) == 0)
            {
                if (strcmp("push", commands[command_code]) == 0)
                {
                    fscanf(text_code, "%d", &buf_number);
                    fprintf(machine_code, "%d %d\n", command_code, buf_number);
                }
                else if (strcmp("hlt", commands[command_code]) == 0)
                {
                    fprintf(machine_code, "%d\n", command_code);
                    halt_reached = 1;
                }
                else
                {
                    fprintf(machine_code, "%d\n", command_code);
                }
                
                command_defined = 1;
                break;
            }
        }
        if (command_defined == 0)
        {
            printf("    Wrong command: %s\n"
                   "    buf_number   = %d\n", text, buf_number);
        }
        if (halt_reached)
        {
            break;
        }
    }
    fclose(text_code);
    fclose(machine_code);
    return 0;
}
