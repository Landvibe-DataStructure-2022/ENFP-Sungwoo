#include<iostream>
#include<string>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

class LinkedList {
private:
    Node *header = new Node;
    Node *trailer = new Node;
    int size;
public:
    LinkedList() {
        header = nullptr;
        trailer = nullptr;
        size = 0;
    }

    ~LinkedList() {
        header = nullptr;
        trailer = nullptr;
        size = 0;
    }

    void Print() {
        if (size == 0) {
            cout << "empty\n";
        } else {
            Node *cur = header;
            while (cur != nullptr) {
                cout << cur->data << " ";
                cur = cur->next;
            }
            cout << "\n";
        }
    }

    void Append(int x) {
        Node *newNode = new Node;
        newNode->data = x;
        if (size == 0) {
            header = newNode;
            trailer = newNode;
            size++;
        } else {
            newNode->next = nullptr;
//            newNode->prev=trailer->prev;
            newNode->prev = trailer;
            trailer->next = newNode;
            trailer = newNode;
            size++;
        }
        Print();
    }

    int Delete(int i) {
        if (i == 0 || i >= size) {
            cout << "-1\n";
            return -1;
        } else if (size == 1) {
            Node *delNode = header;
            header = nullptr;
            trailer = nullptr;
            size--;
            cout << delNode->data << "\n";
            return delNode->data;
        } else {
            Node *delNode = header;
            Node *prevNode = delNode;
            for (int a = 0; a < i; a++) {
                delNode = delNode->next;
            }
            prevNode = delNode->prev;
            prevNode->next = delNode->next;
            delNode->next->prev = prevNode;
            size--;
            cout << delNode->data << "\n";
            return delNode->data;
        }
    }

    void Print_reverse() {
        if (size == 0) {
            cout << "empty\n";
        } else {
            Node *cur = trailer;
            while (cur != nullptr) {
                cout << cur->data << " ";
                cur = cur->prev;
            }
            cout << "\n";
        }
    }

    void Sum() {
        Node *cur = header;
        int sum = 0;
        while (cur != nullptr) {
            sum = sum + cur->data;
            cur = cur->next;
        }
        cout << sum << "\n";
    }
};

int main() {
    LinkedList *li = new LinkedList;
    int M;
    string cmd;
    cin >> M;
    while (M--) {
        cin >> cmd;
        if (cmd == "Print") {
            li->Print();
        } else if (cmd == "Append") {
            int x;
            cin >> x;
            li->Append(x);
        } else if (cmd == "Delete") {
            int i;
            cin >> i;
            li->Delete(i);
        } else if (cmd == "Print_reverse") {
            li->Print_reverse();
        } else if (cmd == "Sum") {
            li->Sum();
        }
    }
    return 0;
}

