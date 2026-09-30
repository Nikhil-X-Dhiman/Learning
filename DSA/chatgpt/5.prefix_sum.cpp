#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

void longestSubarrayWithSumK(const vector<int>& arr, int k);
void countNumberOfSubarraysWithSumK(const vector<int>& arr, int k);

int main(){

  {
    // vector<int> arr={1, 2, 3, 1, 1, 1, 1, 4, 2, 3};
    vector<int> arr = {1, 2, 1, 2};
    // longestSubarrayWithSumK(arr, 3);
    countNumberOfSubarraysWithSumK(arr, 3);
  }
  return 0;
}

void longestSubarrayWithSumK(const vector<int>& arr, int k){
  unordered_map<int, int> prefixSumArray;
  int sum=0, longestLength=0;
  for (int i = 0; i < arr.size(); i++)
  {
    sum+=arr[i];
    if (sum==k)
    {
      longestLength=max(longestLength, i+1);
    }
    int rem = sum-k;
    if (prefixSumArray.find(sum) == prefixSumArray.end())
    {
      prefixSumArray[sum] = i;
    }
    if (prefixSumArray.find(rem) != prefixSumArray.end())
    {
      int len = i-prefixSumArray[rem];
      longestLength=max(longestLength, len);
    }

  }
  cout<<"Longest: "<<longestLength<<endl;
  return;
}

// Count the number of subarrays whose sum equals k (do this again i didn't understood it for now)
void countNumberOfSubarraysWithSumK(const vector<int>& arr, int k){
  unordered_map<int, int> freq;

  freq[0] = 1;

  int prefixSum = 0;
  int count = 0;

  for (int x : arr) {
      prefixSum += x;

      int needed = prefixSum - k;

      if (freq.count(needed)) {
          count += freq[needed];
      }

      freq[prefixSum]++;
  }
  cout<<"Count Subarrays: "<<count<<endl;
  return;
}
