#include<iostream>
#include "mystack.h"

using namespace std;
int main()
{
    Stack <int> s;
    int n;
    cout<<"Give n:";
    cin>>n;
    cout<<"Give n numbers:";
    for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            s.push(x);
        }

    while(!s.isEmpty())
    {
        cout<<s.pop()<<" ";
    }

    return 0;
}
