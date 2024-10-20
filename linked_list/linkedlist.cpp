#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    void insert(int value) {
        Node* newnode = new Node(); 
        newnode->val = value;
        newnode->next = nullptr;

        if (head == nullptr) {
            head = newnode;
        } else {
            Node* curr = head;
            while (curr->next) {
                curr = curr->next;
            }
            curr->next = newnode;
        }
    }

    void deleteNode(Node* node) {
        if (head == nullptr || node == nullptr) return;

        if (head == node) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* curr = head;
        Node* pre = nullptr;

        while (curr != nullptr && curr != node) {
            pre = curr;
            curr = curr->next;
        }

        if (curr == nullptr) return;
        pre->next = curr->next;
        delete curr;
    }

    void display() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->val << " -> ";
            curr = curr->next;
        }
        cout << "nullptr" << endl;
    }
};

int main() {
    LinkedList list;
    list.insert(5);
    list.insert(10);
    list.insert(15);

    cout << "Original list: ";
    list.display();

    // Let's delete the second node (value 10)
    Node* nodeToDelete = list.head->next;
    list.deleteNode(nodeToDelete);

    cout << "After deleting node with value 10: ";
    list.display();

    return 0;
}
