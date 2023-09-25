#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct snode
{
    char c;
    struct snode *next;
} snode;

typedef snode *Stack;

void push(char c, Stack s)
{
    Stack n = (Stack)malloc(sizeof(snode));
    n->c = c;
    n->next = s->next;
    s->next = n;
}

char pop(Stack s)
{
    if (s->next == NULL)
    {
        return -1;
    }
    char k = s->next->c;
    Stack temp = s->next;
    s->next = s->next->next;
    free(temp);
    return k;
}

int precedence(char operator)
{
    switch (operator)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

char *convert(int n, char *infix)
{
    int j = 0;
    char *postfix = (char *)malloc(sizeof(char) * (n + 2));
    Stack s = (Stack)malloc(sizeof(snode));
    for (int i = 0; i < n; i++)
    {
        if (infix[i] == ' ')
        {
            continue;
        }
        else if ((infix[i] >= 48 && infix[i] <= 57) || (infix[i] >= 65 && infix[i] <= 90) || (infix[i] >= 97 && infix[i] <= 122))
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i], s);
        }
        else if (infix[i] == ')')
        {
            while (s->next != NULL && s->next->c != '(')
            {
                postfix[j++] = pop(s);
            }
            if (s->next != NULL && s->next->c != '(')
            {
                return "invalid";
            }
            else
            {
                pop(s);
            }
        }
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
        {
            while (s->next != NULL && precedence(s->next->c) >= precedence(infix[i]))
            {
                postfix[j++] = pop(s);
            }
            push(infix[i], s);
        }
    }
    while (s->next != NULL)
    {
        if (s->next->c == '(')
        {
            return "invaldid";
        }
        postfix[j++] = pop(s);
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[20];
    scanf("%s", infix);
    char *postfix = convert(strlen(infix), infix);
    printf("%s\n", postfix);
    free(postfix);
    return 0;
}