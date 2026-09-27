#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void traverse_arr_end(const vector<int>& arr, int end);
void two_sum(const vector<int>& arr, int target);
void remove_duplicates(vector<int>& arr);

int main(){

  {
    vector<int> arr = {1, 3, 4, 6, 8, 11, 15};
    int target = 14;
    two_sum(arr, target);
  }
  {
    vector<int> arr = {1, 1, 2, 2, 3, 4, 4};
    remove_duplicates(arr);
  }

  return 0;
}

void traverse_arr_end(const vector<int>& arr, int end){
  for (int i = 0; i < end; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return;
}

// Find whether a sorted array contains two numbers whose sum equals a target.
void two_sum(const vector<int>& arr, int target){
  int i=0, j=arr.size()-1;
  while (i<j)
  {
    int sum=arr[i]+arr[j];
    if (sum==target)
    {
      cout<<arr[i]<<" "<<arr[j]<<endl;
      return;
    }else if (sum>target)
    {
      j--;
    }else
    {
      i++;
    }



  }
  return;
}

// Remove duplicates from a sorted array in-place. || also use uuper_bound & lower_bound for efficiency
void remove_duplicates(vector<int>& arr){
  int fast=0, slow=0;
  while (fast<arr.size())
  {
    if (arr[slow]==arr[fast])
    {
      fast++;
    }else
    {
      slow++;
      arr[slow]=arr[fast];
      fast++;
    }
  }
  traverse_arr_end(arr, slow+1);
  return;
}
