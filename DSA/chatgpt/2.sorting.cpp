#include<iostream>
#include<vector>
using namespace std;

template <typename T>
void traverse_vectors(const T& arr);

template <typename T>
void swap_elements(T& a, T& b);
void selection_sort(vector<int>& arr);
void insertion_sort(vector<int>& arr);
void bubble_sort(vector<int>& arr);
void merge_sort(vector<int>& arr, int start, int end);
void merge_sorted_arr(vector<int>& arr, int start, int mid, int end);
void quick_sort(vector<int>& arr, int start, int end);
int partition(vector<int>& arr, int start, int end);


int main(){

  vector<int> arr = {4, 2, 6, 5, 7, 1, 3};
  // selection_sort(arr);
  // insertion_sort(arr);
  // bubble_sort(arr);
  // merge_sort(arr, 0, arr.size()-1);
  quick_sort(arr, 0, arr.size()-1);
  traverse_vectors(arr);

  return 0;
}

template <typename T>
void traverse_vectors(const T& arr){
  for(auto i: arr){
    cout<<i<<" ";
  }
  cout<<endl;
  return;
}

template <typename T>
void swap_elements(T& a, T& b){
  auto tmp = a;
  a=b;
  b=tmp;
  return;
}

void selection_sort(vector<int>& arr){
  for (size_t i = 0; i < arr.size(); i++)
  {
    size_t minValueIndex = i;
    for (size_t j = i+1; j < arr.size(); j++)
    {
      if (arr[j]<arr[minValueIndex])
      {
        minValueIndex=j;
      }
    }
    swap_elements(arr[i], arr[minValueIndex]);
  }
  return;
}

void insertion_sort(vector<int>& arr){
  int n=arr.size();
  for (int i = 1; i < n; i++)
  {
    int j=i-1, key=arr[i];
    while (j>=0 && arr[j]>key)
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=key;
  }
  return;
}

void bubble_sort(vector<int>& arr){
  int n=arr.size();
  for (int i = 0; i < n-1; i++)
  {
    bool swapped=false;
    for (int j = 0; j < n-i-1; j++)
    {
      if (arr[j]>arr[j+1])
      {
        swap_elements(arr[j], arr[j+1]);
        swapped=true;
      }

    }
    if (!swapped)
    {
      break;
    }

  }
  return;
}

void merge_sort(vector<int>& arr, int start, int end){
  if (start>=end)
  {
    return;
  }

  int mid = start + (end - start) / 2;
  merge_sort(arr, start, mid);
  merge_sort(arr, mid+1, end);

  merge_sorted_arr(arr, start, mid, end);
}

void merge_sorted_arr(vector<int>& arr, int start, int mid, int end){
  vector<int> tmp;
  int i=start, j=mid+1;
  while (i<=mid && j<=end)
  {
    if (arr[i]<arr[j])
    {
      tmp.push_back(arr[i]);
      i++;
    }else
    {
      tmp.push_back(arr[j]);
      j++;
    }
  }
  while (i<=mid)
  {
    tmp.push_back(arr[i]);
    i++;
  }
  while (j<=end)
  {
    tmp.push_back(arr[j]);
    j++;
  }

  for (int k = 0; k < tmp.size(); k++)
  {
    arr[start+k] = tmp[k];
  }

}

void quick_sort(vector<int>& arr, int start, int end){
  if (start>=end)
  {
    return;
  }

  int pIndex = partition(arr, start, end);
  quick_sort(arr, start, pIndex-1);
  quick_sort(arr, pIndex+1, end);
  return;
}

int partition(vector<int>& arr, int start, int end){
  int pivot = arr[start];
  int i=start, j=end;

  while (i<j)
  {
    while (arr[i]<=pivot && i<=end-1)
    {
      i++;
    }
    while (arr[j]>pivot && j>=start)
    {
      j--;
    }
    if (i<j)
    {
      swap(arr[i], arr[j]);
    }
  }
  swap(arr[start], arr[j]);
  return j;
}
