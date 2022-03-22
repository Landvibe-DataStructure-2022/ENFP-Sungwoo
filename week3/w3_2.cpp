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
    int pop();
};

LinkedList::LinkedList() {
    head=tail= nullptr;
}

bool LinkedList::empty() {
    if(head==nullptr && tail == nullptr){
        return true;
    }
    else{
        return false;
    }
}

void LinkedList::top() {
    cout<<head->data;
}

void LinkedList::push(int x) {
    Node* newNode = new Node;
    newNode->data=x;
    newNode->next=head;
    head=newNode;
}

int LinkedList::pop() {
    int temp = head->data;
    head=head->next;
    return temp;
}

int main(){
    int t;
    cin>>t;
    int a,b;
    string p;
    LinkedList* stack = new LinkedList;
    while(t--){
        cin>>p;
        for(int i = 0;i<p.length();i++){
            if(p[i]=='+'){
                a = stack->pop();
                b = stack->pop();
                stack->push(b+a);
            }
            else if(p[i]=='-'){
                a=stack->pop();
                b=stack->pop();
                stack->push(b-a);
            }
            else if(p[i]=='*'){
                a=stack->pop();
                b=stack->pop();
                stack->push(b*a);
            }
            else{
                stack->push(p[i]-'0');
            }
        }
        cout<<stack->pop()<<"\n";
    }
    return 0;
}