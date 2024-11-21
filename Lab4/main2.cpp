#include <iostream>
#include "queue1.h"

int main() {
    Queue <char>q;

    q.enqueue('A');
    q.enqueue('F');
    q.enqueue('H');
    q.enqueue('S');
    q.enqueue('L');

    cout << "Dequeue: " << q.dequeue() << endl;
    cout << "Head: " << q.getHead() << endl;
    cout << "Tail: " << q.getTail() << endl;
    cout << "Peek: " << q.peek() << endl;
    cout << "IsEmpty: " << q.isEmpty() << endl;
    
    q.enqueue('X');
    cout << "Head: " << q.getHead() << endl;
    cout << "Tail: " << q.getTail() << endl;
    
    return 0;
}