// Find total number of Squares in a N*N cheesboard.

 

// Example 1:

// Input:
// N = 1
// Output:
// 1
// Explanation:
// A 1*1 chessboard has only 1 square.
// Example 2:

// Input:
// N = 2
// Output:
// 5
// Explanation:
// A 2*2 chessboard has 5 squares.
// 4 1*1 squares and a 2*2 square.
 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function squaresInChessBoard() which takes an Integer N as input and returns the number of squares in a N*N chessboard.

 

// Expected Time Complexity: O(1)
// Expected Auxiliary Space: O(1)

 

// Constraints:
// 1 <= N <= 105

// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        // code here
        return (N*(N+1)*(2*N+1))/6;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.squaresInChessBoard(N) << endl;
    }
    return 0;
}  // } Driver Code Ends