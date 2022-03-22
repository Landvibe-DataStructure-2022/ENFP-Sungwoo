#include<iostream>
#include<string>

using namespace std;

class arrayStack{
private:
    int arr[10];
    int arrSize;
    int topIndex;
public:
    arrayStack(int x);
    bool empty();
    void top();
    void push(int x);
    void pop();
};

arrayStack::arrayStack(int x) {
    arrSize=x;
    topIndex=-1;
}

bool arrayStack::empty() {
    if(topIndex == -1){
        return true;
    }
    else{
        return false;
    }
}

void arrayStack::top() {
    if(empty()){
        cout<<"-1\n";
    }
    else{
        cout<<arr[topIndex]<<"\n";
    }
}

void arrayStack::push(int x) {
    if(topIndex+1>=arrSize){
        cout<<"FULL\n";
    }
    else{
        arr[++topIndex]=x;
    }
}

void arrayStack::pop() {
    if(empty()){
        cout<<"-1\n";
    }
    else{
        cout<<arr[topIndex]<<"\n";
        topIndex--;
    }
}

int main(){
    int t,N;
    string cmd;
    cin>>t>>N;
    arrayStack* as = new arrayStack(t);
    while(N--){
        cin>>cmd;
        if(cmd=="empty"){
            if(as->empty()){
                cout<<"1\n";
            }
            else{
                cout<<"0\n";
            }
        }
        else if(cmd=="top"){
            as->top();
        }
        else if(cmd=="push"){
            int x;
            cin>>x;
            as->push(x);
        }
        else if(cmd=="pop"){
            as->pop();
        }
    }

    return 0;
}