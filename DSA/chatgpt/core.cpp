#include <iostream>
using namespace std;

int recursiveArraySum(int arr[], int index, int size);

int main(){
  cout<<"PROGRAM STARTED!!!"<<endl;

  {
    // string name;
    // getline(cin, name);
    // cout<<"Name: "<<name<<endl;
  }

  {
    // string s = "12345";
    // cout<<stoi(s) + 100<<endl;
  }

  {
    // int x = 100;
    // int* p = &x;
    // *p = 200;
    // cout<<x<<endl;
  }

  {
    // int* a=nullptr;
    // cout<<*a<<endl;
  }

  {
    // int arr[] = {10, 20, 30, 40, 50};
    // int* p=(arr+2);
    // *p = 100;
    // cout<<arr[2]<<endl;

  }

  {
    // struct Node {
    //   int num;
    //   Node* next=nullptr;
    // };
    // Node* a = new Node{5};
    // Node* b = new Node{10};
    // Node* c = new Node{15};
    // Node* current = a;
    // a->next=b;
    // b->next=c;
    // while (current!=nullptr)
    // {
    //   cout<<current->num<<" ";
    //   current=current->next;
    // }
    // cout<<endl;
    // delete a;
    // delete b;
    // delete c;

  }

  {
    // int arr[] = {5, 10, 15, 20};
    // int size = sizeof(arr)/sizeof(arr[0]);
    // cout<<"SUM of array: "<<recursiveArraySum(arr, 0, size)<<endl;
  }

  return 0;
}

int recursiveArraySum(int arr[], int index, int size){
  if (index==size)
  {
    return 0;
  }
  return arr[index] + recursiveArraySum(arr, index+1, size);
}
