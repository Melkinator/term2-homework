#include <stdexcept>

#ifndef STACK
#define STACK

using namespace std;

class Stack{
    // complete the Stack ADT here
    private:
        struct Node {
            float data;
            Node *next;
            
            Node(float value): data(value), next(nullptr) {}
        };
        Node *head;
        int count;
    public:
        Stack(): head(nullptr), count(0) {}
        ~Stack() {
            while (!isEmpty()) {
                pop();
            }
        }

        void push(float data) {
            Node *n = new Node(data);
            n->next = head;
            head = n;
            count++;
        }
        
        float pop() {
            if (isEmpty()) throw runtime_error("underflow or something");
            Node *temp = head;
            head = head->next;
            return temp->data;
            delete temp;
            count--;
        }

        float peek() const {
            if (isEmpty()) {
                throw runtime_error("underflow maybe");
            } else {
                return head->data;
            }
        }

        bool isEmpty() const {
            return head==nullptr;
        }
};

#endif
