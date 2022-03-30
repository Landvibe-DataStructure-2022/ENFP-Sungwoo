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
        trailer->prev = header;
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
        Node* newNode = new Node;
        newNode->data=e;
        if(p==header){
        }
        else{
            newNode->next=p;
            p->prev->next=newNode;
            newNode->prev=p->prev;
            p->prev=newNode;
            size++;
        }
    }

    void erase(){
        if(p==header){
        }
        else{
            if(size==0){
                cout<<"Empty\n";
            }
            else{
                p->next->prev=p->prev;
                p->prev->next=p->next;
                size--;
                begin();
            }

        }

    }

    void plus(){
        if(p==trailer){
        }
        p=p->next;
    }

    void minus(){
        if(p==header){
        }
        else {
            p = p->prev;
        }
    }

    void print(){
        Node* cur = header;
        if(size==0){
            cout<<"Empty\n";
        }
        else {
            for(int i=0;i<size;i++) {
                cur = cur->next;
                cout << cur->data << " ";
            }
            cout << "\n";
        }
    }

    void find(int e){
        Node* cur = header->next;
        int idx=0;
        int result=-1;
        if(size==0){
            cout<<"Empty\n";
        }
        else{
            for(int i=0;i<size;i++){
                if(cur->data==e){
                    result = idx;
                }
                else {
                    cur = cur->next;
                    idx++;
                }
            }
            if(result==-1){
                cout<<"-1\n";
            }
            else{
                cout<<idx<<"\n";
            }
        }
    }
};

int main(){
    LinkedList* li= new LinkedList;
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
        else if(cmd=="print"){
            li->print();
        }
        else if(cmd=="insert"){
            int a;
            cin>>a;
            li->insert(a);
        }
        else if(cmd=="begin"){
            li->begin();
        }
        else if(cmd=="erase"){
            li->erase();
        }
        else if(cmd=="++"){
            li->plus();
        }
        else if(cmd=="--"){
            li->minus();
        }
        else if(cmd=="end"){
            li->end();
        }
    }
    return 0;
}