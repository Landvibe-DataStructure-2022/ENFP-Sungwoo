#include<iostream>
#include<string>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;
};

class LinkedList{
private:
    Node* header = new Node;
    Node* trailer = new Node;
    Node* p = new Node;
    int size;
public:
    LinkedList(){
        header->next=trailer;
        trailer->prev=header;
        p=header;
        size=0;
    }

    void begin(){
        p=header->next;
    }

    void end(){
        p=trailer;
    }

    void insert(int e){
        if(p==header){

        }
        else {
            Node *newNode = new Node;
            newNode->data = e;
            newNode->next = p;
            p->prev->next = newNode;
            newNode->prev = p->prev;
            p->prev = newNode;
            size++;
        }
    }

    void erase(){
        if(p==header){
            cout<<"Empty\n";
        }
        else {
            p->next->prev = p->prev;
            p->prev->next = p->next;
            size--;
            begin();
        }
    }

    void plus(){
        if(p==trailer){

        }
        else {
            p = p->next;
        }
    }

    void minus(){
        if(p==header){

        }
        else {
            p = p->prev;
        }
    }

    void reversePrint(){
        if(size==0){
            cout<<"Empty\n";
        }
        else{
            Node* cur = new Node;
            cur=trailer->prev;
            while(cur != header){
                cout<<cur->data<<" ";
                cur=cur->prev;
            }
            cout<<"\n";
        }
    }

    void find(int e){
        Node* cur = new Node;
        cur = header->next;
        int idx=0;
        if(size==0){
            cout<<"Empty\n";
        }
        else {
            for (int i = 0; i < size; i++) {
                if (cur->data == e) {
                    cout << idx << "\n";
                    break;
                } else {
                    idx++;
                    cur = cur->next;
                }
            }
            if (idx == size) {
                cout<<"-1\n";
            }
        }
    }
};

int main(){
    LinkedList* li = new LinkedList;
    int m;
    cin>>m;
    while(m--){
        string cmd;
        cin>>cmd;
        if(cmd=="find"){
            int a;
            cin>>a;
            li->find(a);
        }
        else if(cmd=="reversePrint"){
            li->reversePrint();
        }
        else if(cmd=="insert"){
            int a;
            cin>>a;
            li->insert(a);
        }
        else if(cmd=="erase"){
            li->erase();
        }
        else if(cmd=="begin"){
            li->begin();
        }
        else if(cmd=="end"){
            li->end();
        }
        else if(cmd=="++"){
            li->plus();
        }
        else if(cmd=="--"){
            li->minus();
        }
    }
    return 0;
}