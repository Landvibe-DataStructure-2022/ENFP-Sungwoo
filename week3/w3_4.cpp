#include<iostream>
#include<string>

using namespace std;

class arrayStack{
private:
    int arr[100]={};
    int topIndex;
public:
    arrayStack() {
        topIndex=-1;
    }

    bool empty() {
        if(topIndex==-1){
            return true;
        }
        else{
            return false;
        }
    }

    void top() {
        if(empty()){
            cout<<"-1\n";
        }
        else {
            cout << arr[topIndex] << "\n";
        }
    }

    void push(int x){
        arr[topIndex+1]=x;
        topIndex++;
    }

    int pop() {
        topIndex--;
        return arr[topIndex + 1];
    }
};


int main(){
    int t;
    int a,b;
    cin>>t;
    string p;

    arrayStack* st = new arrayStack();

    while(t--){
        cin>>p;
        for(int i = 0; i<p.length();i++){
            if(p[i]=='+'){
                a=st->pop();
                b=st->pop();
                st->push(b+a);
            }
            else if(p[i]=='-'){
                a=st->pop();
                b=st->pop();
                st->push(b-a);
            }
            else if(p[i]=='*'){
                a=st->pop();
                b=st->pop();
                st->push(b*a);
            }
            else{
                st->push(p[i]-'0');
            }
        }
        st->top();
    }
    return 0;
}