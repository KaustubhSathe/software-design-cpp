#include<bits/stdc++.h>

using namespace std;

int main(){
    // assign using constructor
    vector<int> arr(100, 100);

    // initialize using for loop
    for(int i = 0;i<100;i++){
        arr[i] = i + 1;
    } 
    
    // iterate through using for auto x: vector notation
    for(auto x : arr){
        cout<<x<<endl;
    }
    // iterate 


    return 0;
}