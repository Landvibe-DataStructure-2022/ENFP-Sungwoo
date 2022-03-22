#include<iostream>
#include<string>

using namespace std;

struct Node{
    int data;
    Node* next;
};

class LinkedList{
private:
    Node* head;
    Node* tail;
    int n;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
        n =0;
    }

    void enqueue(int val){
        Node* newNode = new Node;
        newNode->data=val;
        if(n == 0){
            head=newNode;
            tail=newNode;
        }
        else {
            newNode ->next = nullptr;
            tail->next=newNode;
            tail = newNode;
        }
        n++;
    }

    void dequeue(){
        if(n == 0){
            cout<<"Empty\n";
        }
        else{
            cout<<head->data<<"\n";
            head=head->next;
            n--;
        }
    }

    void isEmpty(){
        if(n == 0){
            cout<<"True\n";
        }
        else{
            cout<<"False\n";
        }
    }

    void size(){
        cout << n << "\n";
    }

    void front(){
        if(n==0){
            cout<<"Empty\n";
        }
        else{
            cout<<head->data<<"\n";
        }
    }

    void rear(){
        if(n==0){
            cout<<"Empty\n";
        }
        else{
            cout<<tail->data<<"\n";
        }
    }
};

int main(){
    LinkedList* li = new LinkedList;

    string cmd;
    int T;
    cin>>T;
    while(T--){
        cin>>cmd;
        if(cmd=="enqueue"){
            int val;
            cin>>val;
            li->enqueue(val);
        }
        else if(cmd=="dequeue"){
            li->dequeue();
        }
        else if(cmd=="isEmpty"){
            li->isEmpty();
        }
        else if(cmd=="size"){
            li->size();
        }
        else if(cmd=="front"){
            li->front();
        }
        else if(cmd=="rear"){
            li->rear();
        }
    }
    return 0;
}