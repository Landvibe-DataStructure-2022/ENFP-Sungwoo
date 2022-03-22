#include<iostream>
#include<string>

using namespace std;

int arr[10001];
int arrSize;

void left(int x){
    int temp;
    while(x--){
        temp=arr[0];
        for(int i = 0; i<arrSize-1;i++){
            arr[i]=arr[i+1];
        }
        arr[arrSize-1]=temp;
    }
}

void print(){
    for(int i = 0; i<arrSize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,d;
        cin>>n>>d;
        arrSize=n;


        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }

        left(d);

        print();
    }
    return 0;
}
