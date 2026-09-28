#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void max_sum(const vector<int>& arr, int k);
void var_max_sum(const vector<int>& arr, int target);

int main(){

  {
    // vector<int> arr = {4, 2, 1, 7, 8, 1, 2};
    vector<int> arr = {4, 2, 1, 7, 8, 1, 2};
    max_sum(arr, 3);
  }
  {
    vector<int> arr = {2, 3, 1, 2, 4, 3};
    int target = 7;
    var_max_sum(arr, target);
  }
  return 0;
}

// fixed sliding window: maximum sum of a subarray of fixed size k
void max_sum(const vector<int>& arr, int k){
  int sum=0, result=0;
  // build first window
  for (int i = 0; i < k; i++)
  {
    sum+=arr[i];
  }
  result=sum;
  // process remaining window one by one
  for (int i = k; i < arr.size(); i++)
  {
    sum+=arr[i];  // add new element
    sum-=arr[i-k];  // remove old element
    result = max(sum, result);
  }
  cout<<"Max Sum: "<<result<<endl;
  return;
}

// variable sliding window: Find the smallest contiguous subarray whose sum is at least
void var_max_sum(const vector<int>& arr, int target){
  int left=0, right=0, windowSum=0, total=__INT_MAX__;

  for (int right = 0; right < arr.size(); right++)
  {
    windowSum+=arr[right];
    while (windowSum>=target)
    {
      total=min(total, right-left+1);
      windowSum-=arr[left];
      left++;
    }
  }


  cout<<"Min Total Array Length: "<<(total == __INT_MAX__? 0 : total)<<endl;
  return;
}
