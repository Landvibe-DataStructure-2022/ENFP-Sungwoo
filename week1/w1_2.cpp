#include<iostream>
#include<string>

using namespace std;

int arr[10001];
int arrSize;

void right(int x){
    int temp;
    while(x--){
        temp=arr[arrSize-1];
        for(int i = arrSize-2;i>=0;i--){
            arr[i+1]=arr[i];
        }
        arr[0]=temp;
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

        right(d);

        print();
    }
    return 0;
}
