#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void find_subsets_arrays(const vector<int>& arr, int index, vector<int> result);
void find_permutation_swap(int index, vector<int>& arr, vector<vector<int>> ans);
// void find_combination(int index, const vector<int>& arr, vector<vector<int>>& ans, vector<int>& current);
void find_combination(int index, int k, const vector<int>& arr, vector<vector<int>>& ans, vector<int>& current);
void find_combintion_sum(int start, const vector<int>& arr, vector<vector<int>>& ans, vector<int>& current, int sum);
void traverse2vector(const vector<vector<int>> arr);

int main(){
  {
    vector<int> arr={1, 2, 3};
    vector<int> result;
    find_subsets_arrays(arr, 0, result);
  }
  cout<<endl;
  {
    vector<int> arr={1, 2, 3};
    vector<vector<int>> ans;
    find_permutation_swap(0, arr, ans);

  }
  cout<<endl;
  {
    vector<int> arr={1, 2, 3, 4};
    vector<int> current;
    vector<vector<int>> ans;
    find_combination(0, 2, arr, ans, current);
    traverse2vector(ans);
  }
  cout<<endl;

  {
    vector<int> arr={1, 2, 3, 4};
    vector<int> current;
    vector<vector<int>> ans;
    int sum=0;
    find_combintion_sum(0, arr, ans, current, sum);
    traverse2vector(ans);
  }
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

// void find_combination(int index, const vector<int>& arr, vector<vector<int>>& ans, vector<int>& current){
//   if (current.size()==2)
//   {
//     ans.push_back(current);
//     return;
//   }
//   if (index==arr.size())
//   {
//     traverse2vector(ans);
//     return;
//   }
//   for (int16_t i = index+1; i < arr.size(); i++)
//   {
//     current.push_back(arr[index]);
//     current.push_back(arr[i]);
//     find_combination(index, arr, ans, current);
//     current.pop_back();
//     current.pop_back();
//   }
//   find_combination(index+1, arr, ans ,current);
//   return;
// }

void find_combination(int index, int k, const vector<int>& arr, vector<vector<int>>& ans, vector<int>& current){
  if (current.size()==k)
  {
    ans.push_back(current);
    return;
  }

  for (int16_t i = index; i < arr.size(); i++)
  {
    current.push_back(arr[i]);
    find_combination(i+1, k, arr, ans, current);
    current.pop_back();
  }

  return;
}

// Find combinations whose sum is exactly 7
void find_combintion_sum(int start, const vector<int>& arr, vector<vector<int>>& ans, vector<int>& current, int sum){
  if (sum==7)
  {
    ans.push_back(current);
    return;
  }
  for (int16_t i = start; i < arr.size(); i++)
  {
    current.push_back(arr[i]);
    sum+=arr[i];
    find_combintion_sum(i+1, arr, ans, current, sum);
    sum-=current[current.size()-1];
    current.pop_back();
  }

  return;
}
