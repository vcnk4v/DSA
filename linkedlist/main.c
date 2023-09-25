#include "ll.h"
int main()
{
    PtrToNode lst1 = MakeNode(0);
    insert(lst1, 0, 1);
    insert(lst1, 0, 2);
    insert(lst1, 0, 3);
    insert(lst1, 0, 4);
    insert(lst1, 0, 5);
    insert(lst1, 0, 6);
    insert(lst1, 0, 7);
    insert(lst1, 0, 8);
    print_clist(lst1);

    PtrToNode lst2 = MakeNode(0);
    insert(lst2, 0, 9);
    insert(lst2, 0, 10);
    insert(lst2, 0, 11);
    insert(lst2, 0, 12);

    print_clist(lst2);
    printf("\n");

    PtrToNode new = rec_Interleave(lst1, lst2);
    print_clist(new);
    printf("\n");
    PtrToNode ans = reverse_rec(lst1);
    print_clist(ans);
}
