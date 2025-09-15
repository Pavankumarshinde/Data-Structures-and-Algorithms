#include <iostream>
#include <vector>
using namespace std;

class stack
{
public:
    int capacity;
    int t;    // index of next empty slot
    int size; // current size
    vector<int> arr;

    stack(int capacity)
    {
        arr = vector<int>(capacity);
        t = 0;
        size = 0;
        this->capacity = capacity;
    }

    bool push(int a)
    {
        if (size == capacity)
            return false; // full
        arr[t] = a;
        t++;
        size++;
        return true;
    }

    bool pop()
    {
        if (size == 0)
            return false; // empty
        t--;
        size--;
        return true;
    }

    int top()
    {
        if (size == 0)
        {
            cout << "empty stack" << endl;
            return -1;
        }
        return arr[t - 1];
    }

    void print()
    {
        cout << "Stack: ";
        if (size == 0)
        {
            cout << "empty\n";
            return;
        }
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};
int main()
{
    stack stk(5);

    // Push elements
    cout << stk.push(10) << endl; // true (1)
    cout << stk.push(20) << endl; // true (1)
    cout << stk.push(30) << endl; // true (1)

    stk.print(); // 10 20 30

    // Top element
    cout << "Top: " << stk.top() << endl; // 30

    // Pop element
    cout << stk.pop() << endl; // true (1)
    stk.print();               // 10 20

    // Push more
    stk.push(40);
    stk.push(50);
    stk.push(60);                 // should succeed
    cout << stk.push(70) << endl; // false (0, full)

    stk.print(); // 10 20 40 50 60

    // Empty stack completely
    while (stk.pop())
        ;
    stk.print(); // empty

    cout << "Top after empty: " << stk.top() << endl; // prints "empty stack"
    return 0;
}
