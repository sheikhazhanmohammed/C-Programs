#include<iostream>
using namespace std;
int sum(int a, int b)
{
  return a+b;
}
int difference(int a, int b)
{
  return a-b;
}
int multiply(int a, int b)
{
  return a*b;
}
int division(int a, int b)
{
  return a/b;
}
main()
{
  int choice, number1, number2, exit=1;
  cout<<"Enter the two numbers: "<<endl;
  cin>>number1>>number2;
  cout<<"Enter choice as follows: \n 1 for Add \n 2 for Multiply \n 3 for Difference \n 4 for Divide"<<endl;
  cin>>choice;
  while(exit)
  {
    int result;
    if(choice==1)
      result=sum(number1,number2);
    else if(choice==2)
      result=multiply(number1,number2);
    else if(choice==3)
      result=difference(number1,number2);
    else if(choice==4)
      result=division(number1,number2);
    else
      cout<<"enter valid choice"<<endl;
    cout<<"The result of operation is: "<<result<<endl;
    cout<<"Enter 0 to exit, or 1 to continue"<<endl;
    cin>>exit;
    if(exit==0)
    {
      break;
    }
    else
    {
        cout<<"Enter numbers"<<endl;
        cin>>number1>> number2;
    }
  }
}
