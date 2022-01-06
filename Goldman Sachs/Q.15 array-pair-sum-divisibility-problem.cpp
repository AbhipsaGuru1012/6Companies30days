// Given an array of integers and a number k, write a function that returns true if given array can be divided into pairs such that sum of every pair is divisible by k.
 

// Example 1 :

// Input : arr = [9, 5, 7, 3], k = 6
// Output: True
// Explanation: {(9, 3), (5, 7)} is a 
// possible solution. 9 + 3 = 12 is divisible
// by 6 and 7 + 5 = 12 is also divisible by 6.

// Example 2:

// Input : arr = [2, 4, 1, 3], k = 4
// Output: False
// Explanation: There is no possible solution.
 

// Your Task:
// You don't need to read or print anything. Your task is to complete the function canPair() which takes array and k as input parameter and returns true if array can be divided into pairs such that sum of every pair is divisible by k otherwise returns false.
 

// Expected Time Complexity: O(n)
// Expected Space Complexity : O(n)
 

// Constraints:
// 1 <= length of array <= 100000
// 1 <= elements of array <= 100000
// 1 <= k <= 100000

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int, int>mp;
        for(int i=0; i<nums.size(); i++)
            mp[(nums[i]%k+k)%k]++;
        for(auto itr=mp.begin(); itr!=mp.end(); itr++)
        {
            if(itr->first==0){
                if((itr->second)%2!=0)
                    return false;
            }
            else
            {
                if(itr->second!=mp[k-(itr->first)])
                    return false;
            }
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends