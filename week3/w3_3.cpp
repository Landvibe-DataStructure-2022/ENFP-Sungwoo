#include<iostream>
#include<string>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* head = new Node;
    Node* tail = new Node;
public:
    LinkedList();
    bool empty();
    void top();
    void push(int x);
    void pop();
};

LinkedList::LinkedList() {
    head=tail= nullptr;
}

bool LinkedList::empty() {
    if(head== nullptr && tail == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void LinkedList::top() {
    if(empty()){
        cout<<"-1\n";
    }
    else{
        cout<<head->data<<"\n";
    }
}

void LinkedList::push(int x) {
    Node* newNode = new Node;
    newNode->data=x;
    newNode ->next = head;
    head = newNode;
}

void LinkedList::pop() {
    if(empty()){
        cout<<"-1\n";
    }
    else {
        cout << head->data << "\n";
        head = head->next;
    }
}

int main(){
    int N;
    string cmd;
    cin>>N;

    LinkedList* stack = new LinkedList;

    while(N--){
        cin>>cmd;
        if(cmd=="empty"){
            if(stack->empty()){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
        else if(cmd=="top"){
            stack->top();
        }
        else if(cmd=="push"){
            int x;
            cin>>x;
            stack->push(x);
        }
        else if(cmd=="pop"){
            stack->pop();
        }
    }
    return 0;
}