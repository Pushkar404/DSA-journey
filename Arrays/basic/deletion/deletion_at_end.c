#include <stdio.h>
void outputArray(int arr[], int size){
      printf("Elements of Array: \n");
      for (int i = 0; i<size;i++){
            printf("%d ", arr[i]);
      }
      printf("\n");
}
int main(){
      int arr[] = {10, 20, 30, 40, 50};
      int pos = 2;
      int size = sizeof(arr)/4;

      outputArray(arr, size);
      size--;
      outputArray(arr, size);
      return 0;
}