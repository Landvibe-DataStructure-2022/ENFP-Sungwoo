#include<iostream>
#include<string>

using namespace std;

class Array{
private:
    int arr[10001];
    int arrSize;
public:
    Array(int N){
        arr[10001]={};
        arrSize=N;
    }

    void at(int i){
        cout<<arr[i]<<"\n";
    }

    void add(int i, int value){
        for(int j=arrSize-1;i<j;j--){
            arr[j]=arr[j-1];
        }
        arr[i]=value;
    }

    void remove(int i){
        for(int k =i+1;k<arrSize;k++){
            arr[k-1]=arr[k];
        }
        arr[arrSize-1]=0;
    }

    void set(int i, int value){
        arr[i]=value;
        cout<<value<<"\n";
    }

    void print(){
        for(int i = 0;i<arrSize;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

    void find_max(){
        int max=arr[0];
        for(int i=0;i<arrSize-1;i++){
            if(max<arr[i+1]){
                max=arr[i+1];
            }
        }
        cout<<max<<"\n";
    }
};

int main(){
    int t,n;
    string s;
    cin>>t>>n;

    Array* arr= new Array(t);

    while(n--){
        cin>>s;
        if(s=="at"){
            int a;
            cin>>a;
            arr->at(a);
        }
        else if(s=="add"){
            int a,b;
            cin>>a>>b;
            arr->add(a,b);
        }
        else if(s=="remove"){
            int a;
            cin>>a;
            arr->remove(a);
        }
        else if(s=="set"){
            int a, b;
            cin>>a>>b;
            arr->set(a,b);
        }
        else if(s=="print"){
            arr->print();
        }
        else if(s=="find_max"){
            arr->find_max();
        }
    }
    return 0;
}