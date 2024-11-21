#include "liste1.h"
#include <iostream>

int main()
{
    LinkedList <int> my_list;
    my_list.addFirst(1);
    my_list.addFirst(5);
    my_list.addFirst(3);
    my_list.addLast(2);
    my_list.addLast(1);
    my_list.addLast(14);
    my_list.addLast(10);

    my_list.splitList();
    return 0;
}
