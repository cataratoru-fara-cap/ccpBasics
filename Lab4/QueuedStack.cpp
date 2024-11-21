#include "queue2.h"

using namespace std;

template <typename T> class QueuedStack {
private:
    
public:
    QueueCirc <T> q1, q2;
    void push(T x){
        q1.enqueue(x);
    }
    T pop(){
       T x = q1.tail();
       while (q1.peek() != x )
       {
        q2.enqueue(q1.dequeue())
       } 
       q1 = q2;
       q2 = QueueCirc <T>;

       return x;   
    }
    
    int isEmpty(){
        return q1.isEmpty();
    }

    QueuedStack(){}
    ~QueuedStack(){}
};

int main(int argc, char const *argv[])
{
    return 0;
}
