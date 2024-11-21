#include <iostream>
#include "queue2.h"
//modified NMAX in original header to 3

int main(int argc, char const *argv[])
{
    QueueCirc<char>q;

    cout << "IsEmpty: " << q.isEmpty() << endl;

    q.enqueue('A');
    q.enqueue('F');
    q.enqueue('H');

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Head: " << q.getHead() << endl;
    cout << "Tail: " << q.getTail() << endl;
    cout << "Peek: " << q.peek() << endl;
    
    q.enqueue('X');
    
    cout << "Dequeue: " << q.dequeue() << endl;

    q.enqueue('Y');
    
    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Dequeue: " << q.dequeue() << endl;

    cout << "Head: " << q.getHead() << endl;
    cout << "Tail: " << q.getTail() << endl;
    
    cout << "IsEmpty: " << q.isEmpty() << endl;
    
    return 0;
}
