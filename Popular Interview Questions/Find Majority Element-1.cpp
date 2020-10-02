/******************************************************/
/*  Question Statement - Given an array of n integers find the 
    number that occurs more than floor(n/2) times . If no element exists
    then return -1
    
    Expected Time Complexity- O(n)
    Expected Space Complexity- O(1)
    
*/
/******************************************************/

#include <bits/stdc++.h>

using namespace std;

/* Algorithm Used - Moore's Voting Algorithm */
int majorityElement(vector<int> &nums)
{
    int majority = -1;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == majority)
        {
            count++;
        }
        else if (count == 0)
        {
            majority = nums[i];
            count = 1;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    /* Add check for the case in which no element appears greater than 
        n/2 times

        Eg: nums=[1,2,3,4,5,5,1,2]
    */
    for (int item : nums)
    {
        if (item == majority)
        {
            count++;
        }
    }
    if (cout > (n / 2))
    {
        return majority;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> input(n);
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }

    cout << majorityElement(input) << endl;
}
