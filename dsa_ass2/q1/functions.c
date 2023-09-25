#include "functions.h"
Stack InitStack(int max_elems)
{
    Stack s = (Stack)malloc(sizeof(Stackinfo));
    s->Stackelems = (elemtype *)malloc(sizeof(elemtype) * max_elems);
    s->top_index = -1;
    s->max_elems = max_elems;
    return s;
}
int isfull(Stack s)
{
    if (s->top_index == s->max_elems - 1)
    {
        return 1;
    }
    return 0;
}
int isempty(Stack s)
{
    if (s->top_index == -1)
    {
        return 1;
    }
    return 0;
}
void Push(Stack s, elemtype e)
{

    s->Stackelems[++(s->top_index)] = e;

}
elemtype Pop(Stack s)
{

    return s->Stackelems[(s->top_index)--];

}
elemtype Top(Stack s)
{
    return s->Stackelems[s->top_index];
    
}
int isPalindrome(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    Stack s = InitStack(len);
    int i;
    for (i = 0; i < len / 2; i++)
    {
        Push(s, str[i]);
    }
    int j;
    if (len % 2 == 0)
    {
        for (j = i; j < len; j++)
        {
            if (str[j] != Pop(s))
            {
                return 0;
            }
        }
    }
    else
    {
        for (j = i + 1; j < len; j++)
        {
            if (str[j] != Pop(s))
            {
                return 0;
            }
        }
    }
    return 1;
}
int isLeftBracket(char c)
{
    if (c == '(' || c == '{' || c == '[')
    {
        return 1;
    }
    return 0;
}
int isRightBracket(char c)
{
    if (c == ')' || c == '}' || c == ']')
    {
        return 1;
    }
    return 0;
}
int isMatch(char c1, char c2)
{
    if (c1 == ')' && c2 == '(')
    {
        return 1;
    }
    else if (c1 == '}' && c2 == '{')
    {
        return 1;
    }
    else if (c1 == ']' && c2 == '[')
    {
        return 1;
    }
    return 0;
}
int isBalanced(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    Stack s;
    s = InitStack(len);
    int count_brackets = 0;
    for (int i = 0; i < len; i++)
    {
        if (isLeftBracket(str[i]))
        {
            Push(s, str[i]);
            count_brackets++;
        }
        else if (isRightBracket(str[i]))
        {
            if (isempty(s))
            {
                return 0;
            }
            if (!isMatch(str[i], Top(s)))
            {
                return 0;
            }
            Pop(s);
        }
    }
    if (count_brackets == 0)
    {
        free(s);
        return 0;
    }
    if (isempty(s))
    {
        free(s);
        return 1;
    }
    free(s);
    return 0;
}