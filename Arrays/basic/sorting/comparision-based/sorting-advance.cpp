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


void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right){
      if (left >= right) return;
      // int mid = (right + left) / 2;
      int mid = left + (right-left)/2;
      mergeSort(arr, left, mid);
      mergeSort(arr, mid+1, right);

      merge(arr, left, mid, right);
}
void merge(int arr[], int left, int mid, int right){
      int n1 = mid - left + 1; // Left
      int n2 = right - mid; // Right
      vector<int> L(n1), R(n2);
      // Placing elements in L and R
      for (int i = 0; i < n1; i++){
            L[i] = arr[left+i];
      }
      for (int j = 0; j < n2; j++){
            R[j] = arr[mid+1+j];
      }
      int i=0, j = 0, k = left;
      while (i<n1 && j<n2){
            if(L[i]<R[j]){
                  arr[k] = L[i];
                  i++;
            }
            else{
                  arr[k] = R[j];
                  j++;
            }
            k++;
      }

      while(i<n1){
            arr[k]=L[i];
            i++; k++;
      }
      while(j<n2){
            arr[k]=R[j];
            j++; k++;
      }

}
int partition(int arr[], int left, int right){
      int pivot = arr[left];
      int start = left, end = right;

      while (start < end){
            while (start<=right && arr[start]<=pivot) start++;
            while (arr[end]>pivot) end--;

            if (start < end) swap(&arr[start], &arr[end]);
      }
      swap(&arr[left], &arr[end]);

      return end;
}
void quickSort(int arr[], int left, int right){
      if (left<right){
            int loc = partition(arr, left, right);
            quickSort(arr, left, loc - 1);
            quickSort(arr, loc+1, right);
      }
}

void heapify(int arr[], int n, int i){
      int largest = i;
      int left = 2*i + 1;
      int right = 2*i + 2;

      if(left<n && arr[left]>arr[largest]){
            largest = left;
      }

      if(right<n && arr[right]>arr[largest]){
            largest = right;
      }

      if (largest != i){
            swap(&arr[largest], &arr[i]);
            heapify(arr, n, largest);
      }      
}
void heapSort(int arr[], int n){

      for(int i = n/2 - 1; i>=0; i--){
            heapify(arr, n, i);
      }
      for(int i = n - 1; i>=0; i--){
            swap(&arr[0], &arr[i]); // mobe current root to end
            // call max heapify on reduced
            heapify(arr, i, 0);

      }
}


int main(){
      int myArr[] = {9,8,7,6,5,4,3,2,1};
      int size = sizeof(myArr)/sizeof(myArr[0]);
      printArr(myArr, size);
      // mergeSort(myArr, 0, size - 1);
      // quickSort(myArr, 0, size - 1);
      heapSort(myArr, size);
      printArr(myArr, size);
      return 0;
}