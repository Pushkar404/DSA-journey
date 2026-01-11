#include <stdio.h>
void outputArray(int arr[], int size){
      printf("Elements of Array: \n");
      for (int i = 0; i<size;i++){
            printf("%d ", arr[i]);
      }
      printf("\n");
}
void deletionPos(int arr[], int *size, int pos){
      for (int i = 0; i<*size-1; i++){
            arr[i]=arr[i+1];
      }
      (*size)--;
}
int main(){
      int arr[] = {10, 20, 30, 40, 50};
      int pos = 2;
      int size = sizeof(arr)/4;

      outputArray(arr, size);
      deletionPos(arr, &size, pos);
      outputArray(arr, size);
      return 0;
}