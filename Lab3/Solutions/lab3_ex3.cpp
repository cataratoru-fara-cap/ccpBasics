#include<iostream>
#include "mystack.h"

using namespace std;
int main()
{
    Stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.displayElements();
    cout<<endl<<s.isEmpty()<<endl;
    cout<<s.peek()<<endl;
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    cout<<s.isEmpty();


    return 0;
}
