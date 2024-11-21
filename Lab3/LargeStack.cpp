#include "mystack.h"

template <typename  T>
class LargeStack
{

public:
    Stack <T> Smain, Saux;

    void push(T x){
        Smain.push(x);
    }

    T pop(){
        return Smain.pop();
    }

    void swap(int a, int b){
        Saux = Smain;
        Saux.stackArray[a] = Smain.stackArray[b];
        Saux.stackArray[b] = Smain.stackArray[a];
        Smain = Saux;

        Saux = Stack<T>();
    }
    ~LargeStack(){

    }

};

int main(){
    LargeStack <int> s;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.Smain.displayElements();
    s.Saux.displayElements();
    cout<<endl;
    s.swap(1,2);
    s.Smain.displayElements();

    return 0;
}