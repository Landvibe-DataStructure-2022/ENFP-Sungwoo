#include<iostream>
#include<string>

using namespace std;

int n;

class Array{
private:
    int arr[10000]{};
    int frt;
    int rr;
    int qSize;
public:
    Array(){
        frt = 0;
        rr=0;
        qSize=0;
    }

    void enqueue(int val){
        if(qSize>=n){
            cout<<"Full\n";
        }
        else{
            arr[rr]=val;
            rr=(rr+1)%10000;
            qSize++;
        }
    }

    void dequeue(){
        if(qSize==0){
            cout<<"Empty\n";
        }
        else{
            cout<<arr[frt]<<"\n";
            frt=(frt+1)%10000;
            qSize--;
        }
    }

    void isEmpty(){
        if(qSize==0){
            cout<<"True\n";
        }
        else{
            cout<<"False\n";
        }
    }

    void size(){
        cout<<qSize<<"\n";
    }

    void front(){
        if(qSize==0){
            cout<<"Empty\n";
        }
        else {
            cout << arr[frt] << "\n";
        }
    }

    void rear(){
        if(qSize==0){
            cout<<"Empty\n";
        }
        else{
            if(rr==0){
                cout<<arr[10000]<<"\n";
            }
            else{
                cout<<arr[rr-1]<<"\n";
            }
        }
    }
};

int main(){
    Array* Queue = new Array;

    int t;
    string cmd;
    cin>>n>>t;
    while(t--){
        cin>>cmd;
        if(cmd=="enqueue"){
            int val;
            cin>>val;
            Queue->enqueue(val);
        }
        else if(cmd=="dequeue"){
            Queue->dequeue();
        }
        else if(cmd=="size"){
            Queue->size();
        }
        else if(cmd=="isEmpty"){
            Queue->isEmpty();
        }
        else if(cmd=="front"){
            Queue->front();
        }
        else if(cmd=="rear"){
            Queue->rear();
        }
    }
    return 0;
}