// Given a set of N nuts of different sizes and N bolts of different sizes. There is a one-one mapping between nuts and bolts. Match nuts and bolts efficiently.

// Comparison of a nut to another nut or a bolt to another bolt is not allowed. It means nut can only be compared with bolt and bolt can only be compared with nut to see which one is bigger/smaller.
// The elements should follow the following order ! # $ % & * @ ^ ~ .

// Example 1:

// Input: 
// N = 5
// nuts[] = {@, %, $, #, ^}
// bolts[] = {%, @, #, $ ^}
// Output: 
// # $ % @ ^
// # $ % @ ^
// Example 2:

// Input: 
// N = 9
// nuts[] = {^, &, %, @, #, *, $, ~, !}
// bolts[] = {~, #, @, %, &, *, $ ,^, !}
// Output: 
// ! # $ % & * @ ^ ~
// ! # $ % & * @ ^ ~
// Your Task:  
// You don't need to read input or print anything. Your task is to complete the function matchPairs() which takes an array of characters nuts[], bolts[] and n as parameters and returns void. You need to change the array itself.

// Expected Time Complexity: O(NlogN)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 <= N <= 9
// Array of Nuts/Bolts can only consist of the following elements:{'@', '#', '$', '%', '^', '&', '~', '*', '!'}.

// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
	void matchPairs(char nuts[], char bolts[], int n) {
	    // code here
        char arr[9]={'0','0','0','0','0','0','0','0','0'} ;
        for(int i=0;i<n;i++){
            if(nuts[i]=='!'){
                arr[0]='!';
            }
            else if{
                (nuts[i]=='#')arr[1]='#';
            }
            else if{
                (nuts[i]=='$')arr[2]='$';
            }
            else  if(nuts[i]=='%'){
                arr[3]='%';
            }
            else if{
                (nuts[i]=='&')arr[4]='&';
            }
            else if(nuts[i]=='*'){
                arr[5]='*';
            }
            else if(nuts[i]=='@'){
                arr[6]='@';
            }
            else if(nuts[i]=='^'){
                arr[7]='^';
            }
            else{
                arr[8]='~';
            }
        }
        int count=0;
        for(int i=0;i<9;i++){
            if(arr[i]!='0'){
                nuts[count]=arr[i];
                bolts[count]=arr[i];
                count++;
            }      
        }
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        char nuts[n], bolts[n];
        for (int i = 0; i < n; i++) {
            cin >> nuts[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> bolts[i];
        }
        Solution ob;
        ob.matchPairs(nuts, bolts, n);
        for (int i = 0; i < n; i++) {
            cout << nuts[i] << " ";
        }
        cout << "\n";
        for (int i = 0; i < n; i++) {
            cout << bolts[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends