#include <iostream>
using namespace std;
void swap(int* a, int *b){
      int temp = *a;
      *a = *b;
      *b = temp;
}
void printArr(int arr[], int n){
      cout<<"[ ";
      for (int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
            
      }
      cout<<"] "<<endl;
}

int main(){
      int myArr[] = {9,8,7,6,5,4,3,2,1};
      int size = sizeof(myArr)/sizeof(myArr[0]);
      printArr(myArr, size);
      printArr(myArr, size);
      return 0;
}