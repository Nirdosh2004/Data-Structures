#include<iostream>
using namespace std;

int sequentialSearch(int arr[] , int size , int target){
    int ans = -1;
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            ans = i;
        }
    }
    return ans;
}

int main(){
    
    int size;
    cout<<"Enter size of array : ";
    cin>>size;
    
    int arr[size];
    cout<<"Enter elements of array : \n";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    
    int target;
    cout<<"Enter target : ";
    cin>>target;
    
    cout<<"Answer is : "<<sequentialSearch(arr , size , target);
    
    return 0;
}
