#include <iostream>
#include <vector>
using namespace std;

class deque
{
public:
    int size;
    int rear;
    int front;
    vector<int> arr;
    int capacity;

    deque(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        rear = -1;
        front = 0;
        arr = vector<int>(capacity);
    }

    bool push_front(int a)
    {
        if (size == capacity)
            return false; // full

        front = (front - 1 + capacity) % capacity;
        arr[front] = a;
        size++;
        if (size == 1)
            rear = front; // first element
        return true;
    }

    bool push_back(int a)
    {
        if (size == capacity)
            return false; // full

        rear = (rear + 1) % capacity;
        arr[rear] = a;
        size++;
        if (size == 1)
            front = rear; // first element
        return true;
    }

    bool pop_front()
    {
        if (size == 0)
            return false; // empty
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool pop_back()
    {
        if (size == 0)
            return false; // empty
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int get_front()
    {
        if (size == 0)
            throw runtime_error("Deque is empty");
        return arr[front];
    }

    int get_back()
    {
        if (size == 0)
            throw runtime_error("Deque is empty");
        return arr[rear];
    }

    void print()
    {
        cout << "Deque: ";
        if (size == 0)
        {
            cout << "empty\n";
            return;
        }
        for (int k = 0; k < size; k++)
        {
            cout << arr[(front + k) % capacity] << " ";
        }
        cout << "\n";
    }
};
int main()
{
    deque Deque(5);

    // Push back
    Deque.push_back(10);
    Deque.push_back(20);
    Deque.push_back(30);
    Deque.print(); // 10 20 30

    // Push front
    Deque.push_front(5);
    Deque.push_front(1);
    Deque.print(); // 1 5 10 20 30

    // Try to push when full
    cout << "Push back when full: " << Deque.push_back(40) << "\n"; // false

    // Front and back values
    cout << "Front: " << Deque.get_front() << "\n"; // 1
    cout << "Back: " << Deque.get_back() << "\n";   // 30

    // Pop front
    Deque.pop_front();
    Deque.print(); // 5 10 20 30

    // Pop back
    Deque.pop_back();
    Deque.print(); // 5 10 20

    // Add more
    Deque.push_back(40);
    Deque.push_back(50);
    Deque.print(); // 5 10 20 40 50

    // Empty deque
    while (Deque.pop_front())
        ;
    Deque.print(); // empty

    return 0;
}
