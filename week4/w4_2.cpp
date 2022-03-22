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
    int size;
public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void enqueue(int val){
        Node* newNode = new Node;
        newNode->data=val;
        if(size == 0){
            head=newNode;
            tail=newNode;
        }
        else {
            newNode ->next = nullptr;
            tail->next=newNode;
            tail = newNode;
        }
        size++;
    }

    int dequeue(){
        if(size == 0){
            return -1;
        }
        else if(size == 1){
            int result = head->data;
            head=tail= nullptr;
            size--;
            return result;
        }
        else{
            int result=head->data;
            head=head->next;
            size--;
            return result;
        }
    }
    int front(){
        return head->data;
    }
};

int main(){
    int T,N;
    cin>>T;
    while(T--){
        LinkedList* p1 = new LinkedList;
        LinkedList* p2 = new LinkedList;
        int p1Point=0;
        int p2Point=0;
        int p1p=0;
        int p2p=0;
        cin>>N;
        for(int i = 0;i<N;i++){
            int data;
            cin>>data;
            p1->enqueue(data);
        }
        for(int i = 0;i<N;i++){
            int data;
            cin>>data;
            p2->enqueue(data);
        }
        for(int i = 0;i<N;i++){
            int a,b;
            a=p1->dequeue()+p1p;
            b=p2->dequeue()+p2p;

            if (a > b) {
                p1Point++;
                p1p=a - b;
                p2p=0;
            } else if (a < b) {
                p2Point++;
                p2p=b-a;
                p1p=0;
            }
            else{
                p1p=0;
                p2p=0;
            }
        }
        if(p1Point>p2Point){
            cout<<"1\n";
        }
        else if(p1Point<p2Point){
            cout<<"2\n";
        }
        else if(p1Point==p2Point){
            cout<<"0\n";
        }
    }
    return 0;
}