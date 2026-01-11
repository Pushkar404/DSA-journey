#include <stdio.h>

int main(){
      int i, item, size, arr[100];
      scanf("%d", &size);
      scanf("%d", &item);
      for(i = 0; i < size; i++){
            scanf("%d", &arr[i]);
      }
      size++;
      
      arr[size-1]=item;
      for(i = 0; i<size;i++){
            printf("%d ", arr[i]);
      }
      return 0;
}