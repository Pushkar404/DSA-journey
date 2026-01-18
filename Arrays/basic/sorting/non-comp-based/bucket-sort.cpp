#include <bits/stdc++.h>
using namespace std;

void bucketSort(vector<float>&arr){
      int n = arr.size();
      vector<vector<float>> buckets(n);

      for(int i = 0; i < n; i++){
            int idx = n * arr[i];
            buckets[idx].push_back(arr[i]);
      }
      for (int i = 0; i < n; i++)
      {
            sort(buckets[i].begin(), buckets[i].end());

      }
      int index = 0;
      for (int i = 0; i < n; i++)
      {
            for(float val:buckets[i]){
                  arr[index++] = val;
            }
      }
      
      
}

int main() {
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};

    bucketSort(arr);

    for (float x : arr)
        cout << x << " ";

    return 0;
}
