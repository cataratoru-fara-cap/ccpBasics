#include "queue1.h"

int main(int argc, char const *argv[])
{
    Queue <char> myQueue;
    myQueue.enqueue('A');
    myQueue.enqueue('F');
    myQueue.enqueue('H');
    myQueue.enqueue('S');
    myQueue.enqueue('L');
    cout << myQueue.dequeue();
    cout << myQueue.dequeue();
    cout << myQueue.dequeue();
    cout << myQueue.dequeue();


    cout << "\n";
    cout << "\n";
    return 0;
}
