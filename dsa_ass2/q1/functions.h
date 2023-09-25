#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
typedef char elemtype;
typedef struct Stackinfo *Stack;
typedef struct Stackinfo
{
    int max_elems;
    int top_index;
    elemtype *Stackelems;
} Stackinfo;

Stack InitStack(int max_elems);
int isfull(Stack s);
int isempty(Stack s);
void Push(Stack s, elemtype e);
elemtype Pop(Stack s);
elemtype Top(Stack s);
int isPalindrome(char *str);
int isLeftBracket(char c);
int isRightBracket(char c);
int isBalanced(char *str);
#endif