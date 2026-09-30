#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> nextGreaterElement(const vector<int>& arr);
vector<int> nextSmallerElement(const vector<int>& arr);

int main(){



  return 0;
}



vector<int> nextGreaterElement(const vector<int>& arr){
  vector<int> result;
  stack<int> st;
  for (int16_t i = arr.size()-1; i > 0; i--)
  {
    while (!st.empty() && arr[i]>=st.top())
    {
      st.pop();
    }
    if (st.empty())
    {
      result[i]=-1;
    }else
    {
      result[i]=st.top();
    }
    st.push(arr[i]);
  }
  return result;
}

vector<int> nextSmallerElement(const vector<int>& arr){
  vector<int> result;
  stack<int> st;
  for (int16_t i = arr.size()-1; i > 0; i--)
  {
    while (!st.empty() && st.top()>=arr[i])
    {
      st.pop();
    }
    if (st.empty())
    {
      result[i]=-1;
    }else
    {
      result[i]=st.top();
    }
    st.push(arr[i]);
  }
  return result;
}
