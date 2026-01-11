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

void bubbleSort(int arr[], int n){
      for (int i = 0; i < n - 1; i++){
            bool swapped = false;
            for (int j = 0; j < n - 1 - i; j++){
                  if(arr[j]>arr[j+1]){
                        swap(&arr[j], &arr[j+1]);
                        swapped = true;
                  }
            }
            if (swapped == false) break;

      }
}

void selectionSort(int arr[], int n){
      for (int i = 0; i < n - 1; i++){
            int min = i;
            for (int j = i+1; j < n; j++){
                  if(arr[j]<arr[min]){
                        min = j;                        
                  }
            }
            if (min != i){
                  swap(&arr[i],&arr[min]);

            }
      }
}

void insertionSort(int arr[], int n){
      for(int i = 1; i < n; i++){
            int key  = arr[i];
            int j = i - 1;
            while(j>=0 && arr[j] > key){
                  arr[j+1]=arr[j];
                  j--;
            }
            arr[j+1] = key;
      }
}
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right){
      if (left>=right) return;
      int mid = left + (right-left)/2;
      mergeSort(arr, left, mid);
      mergeSort(arr, mid+1, right);

      merge(arr, left, mid, right);

}
void merge(int arr[], int left, int mid, int right){
      int n1 = mid - left + 1;
      int n2 = right - mid;
      vector<int> L(n1), R(n2);
      for (int i = 0; i < n1; i++){
            L[i] = arr[left + i];
      }
      for (int j = 0; j < n2; j++){
            R[j] = arr[mid+1+j];
      }
      int i = 0, j = 0, k = left;
      while(i<n1 && j<n2){
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
            arr[k] = L[i];
            i++; k++;
      }
      while(j<n2){
            arr[k] = R[j];
            j++; k++;
      }
}

int partition(int arr[], int left, int right){
      int pivot = arr[left];
      int start = left, end = right;

      while (start<end){
            while (start <= right && arr[start] <= pivot) start++;
            while (arr[end] > pivot) end--;

            if (start < end) swap(&arr[start], &arr[end]);



      }
      swap(&arr[left], &arr[end]);

      return end;
}

void quickSort(int arr[], int left, int right){
      if (left>right) return;
      int loc = partition(arr, left, right);
      quickSort(arr, left, loc - 1);
      quickSort(arr, loc + 1, right);
}


void heapify(int arr[], int n, int i){
      int largest = i;
      int left = 2*i + 1; // Left Index
      int right = 2*i + 2; // Right Index
      // If left child is larger than root
      if (left<n && arr[left]>arr[largest]) largest = left;
      // If right child is larger than root
      if (right<n && arr[right]>arr[largest]) largest = right;

      // If largest is not root
      if (largest != i){
            swap(&arr[i], &arr[largest]);
            // Recursively Heapify
            heapify(arr, n, largest);
      }
}


void heapSort(int arr[], int n){

      // Build heap (rearrange vector)
      for (int i = (n/2)-1; i>=0; i--) 
            heapify(arr, n, i);
      // one by one extract an element from heap
      for(int i = n - 1; i > 0; i--){
            swap(&arr[0], &arr[i]);
            heapify(arr, i, 0);
      }
}


int main(){
      int myArray[] = { 9, 4, 3, 8, 10, 2, 5 };
      
      int size  = sizeof(myArray) / sizeof(myArray[0]);
      printArr(myArray, size);
      // bubbleSort(myArray, size);
      // selectionSort(myArray, size);
      // insertionSort(myArray, size);
      // mergeSort(myArray, 0, size - 1);
      // quickSort(myArray, 0, size - 1);
      heapSort(myArray, size);
      
      printArr(myArray, size);
      return 0;
}