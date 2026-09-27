#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void traverse_array(const vector<int>& arr);
void reverse_array(vector<int>& arr, int i=0);
int nth_fibonacci_numer(int n);

int main(){

  {
    vector<int> arr = {1, 2, 3, 4, 5};
    traverse_array(arr);
    reverse_array(arr);
    traverse_array(arr);
  }

  {
    cout<<nth_fibonacci_numer(10)<<endl;
  }
  return 0;
}

void traverse_array(const vector<int>& arr){
  for(int i: arr){
    cout<<i<<" ";
  }
  cout<<endl;
}

void reverse_array(vector<int>& arr, int i){
  if (i>=arr.size()/2)
  {
   return;
  }
  swap(arr[i], arr[arr.size()-1-i]);
  reverse_array(arr, i+1);
}

int nth_fibonacci_numer(int n){
  if (n<=1)
  {
    return n;
  }

  return nth_fibonacci_numer(n-2) + nth_fibonacci_numer(n-1);
}
