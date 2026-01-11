#include <stdio.h>

int main(){
      int i, item, size, arr[100], pos;
      scanf("%d", &size);
      scanf("%d", &item);
      scanf("%d", &pos);
      for(i = 0; i < size; i++){
            scanf("%d", &arr[i]);
      }
      size++;
      for (i =size; i>pos; i--){
            arr[i-1]=arr[i-2];
      }
      arr[pos-1]=item;
      for(i = 0; i < size; i++){
            printf("%d ", arr[i]);
      }
      return 0;
}