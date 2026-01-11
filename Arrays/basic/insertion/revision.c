#include <stdio.h>
void inputArray(int arr[], int size){
      printf("Enter elements of Array:\n");
      for (int i = 0; i < size; i++){
            scanf("%d", &arr[i]);
      }
}
void outputArray(int arr[], int size){
      printf("Elements of Array: \n");
      for (int i = 0; i<size;i++){
            printf("%d ", arr[i]);
      }
      printf("\n");
}
void insertAtPos(int arr[], int *size, int pos, int item){
      // size++;
      // for (int i=size; i>pos; i--){
      //       arr[i-1]=arr[i-2];
      // }
      for (int i=*size-1; i>=pos - 1; i--){
            arr[i+1]=arr[i];
      }
      arr[pos-1]=item;
      (*size)++;
}
int main(){
      int i, item, pos, arr[100], size;
      item = 99, pos = 3, size = 5;
      inputArray(arr, size);
      // outputArray(arr, size);
      insertAtPos(arr, &size, pos, item);
      outputArray(arr, size);
      return 0;

}