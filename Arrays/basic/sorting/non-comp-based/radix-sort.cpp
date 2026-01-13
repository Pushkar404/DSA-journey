#include <iostream>
#include <vector>
using namespace std;
void printArr(vector<int> &arr){
      int n = arr.size();
      cout<<"[ ";
      for (int i = 0; i < n; i++){
            cout<<arr[i]<<" ";
            
      }
      cout<<"] "<<endl;
}

int getMax(vector<int> &arr){
      int n = arr.size();
      int mx = arr[0];
      for(int i = 1; i < n; i++){
            if (arr[i] > mx){
                  mx = arr[i];
            }
      }
      return mx;
}

void countingSort(vector<int> &arr, int exp){
      int n = arr.size();
      vector<int> output(n);
      int count[10] = {0};

      // count occurences of digits
      for(int i = 0; i < n; i++){
            count[(arr[i]/exp) % 10]++;
      }

      // change count[i] so that it contains the actual position
      for(int i = 1; i<10; i++){
            count[i] = count[i] + count[i - 1];
      }

      // build the output array
      for (int i = n - 1; i >=0; i--){
            int digit = (arr[i]/exp) % 10;
            output[count[digit] - 1] = arr[i];
            count[digit]--;
      }


// copy the output array to arr[]
      for(int i = 0; i <n;i++){
            arr[i] = output[i];
      }
}

void radixSort(vector<int> &arr){
      // find the maximum number to know the number of digits
      int maxVal = getMax(arr);

      // do counting sort for every digit
      for(int exp = 1; maxVal/exp > 0; exp=exp*10){
            countingSort(arr, exp);
      }
}
int main(){
      vector<int> myArr = {9,8,7,6,5,4,3,2,1};
      printArr(myArr);
      radixSort(myArr);
      printArr(myArr);
      return 0;
}