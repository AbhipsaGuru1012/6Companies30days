// An encoded string (s) is given, the task is to decode it. The pattern in which the strings were encoded were as follows
// original string: abbbababbbababbbab 
// encoded string : 3[a3[b]1[ab]]

// Example 1:

// Input: s = 1[b]
// Output: b
// Explaination: 'b' is present only one time.
// Example 2:

// Input: s = 3[b2[ca]]
// Output: bcacabcacabcaca
// Explaination: 2[ca] means 'ca' is repeated 
// twice which is 'caca' which concatenated with 
// 'b' becomes 'bcaca'. This string repeated 
// thrice becomes the output.
// Your Task:
// You do not need to read input or print annything. Your task is to complete the function decodedString() which takes s as input parameter and returns the decoded string.

// Expected Time Complexity: O(|s|)
// Expected Auxiliary Space: O(|s|)

// Constraints:
// 1 ≤ |s| ≤ 30 

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<int> count;  
        stack<string> result; 
        int index = 0;  
        string curr_string = "";   
        
        while(index < s.length()) { 
            if(isdigit(s[index])) {
                int num = 0;  
                while(isdigit(s[index])) {
                    num = 10 * num + (s[index] - '0');  
                    index++;
                }
                count.push(num);
            }
            else if(s[index] == '[') {
                result.push(curr_string); 
                curr_string = "";
                index = index + 1;  
            }
            else if(s[index] == ']') {
                int n = count.top(); count.pop();   
                string res = result.top();result.pop();    
                for(int i = 0; i < n; ++i) {
                    res += curr_string;  
                }
                curr_string = res;  
                index = index + 1;  
            }else {
                curr_string += s[index]; 
                index = index + 1;  
            }
        }
        
        return curr_string;  
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends