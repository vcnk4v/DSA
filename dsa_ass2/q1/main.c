#include "functions.h"
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char str[10001];
        scanf("%s", str);
        if (isBalanced(str) && isPalindrome(str))
        {
            printf("Balanced and Palindromic\n");
        }
        else if (isBalanced(str))
        {
            printf("Balanced\n");
        }
        else if (isPalindrome(str))
        {
            printf("Palindromic\n");
        }
        else
        {
            printf("-1\n");
        }
    }
    return 0;
}