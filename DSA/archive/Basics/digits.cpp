#include<bits/stdc++.h>
using namespace std;

int main(){
  cout<<"Hello World"<<endl;
  // int num = 5758, revNum=0;
  // // extration of digits
  // while (num>0)
  // {
  //   int digit = num%10;
  //   revNum = revNum*10 + digit;
  //   num/=10;
  // }

  // cout<<revNum<<endl;

  // divisors of a number
  // int n = 20;
  // for (int i = 1; i*i < n; i++)
  // {
  //   if (n%i==0)
  //   {
  //     cout<<i<<" ";
  //     if (n/i!=i)
  //     {
  //       cout<<n/i<<" ";
  //     }
  //   }
  // }

  // Highest Common Factor (HCF / GCD) using Equilateral Algo (Euclidean) -> F(a-b, b) also F(a%b, b)
  int num1 = 20, num2 = 40;
  while (num1>0 && num2>0)
  {
    if(num1>num2) num1%=num2;
    if(num2>num1) num2%=num1;
  }
  if (num1==0)  cout<<num2<<endl;
  if (num2==0)  cout<<num1<<endl;



  return 0;
}