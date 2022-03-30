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
    int size;
public:
    LinkedList(){
        header->data=0;
        trailer->data=0;
        header->next=trailer;
        trailer->prev=header;
        size=0;
    }


    void insert(int e){
        Node* newNode = new Node;
        newNode->data=e;
        newNode->next=trailer;
        trailer->prev->next=newNode;
        newNode->prev=trailer->prev;
        trailer->prev=newNode;
        size++;
    }

    void maxPooling(){
        Node* p = new Node;
        p=header->next;
        while(p!=trailer) {
            int a=p->data;
            int b=p->prev->data;
            int c=p->next->data;
            if (a > b) {
                if (a > c) {
                    cout<<a<<" ";
                } else {
                    cout<<c<<" ";
                }
            } else {
                if (b > c) {
                    cout<<b<<" ";
                } else {
                    cout<<c<<" ";
                }
            }
            p=p->next;
        }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        LinkedList* dli = new LinkedList;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            dli->insert(a);
        }
        dli->maxPooling();
        cout<<"\n";
    }
    return 0;
}