#include<iostream>
#include<string>

using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;
};

class LinkedList{
private:
    Node* header = new Node;
    Node* trailer = new Node;
public:
    LinkedList(){
        header->data=0;
        trailer->data=0;
        header->next=trailer;
        trailer->prev=header;
    }

    void insert(int e){
        Node* newNode = new Node;
        newNode->data=e;
        newNode->next=trailer;
        trailer->prev->next=newNode;
        newNode->prev= trailer->prev;
        trailer->prev=newNode;
    }

    void print(){
        Node* cur = new Node;
        cur = header->next;
        while(cur!=trailer){
            cout<<cur->data<<" ";
            cur=cur->next;
        }
    }

    void convolution(){
        Node* itr = new Node;
        itr = header->next;
        while(itr!=trailer) {
            cout<<itr->prev->data + (itr->data) * 3 + (itr->next->data)<<" ";
            itr=itr->next;
        }
        cout<<"\n";
    }
};

int main(){
    int t,n;
    cin>>t;
    while(t--){
        LinkedList* li = new LinkedList;
        cin>>n;
        while(n--){
            int x;
            cin>>x;
            li->insert(x);
        }
        li->convolution();

    }
    return 0;
}