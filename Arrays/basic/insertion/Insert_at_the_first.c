#include <stdio.h>

int main(){
      int i, item, size, arr[100];
      scanf("%d", &size);
      scanf("%d", &item);
      for(i = 0; i < size; i++){
            scanf("%d", &arr[i]);
      }
      size++;
      for (i=size; i>1; i--){
            arr[i-1] = arr[i-2];
      }
      arr[0]=item;
      for(i = 0; i<size;i++){
            printf("%d ", arr[i]);
      }
      return 0;
}