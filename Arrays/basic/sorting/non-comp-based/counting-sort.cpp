#include <iostream>
#include <vector>
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

int getMax(int arr[], int n){
      int mx = arr[0];
      for(int i = 1; i < n; i++){
            if (arr[i] > mx){
                  mx = arr[i];
            }
      }
      return mx;
}

void countSort(int a[], int n){
      if (n <= 1) return;

      int maxVal = getMax(a, n);

      // vector<int> Count(maxVal+1, 0);
      int* count = new int[maxVal+1]();

      // frequency count
      for(int i = 0; i < n; i++){
            count[a[i]]++;
      }

      // rebuild sorted array
      int index = 0;
      for(int i = 0; i <= maxVal; i++){
            while (count[i]>0){
                  a[index++] = i;
                  count[i]--;
            }
      }

}

int main(){
      int myArr[] = {9,8,7,6,5,4,3,2,1};
      int size = sizeof(myArr)/sizeof(myArr[0]);

      printArr(myArr, size);
      countSort(myArr, size);
      printArr(myArr, size);
      return 0;
}