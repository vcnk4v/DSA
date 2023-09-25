#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct snode
{
    int c;
    struct snode *next;
} snode;

typedef snode *Stack;

void push(int c, Stack s)
{
    Stack n = (Stack)malloc(sizeof(snode));
    n->c = c;
    n->next = s->next;
    s->next = n;
}

int pop(Stack s)
{
    if (s->next == NULL)
    {
        return -1;
    }
    int k = s->next->c;
    Stack temp = s->next;
    s->next = s->next->next;
    free(temp);
    return k;
}

int evaluate(char *str)
{
    Stack s = (Stack)malloc(sizeof(snode));
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] >= 48 && str[i] <= 57)
        {
            int x = str[i] - '0';
            push(x, s);
        }
        else
        {
            int a = pop(s);
            int b = pop(s);
            if (str[i] == '%')
            {
                push(b % a, s);
            }
            else if (str[i] == '+')
            {
                push(a + b, s);
            }
            else if (str[i] == '-')
            {
                push(b - a, s);
            }
            else if (str[i] == '*')
            {
                push(b * a, s);
            }
            else if (str[i] == '/')
            {
                push(b / a, s);
            }
        }
    }
    return pop(s);
}
int main()
{
    char str[10];
    scanf("%s", str);
    printf("%d\n", evaluate(str));
    return 0;
}
