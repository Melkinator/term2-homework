#include <iostream>
#include <vector>
#include <random>
#include <string>
using namespace std;

class Node {
    public:
        int data;
        string name;
        int score;        
        Node *left;
        Node *right;

        Node(int x, string d, int y): data(x), name(d), score(y), left(nullptr), right(nullptr) {}
};
    
random_device rd;
mt19937 gen(rd());
uniform_int_distribution<> distrib(1, 100);

int getScore() {
    return distrib(gen);
}

bool search(Node *root, int num) {
    if (root==nullptr) return false;

    if (root->data==num) return true;
    if (num>root->data) {
        return search(root->right, num);
    } else {
        return search(root->left, num);
    }
}

Node *insert(Node *root, int num, string name, int score) {
    if (root==nullptr) return new Node(num, name, score);

    if (search(root, num)) throw runtime_error("you already have the same number");

    if (num<root->data) {
        root->left = insert(root->left, num, name, score);
    } else {
        root->right = insert(root->right, num, name, score);
    }
    return root;
}

void inOrder(Node *root, vector<Node *>&res) {
    if (root==nullptr) return;

    inOrder(root->left, res);
    res.push_back(root);
    inOrder(root->right, res);
}

void printInOrder(Node *root) {
    vector<Node*> res;
    inOrder(root, res);

    for (Node *n:res) {
        cout << n->data << " (" << n->name << ")";
    }
}

vector<Node *> makeBracket(const vector<Node *>&sorted) {
    vector<Node *> bracket;
    int i=0;
    int j= (int)sorted.size() - 1;
    while (i<=j) {
        if (i==j) {
            bracket.push_back(sorted[i++]);
        } else {
            bracket.push_back(sorted[i++]); // top seed
            bracket.push_back(sorted[j--]); // bottom seed
        }
    }
    return bracket;
}

void printBracket(vector<Node *>players) {
    if (players.empty()) return;
    int round = 1;
    while (players.size()>1) {
        cout << "Round " << round << "\n";
        vector<Node *> next;
        for (int i=0;i<players.size();i+=2) {
            if (i+1<players.size()) {
                Node *a = players[i];
                Node *b = players[i+1];
                cout << " Match " << (i/2+1) << ": " << a->name << " (seed " << a->data << ") Score: " << a->score << " vs " << b->name << " (seed " << b->data << ") Score: " << b->score << "\n";
                Node *winner = (a->score >= b->score) ? a : b;
                next.push_back(winner);
            } else {
                Node *a = players[i];
                cout << " Cya: " << a->name << " (seed " << a->data << ")\n";
                next.push_back(a);
            }
        }
        cout << "\n";
        players.swap(next);
        round++;
    }
    cout << "Winner: " << players.front()->name << " (seed " << players.front()->data << ")\n"; 
}

int main() {
    Node *bst = nullptr;
    bst = insert(bst, 21, "brother", getScore());
    bst = insert(bst, 24, "cuh", getScore());
    bst = insert(bst, 23, "ranald", getScore());
    bst = insert(bst, 22, "john", getScore());
    bst = insert(bst, 25, "john fortnite", getScore());

    cout << "In-order print:\n";
    printInOrder(bst);

    vector<Node *> sorted;
    inOrder(bst, sorted);
    vector<Node *> bracket = makeBracket(sorted);

    cout << "\nTournament Bracket:\n";
    printBracket(bracket);
}