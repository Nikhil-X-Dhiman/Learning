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


int main(){

  vector<int> arr = {4, 2, 6, 5, 7, 1, 3};
  // selection_sort(arr);
  // insertion_sort(arr);
  bubble_sort(arr);
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
