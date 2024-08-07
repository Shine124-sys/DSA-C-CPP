/* Program of reversing a string using stack */
/* Data Structures Using C++ by Shoriful Shine */
#include <stdio.h>
#include <string.h>
#define MAX 20

int top = -1;
char stack[MAX];
char pop();
void push (char item);

int main()
{

    char str[20];
    int i;
    printf("\nEnter the string :\n");
    gets(str);

    for (i = 0; i < strlen(str); i++)
        push(str[i]);

    for (i = 0; i < strlen(str); i++)
        str[i] = pop();

    printf("\nReversed string is :\n");
    puts(str);
    return 0;
}

void push(char item)
{
    if (top == MAX - 1)
        printf("Stack overflow\n");
    else
        stack[++top] = item;
}

char pop()
{
    if (top == -1)
        printf("stack underflow \n");
    else
        return stack[top--];
}
