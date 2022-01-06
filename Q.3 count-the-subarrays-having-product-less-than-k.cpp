// Given an array of positive numbers, the task is to find the number of possible contiguous subarrays having product less than a given number k.

// Example 1:

// Input : 
// n = 4, k = 10
// a[] = {1, 2, 3, 4}
// Output : 
// 7
// Explanation:
// The contiguous subarrays are {1}, {2}, {3}, {4} 
// {1, 2}, {1, 2, 3} and {2, 3} whose count is 7.
 

// Example 2:

// Input:
// n = 7 , k = 100
// a[] = {1, 9, 2, 8, 6, 4, 3}
// Output:
// 16
 

// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function countSubArrayProductLessThanK() which takes the array a[], its size n and an integer k as inputs and returns the count of required subarrays.

 

// Expected Time Complexity: O(n)
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 1<=n<=105
// 1<=k<=1015
// 1<=a[i]<=105

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int s=0, sum=0;
        long long product=1;
        for(int i=0;i<n;i++){
            product=product*a[i];
            while(s<i && product>=k){
                product=product/a[s];
                s=s+1;
            }
            if(product<k){
                sum=sum+(i-s+1);
            }
        }
        return sum;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends