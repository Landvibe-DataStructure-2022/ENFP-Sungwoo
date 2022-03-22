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
    Node* head = new Node;
    Node* tail = new Node;
    int L_size;
public:
    LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->L_size=0;
    }

    ~LinkedList(){
        this->head = nullptr;
        this->tail = nullptr;
        this->L_size=0;
    }

    void Print(){
        if(this->L_size == 0){
            cout<<"empty\n";
        }
        else{
            Node* cur = this->head;
            while(cur!= nullptr){
                cout<<cur->data<<" ";
                cur=cur->next;
            }
            cout<<"\n";
        }
    }

    void Append(int x){
        Node* newNode = new Node;
        newNode->data=x;
        if(L_size == 0){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        L_size++;
        this->Print();
    }

    int Delete(int i){
        Node* delNode = head;
        if(L_size <= i){
            return -1;
        }
        else if(i==0){
            if(L_size == 1){
                tail= nullptr;
                head= nullptr;
            }
            else{
                head = delNode->next;
                delNode->next->prev = nullptr;
            }
        }
        else{
            Node* prevNode = head;
            for(int a = 0; a<i;a++){
                prevNode = delNode;
                delNode=delNode->next;
            }
            prevNode->next=delNode->next;
            if(delNode == tail){
                tail = prevNode;
            }
            else{
                delNode->next->prev=prevNode;
            }
        }
        int delValue = delNode->data;
        delete delNode;
        L_size--;
        return delValue;
    }

    void Print_reverse(){
        if(L_size == 0){
            cout<<"empty\n";
        }
        else{
            Node* cur = tail;
            while(cur!= nullptr){
                cout<<cur->data<<" ";
                cur=cur->prev;
            }
            cout<<"\n";
        }
    }

    void Max(){
        if(L_size==0){
            cout<<"empty\n";
        }
        else{
            Node* cur = head;
            int maxValue=cur->data;
            while(cur != nullptr){
                if(maxValue<cur->data){
                    maxValue=cur->data;
                }
                cur=cur->next;
            }
            cout<<maxValue<<"\n";
        }
    }

};

int main(){
    int M;
    cin>>M;
    string cmd;

    LinkedList * dli = new LinkedList;

    while(M--){
        cin>>cmd;
        if(cmd=="Print"){
            dli->Print();
        }
        else if(cmd=="Max"){
            dli->Max();
        }
        else if(cmd=="Delete"){
            int a;
            cin>>a;
            cout<<dli->Delete(a)<<"\n";
        }
        else if(cmd=="Append"){
            int a;
            cin>>a;
            dli->Append(a);
        }
        else if(cmd=="Print_reverse"){
            dli->Print_reverse();
        }

    }

    return 0;
}