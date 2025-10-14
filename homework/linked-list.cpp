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

        void insertMid(int val) {
            if (size<=1) return;
            Node *cur = head;
            for (int i=0;i<(size/2)-1;i++) {
                cur = cur->next;
            }
            Node *n = new Node(val);
            n->next = cur->next;
            cur->next = n;
            size++;
        }

        void popFront() {
            if (!head) return;
            Node *temp = head;
            head = head->next;
            if (!head) back = nullptr;
            delete temp;
            size--;
        }

        void popEnd() {
            if (!head) return;
            if (!head->next) {
                delete head;
                head = back = nullptr;
            } else {
                Node *cur = head;
                while (cur->next->next) cur = cur->next;
                delete cur->next;
                cur->next = nullptr;
                back = cur;
            }
            size--;
        }

        void popMid() {
            if (size<=1) return;
            Node *temp = head;
            Node *prev = nullptr;
            for (int i=0;i<size/2;i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            delete temp;
            size--;
        }

        void swapNodes(int x, int y) {
            if (x==y||size<=1) return;
            Node *prevX = nullptr, *curX = nullptr;
            Node *prevY = nullptr, *curY = nullptr;
            Node *cur = head;
            int count=0;

            while (cur) {
                count++;
                if (count==x) {
                    curX=cur;
                    break;
                }
                prevX=cur;
                cur = cur->next;
            }

            count=0;
            cur = head;

            while (cur) {
                count++;
                if (count==y) {
                    curY=cur;
                    break;
                }
                prevY=cur;
                cur=cur->next;
            }
            count=0;

            if (!curX||!curY) return;

            if (prevX) {
                prevX->next = curY;
            } else {
                head = curY;
            }

            if (prevY) {
                prevY->next = curX;
            } else {
                head = curX;
            }

            Node *temp = curY->next;
            curY->next = curX->next;
            curX->next = temp;
        }

        bool search(int val) {
            Node *cur = head;
            while (cur) {
                if (cur->num == val) return true;
                cur = cur->next;
            }
            return false;
        }

        void print() {
            if (size==0) return;
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
    list.insertFront(20);
    list.insertFront(40);
    list.insertFront(50);
    list.insertMid(30);
    list.swapNodes(2,4);
    

    list.print();
}