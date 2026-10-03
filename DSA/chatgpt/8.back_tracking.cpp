#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void find_subsets_arrays(const vector<int>& arr, int index, vector<int> result);
void find_permutation_swap(int index, vector<int>& arr, vector<vector<int>> ans);

int main(){

  vector<int> arr={1, 2, 3};
  vector<int> result;

  find_subsets_arrays(arr, 0, result);
  cout<<endl;
  vector<vector<int>> ans;
  find_permutation_swap(0, arr, ans);
  cout<<endl;

  return 0;
}

void traverse_vector(const vector<int>& arr){
  for(int i: arr){
    cout<<i;
  }
  cout<<" ";
  return;
}

void traverse2vector(const vector<vector<int>> arr){
  for(vector<int> subArray: arr){
    for(int n: subArray){
      cout<<n;
    }
    cout<<" ";
  }
  return;
}

void find_subsets_arrays(const vector<int>& arr, int index, vector<int> result){
  if (index>=arr.size())
  {
    traverse_vector(result);
    return;
  }
  result.push_back(arr[index]);
  find_subsets_arrays(arr, index+1, result);

  result.pop_back();
  find_subsets_arrays(arr, index+1, result);

  return;
}

void find_permutation_swap(int index, vector<int>& arr, vector<vector<int>> ans){
  if (index==arr.size())
  {
    ans.push_back(arr);
    traverse2vector(ans);
    return;
  }
  for (int16_t i = index; i < arr.size(); i++)
  {
    swap(arr[index], arr[i]);
    find_permutation_swap(index+1, arr, ans);
    swap(arr[index], arr[i]);
  }
  return;
}
