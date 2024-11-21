#include <iostream>
#include "mystack.h"
using namespace std;

#define NMAX 50
using namespace std;

template<typename T>
class LargeStack {
    private:
        Stack<T> Smain, Saux;;
        int topLevel;

    public:
        void push(T x)
        {

            Smain.push(x);
        }


        T pop()
        {

            return Smain.pop();
        }


        void displayElements()
        {
                Smain.displayElements();
        }


        void swap(int i, int j)
        {
            Saux=Smain;
            Saux.stackArray[i]=Smain.stackArray[j];
            Saux.stackArray[j]=Smain.stackArray[i];
            Smain=Saux;
        }

        ~LargeStack()
        { // destructor
        }
};


int main()
{
   LargeStack <int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.displayElements();
    cout<<endl;
    s.pop();
    s.displayElements();
    cout<<endl;
    s.pop();
    s.pop();
    s.displayElements();
    cout<<endl;

    s.push(1);
    s.push(2);
    s.push(3);
    s.displayElements();
    cout<<endl;
    s.swap(1,2);
    s.displayElements();

    return 0;
}
