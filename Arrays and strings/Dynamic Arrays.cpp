#include<iostream>
#include<vector>
using namespace std;



int main(){
    
    vector<int> arr;
    arr.push_back(33);
    arr.push_back(44);
    arr.pop_back();
    for(int i=0 ;i<arr.size();i++){
        cout<<arr[i]<<"|    ";
    }
   
    
    return 0;
}
