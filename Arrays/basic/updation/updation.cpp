#include <bits/stdc++.h>
using namespace std;

void replace_at(int arr[], int n, int pos, int val){
      if(pos < 1 || pos > n){
            cout<<"Invalid Entry"<<endl;
            return;
      }
      arr[pos - 1] = val;
      
}
void coutA(int arr[], int n){
      for(int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
      }
      cout<<"\n";

}

int main(){
      int arr[] = {10,20,30,40,50};
      int n = sizeof(arr) / sizeof(arr[0]);
      int pos, val;
      cout<<"Enter Pos and Value: ";
      cin>>pos>> val;
      coutA(arr, n);
      replace_at(arr, n, pos, val);
      coutA(arr, n);
      return 0;
}