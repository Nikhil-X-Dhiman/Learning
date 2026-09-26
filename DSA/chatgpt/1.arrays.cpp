#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool linear_search(const vector<int>& arr, int target);
int binary_search(const vector<int>& arr, int target);
int search_insert(const vector<int>& arr, int target);  // lower_bound
int custom_upper_bound(const vector<int>& arr, int target);
int count_occurrences(const vector<int>& arr, int target);


int main(){

  {
    // // linear search
    // vector<int> arr = {1, 2, 3, 4, 5};
    // cout<<"Elemant Found: "<<linear_search(arr, 4)<<endl;
  }

  {
    // // binary search
    // vector<int> arr = {1, 2, 3, 4, 5, 9};
    // int result = binary_search(arr, 5);
    // if (result>=0)
    // {
    //   cout<<"Elemant Found At: "<<result<<endl;
    // }else
    // {
    //   cout<<"Element Not Found!!!"<<endl;
    // }

    // // using stl functions
    // cout<<"STL Binary Search: "<<std::binary_search(arr.begin(), arr.end(), 3);
  }

  {
    // Problem: Search Insert Position || Lower Bound
    // vector<int> arr = {1, 3, 5, 7};
    // int result = search_insert(arr, 0);
    // cout<<"Search Insert: "<<result<<endl;
  }

  {
    // vector<int> arr = {1, 3, 3, 5, 7};
    // cout<<"Upper Bound: "<<custom_upper_bound(arr, 0)<<endl;
  }

  {
    // Count how many times a target occurs in a sorted array in O(log n).
    // vector<int> arr = {1, 2, 2, 2, 4, 5, 5, 7};
    // int target = 5;
    // auto count = count_occurances(arr, target);
    // cout<<"Occurence Count: "<<count<<endl;
  }

  {
    vector<int> arr = {1, 2, 2, 2, 3, 3, 5, 7, 7, 7, 7};
    cout<<count_occurrences(arr, 2)<<" "<<count_occurrences(arr, 7)<<" "<<count_occurrences(arr, 4)<<endl;
    cout<<"First Index for 7: "<<lower_bound(arr.begin(), arr.end(), 7)-arr.begin()<<endl;
    cout<<"Last Index for 7: "<<upper_bound(arr.begin(), arr.end(), 7)-arr.begin()-1<<endl;
  }

  return 0;
}

bool linear_search(const vector<int>& arr, int target){
  for(int num: arr){
    if (num==target)
    {
      return true;
    }
  }
  return false;
}

int binary_search(const vector<int>& arr, int target){
  int left = 0, right = arr.size()-1, mid=0;
  while (left<=right)
  {
    mid=left+(right-left)/2;
    if (arr[mid]==target)
    {
      return mid;
    }
    else if (arr[mid]<target)
    {
      left=mid+1;
    }
    else
    {
      right=mid-1;
    }
  }
  return -1;
}

int search_insert(const vector<int>& arr, int target){  // lower_bound
  int left = 0, right = arr.size()-1, mid=0;
  while (left<=right)
  {
    mid=left+(right-left)/2;
    cout<<left<<" "<<right<<" "<<mid<<endl;
    if (arr[mid]==target)   // exclude this if statement in lower_bound
    {
      return mid;
    }
    else if (arr[mid]<target)
    {
      left=mid+1;
    }
    else
    {
      right=mid-1;
    }
  }
  return left;
}

int custom_upper_bound(const vector<int>& arr, int target){
  int left = 0, right = arr.size()-1, mid=0;
  while (left<=right)
  {
    mid=left+(right-left)/2;
    cout<<left<<" "<<right<<" "<<mid<<endl;
    if (arr[mid]<=target)
    {
      left=mid+1;
    }
    else
    {
      right=mid-1;
    }
  }
  return left;
}

int count_occurrences(const vector<int>& arr, int target){
  return upper_bound(arr.begin(), arr.end(), target) - lower_bound(arr.begin(), arr.end(), target);
}
