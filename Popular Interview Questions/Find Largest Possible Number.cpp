/*****************************************************/
/* Given an array of integers return the maximum 
   number that can be formed for these numbers

   Eg: Input:[2,303,55,21]
       Output: 55303221

       Input: [11,19]
       Output: 1911

    Note: The answer may be too large to
          fit inside the long long int so 
          return the answer in form of string


    Expected Time Complexity: Average Case -> O(nlogn) WorstCase -> O(n^2)
    Expected Space Complexity: O(n) (For recursion stack)

*/

#include <bits/stdc++.h>

using namespace std;


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


// Partition algorithm for quicksort

int part(vector<int> &arr, int start, int end)
{

    int index = start + (rand() % (end - start + 1));
    swap(arr[index], arr[end]);
    int temp = start;
    for (int i = start; i < end; i++)
    {
        if ((to_string(arr[i]) + to_string(arr[end])) > ((to_string(arr[end]) + to_string(arr[i]))))
        {
            swap(arr[temp], arr[i]);
            temp++;
        }
    }

    swap(arr[end], arr[temp]);

    return temp;
}

// Randomised QuickSort Used to avoid input dependence

void quick(vector<int> &arr, int start, int stop)
{
    if (start >= stop)
    {
        return;
    }
    int pivot = part(arr, start, stop);
    quick(arr, start, pivot - 1);
    quick(arr, pivot + 1, stop);
}

string maxNum(vector<int> &arr)
{
    quick(arr, 0, arr.size() - 1);
    stirng s = "";
    
    // Below is the code for edge case like Input:[0,0,0,0]

    bool no_zero = false;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0 && no_zero == false)
        {
            continue;
        }
        else if (arr[i] != 0 && no_zero == false)
        {
            no_zero = true;
            s += to_string(arr[i]);
        }
        else
        {
            s += to_string(arr[i]);
        }
    }
    if (s.compare("") == 0)
    {
        s += "0";
    }
    return s;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << maxNum(arr);
}