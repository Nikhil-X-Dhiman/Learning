#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool linear_search(const vector<int>& arr, int target);
int binary_search(const vector<int>& arr, int target);

int main(){

  {
    // linear search
    vector<int> arr = {1, 2, 3, 4, 5};
    cout<<"Elemant Found: "<<linear_search(arr, 4)<<endl;
  }

  {
    // binary search
    vector<int> arr = {1, 2, 3, 4, 5, 9};
    int result = binary_search(arr, 5);
    if (result>=0)
    {
      cout<<"Elemant Found At: "<<result<<endl;
    }else
    {
      cout<<"Element Not Found!!!"<<endl;
    }

    // using stl functions
    cout<<"STL Binary Search: "<<std::binary_search(arr.begin(), arr.end(), 3);
  }

  {
    // Problem: Search Insert Position

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
