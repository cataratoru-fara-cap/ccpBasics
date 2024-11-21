#include "mystack.h"
using namespace std;

int main(){
    Stack <int> s;
    s.push(0);
    cout << s.peek();
    s.push(4);
    s.displayElements();
    cout << s.getTopLevel();
    s.pop();
    cout << s.isEmpty();
    s.pop();
    cout << s.isEmpty();
    s.~Stack();

    cout << "\n";
    int n;
    double d;
    cin >> n;
    Stack <double> other_stack;
    for (int i = 0; i < n; i++)
    {
        cin >> d;
        other_stack.push(d);
    }
    for (int i = 0; i < n; i++)
    {
        cout << other_stack.pop();
    }
    
    
    return 0;
}
