/***************************************************/
/*
        Asked in Amazon

        Given an array(0-based indexing), you have to 
        find the max sum of i*A[i] where A[i] is the 
        element at index i in the array. The only operation
        allowed is to rotate(clock-wise or counter clock-wise)
        the array any number of times.

        Eg:  Input: N=4, A[]={8,3,1,2}
             Output: 29

        Expected  Time Complexity : O(n)
        Expected Space Complexoty : O(1)

*/

#include <bits/stdc++.h>

using namespace std;

int max_sum(vector<int> A,int N)
{
    int prem=-1;
    int temp=0;
    int sum=0;
    for(int i=0;i<N;i++)
    {
        temp+= i*A[i];
        
        sum+=A[i];
        
    }
    prem=max(temp,prem);
    for(int i=0;i<N;i++)
    {
        temp= temp- (sum-A[i])+ (N-1)*A[i];
        prem=max(temp,prem);
        
    }
    
    return prem;
    
    
}

int main()
{   int n;
    cin>>n;

    vector<int> A(n);

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    cout<< max_sum(A,n)<<endl;

}