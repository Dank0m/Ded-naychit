#include<stdio.h>

#define LEN_STR 50

int main(void)
{

    FILE * text_code = fopen("text_code.txt", "r");
    FILE * machine_code = fopen("machine_code.txt", "w");

    char text[LEN_STR];

    while (fgets(text, LEN_STR, text_code) != 0)
    {
        if (strcmp(text, "push") == 0)
        {
            fprintf("1 %d\n" number_separator(text));
        }
        else if
    }

    printf("%s\n", text);

    fclose(text_code);
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
            end_of_num = 1;
        }
        else if (end_of_alp == 1)
        {
            return number;
        }
    }
}