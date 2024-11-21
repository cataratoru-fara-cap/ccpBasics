#include "/home/lupulcelbun/Programing/Cpp/Lab3/mystack.h"
//imported stack from previous lab

using namespace std;

template <typename T> class StackedQueue {
private:
    
public:
    Stack <T> s1, s2;
    void enqueue(T x){
        s1.push();
    }
    T dequeue(){
        while (!s1.isEmpty())
        {
            s2.push(s1.pop);
        }
        
        T x = s2.pop();

        while(!s2.isEmpty()){
            s1.push(s2.pop());
        }

        return x;
    }

    StackedQueue(){}
    ~StackedQueue(){}
};

int main(int argc, char const *argv[])
{
    return 0;
}
