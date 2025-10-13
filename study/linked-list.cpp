#include <iostream>

using namespace std;

class LinkedList {
    struct Node {
        int num;
        Node *next;
        Node(int val): num(val), next(nullptr) {}
    };
    Node *head;
    Node *back;
    int size;
    public:
        LinkedList(): head(nullptr), back(nullptr), size(0) {}
        ~LinkedList() {
            Node *cur = head;
            while (cur) {
                Node *del = cur;
                cur = cur->next;
                delete del;
            }
        }
        void insertFront(int val) {
            Node *n = new Node(val);
            n->next = head;
            head = n;
            if (!back) back = n;
            size++;
        }
        void insertBack(int val) {
            Node *n = new Node(val);
            if (!back) {
                head = back = n;
            } else {
                back->next = n;
                back = n;
            }
            size++;
        }
        void pop() {
            if (!head) return;
            Node *temp = head;
            head = head->next;
            if (!head) back = nullptr;
            delete temp;
            size--;
        }
        void print() {
            Node *cur = head;
            while (cur) {
                cout << cur->num << " ";
                cur = cur->next;
            }
            cout << endl;
        }
};

int main() {
    LinkedList list;

    list.insertFront(10);
    list.insertBack(20);
    list.insertFront(30);

    list.pop();

    list.print();
}