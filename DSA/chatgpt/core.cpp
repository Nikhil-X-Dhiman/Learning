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

  {
    // 32 16 8 4 2 1


    // 5: 101
    // 3: 011
    // OR:111
    // AND:001
    // XOR:110

    // 7: 111
    // 111 & 1 = 1 so odd
    // 12: 1100 & 1 = 0 so even
    // 25: 11001 & 1 = 1 so odd
    // 40: 101000 & 1 = 0 so even

    // int n = 13
    // bit pos 3 2 1 0 (13 & (1 << 2))
    // bits    1 1 0 1
    // 1 << 2  0 1 0 0
    // &       0 1 0 0 -> non zero
    // so 2nd bit is set

    // set a bit
    // num | (1 << k)

    // clear bit
    // num & ~(1 << k)

    // toggle a bit
    // num ^ (1 << k)

    // remove lowest set bit
    // num & (num - 1)
  }

  {
    int n = 10;
    n = n | (1 << 0);
    cout<<n<<endl;
  }

  {
    int n = 15;
    n = n & ~(1<<1);
    cout<<n<<endl;
  }

  {
    int n = 10;
    n = n ^ (1 << 1);
    cout<<n<<endl;
  }

  {
    int n = 23, count=0;
    while (n>0)
    {
      n=n & (n-1);
      count++;
    }
    cout<<count<<endl;
  }

  {
    int arr[] = {1, 2, 4, 6, 8, 12, 16, 20, 32};
    int count = 0, size = sizeof(arr)/sizeof(arr[0]), i=0;
    while (i<size)
    {
      if (arr[i]>0 && (arr[i] & (arr[i]-1)) == 0)
      {
        count++;
        cout<<arr[i]<<" ";
      }
      i++;
    }
    cout<<endl;
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
