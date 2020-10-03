/********************************************/
/* Given a 2-D Matrix of m x n such that each row is
    Sorted in ascending order from left to right
    and each column in sorted in ascending order 
    from top to bottom.

    You are given a key k, find whether this key
    is present in the matrix or not, return true 
    if present else return false.

    Expected Time Complexity: O(m+n)
    Expected Space Complexity: O(1)

*/

#include <bits/stdc++.h>

using namespace std;


bool search(vector<vector<int>> &matrix,int target)
{
    if(matrix.size()==0) return false;
        
        int n= matrix.size();
        int m= matrix[0].size();
        
        int i=0,j=m-1;
        
        
        while(i<n && j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
                j--;
            else
                i++;
        }
        
        return false;
}


int main()
{   
    int n,m;
    cin>>n>>m;
    vector <vector<int>> matrix(n,vector<int>(m));
    
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

