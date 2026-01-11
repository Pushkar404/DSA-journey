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

void bubbleSort(int arr[], int n){
      for(int i = 0; i < n - 1; i++){
            bool swapped = false;
            for(int j = 0; j < n - i - 1; j++){
                  if(arr[j]>arr[j+1]){
                        swap(&arr[j], &arr[j+1]);
                  }
            }
      }
}
void selectionSort(int arr[], int n){
      for(int i = 0; i<n-1; i++){
            int min = i;
            for(int j = i + 1; j<n; j++){
                  if(arr[j]<arr[min]){
                        min = j;
                  }
            }
            if (min != i){
                  swap(&arr[i], &arr[min]);
            }
      }
}
void insertionSort(int arr[], int n){
      for (int i = 1; i < n; i++){
            int key = arr[i];
            int j = i - 1;
            while(j>=0 && arr[j]>key){
                  arr[j+1] = arr[j];
                  j--;
            }
            arr[j+1]=key;
      }
}
int main(){
      int myArr[] = {9,8,7,6,5,4,3,2,1};
      int size = sizeof(myArr)/sizeof(myArr[0]);
      printArr(myArr, size);
      // bubbleSort(myArr, size);
      // selectionSort(myArr, size);
      // insertionSort(myArr, size);
      printArr(myArr, size);
      return 0;
}