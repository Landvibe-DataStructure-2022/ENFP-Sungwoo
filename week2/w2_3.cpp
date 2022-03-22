#include <iostream>
#include <string>
using namespace std;

struct Node{
    int data;
    Node* next;
};

int L_size;
int m;
Node* head = new Node();
Node* tail = new Node();

void Print() {
    if(L_size == 0)
    {
        cout<<"empty\n";
    }
    else {
        Node *cur = head->next;
        while (cur != tail) {
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << "\n";
    }
}

void Append(int data)
{
    Node* cur = head;
    while(cur->next != tail)
        cur = cur->next;

    Node* newNode = new Node();
    newNode->data = data;

    newNode->next = tail;
    cur->next = newNode;

    L_size++;
    Print();
}

int Delete(int index)
{
    if(L_size==0 || L_size <= index)
    {
        return -1;
    }
    else
    {
        Node* cur = head;

        for(int i=0;i<index;i++)
            cur = cur->next;

        int data = cur->next->data;
        cur->next = cur->next->next;

        L_size--;
        return data;
    }
}

void Min(){
    Node* cur = head->next;
    if(L_size == 0){
        cout<<"empty"<<endl;
    }
    else if(L_size == 1){
        cout<<cur->data;
    }
    else {
        int min = 0;
        min=cur->data;
        while (cur->next != tail) {
            if(min>(cur->next->data)){
                min=cur->next->data;
            }
            cur=cur->next;
        }
        cout<<min<<endl;
    }
}

void Insert(int index,int data)
{
    if(index > L_size)
    {
        cout<<"Index Error\n";
    }
    else
    {
        Node* cur = head;
        for(int i=0;i<index;i++)
            cur = cur->next;

        Node* newNode = new Node();
        newNode->data = data;

        newNode->next = cur->next;
        cur->next = newNode;

        L_size++;
        Print();
    }
}

int main(){
    cin>>m;
    head->next = tail;
    while(m--)
    {
        string cmd;
        cin>>cmd;

        if(cmd=="Print")
        {
            Print();
        }
        else if(cmd=="Append")
        {
            int data;
            cin>>data;
            Append(data);
        }
        else if(cmd=="Delete")
        {
            int index;
            cin>>index;
            cout<<Delete(index)<<"\n";
        }
        else if(cmd=="Insert")
        {
            int index,data; cin>>index>>data;
            Insert(index,data);
        }
        else if(cmd=="Min")
        {
            Min();
        }
    }
}