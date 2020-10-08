/****************************************************/
/*
        Given an n x m matrix where each row is sorted 
        in ascending order from left to right and first integer
        of each row is greater than last integer of previous row.

        Given a key k find if the key exists in the matrix of not.
        Return true if the key exists and false if key doesn't exixts.

        Expected Time Complexity - O(log(n*m))
        Expected Space Complexity - O(1)


*/

#include <bits/stdc++.h>

using namespace std;

bool search(vector<vector<int>> &matrix,int target)
{
            if(matrix.size()==0)
        {
            return false;
        }
        int n= matrix.size();
        int m= matrix[0].size();
        
        int start=0,end=(n*m)-1;
        
        int mid;
        bool ans=false;
        while(start<=end)
        {
                mid=(end+start)/2;
                
            if(matrix[mid/m][mid%m]==target)
            {
                ans=true;
                break;
            }
            else if(matrix[mid/m][mid%m]>target)
            {
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
        }
        
        
        
        
        return ans;
}


int main()
{   int n,m;
    cin>>n>>m;

    vector<vector<int>> matrix(n,vector<int>(m));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>matrix[i][j];
        }
    }
    int key;
    cin>>key;
    cout<< search(matrix,key)<<endl;
}