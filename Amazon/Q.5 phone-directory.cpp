// Given a list of contacts contact[] of length n where each contact is a string which exist in a phone directory and a query string s. The task is to implement a search query for the phone directory. Run a search query for each prefix p of the query string s (i.e. from  index 1 to |s|) that prints all the distinct contacts which have the same prefix as p in lexicographical increasing order. Please refer the explanation part for better understanding.
// Note: If there is no match between query and contacts, print "0".

// Example 1:

// Input: 
// n = 3
// contact[] = {"geeikistest", "geeksforgeeks", 
// "geeksfortest"}
// s = "geeips"
// Output:
// geeikistest geeksforgeeks geeksfortest
// geeikistest geeksforgeeks geeksfortest
// geeikistest geeksforgeeks geeksfortest
// geeikistest
// 0
// 0
// Explaination: By running the search query on 
// contact list for "g" we get: "geeikistest", 
// "geeksforgeeks" and "geeksfortest".
// By running the search query on contact list 
// for "ge" we get: "geeikistest" "geeksforgeeks"
// and "geeksfortest".
// By running the search query on contact list 
// for "gee" we get: "geeikistest" "geeksforgeeks"
// and "geeksfortest".
// By running the search query on contact list 
// for "geei" we get: "geeikistest".
// No results found for "geeip", so print "0". 
// No results found for "geeips", so print "0".
// Your Task:
// Youd do not need to read input or print anything. Your task is to complete the function displayContacts() which takes n, contact[ ] and s as input parameters and returns a list of list of strings for required prefixes. If some prefix has no matching contact return "0" on that list.

// Expected Time Complexity: O(|s| * n * max|contact[i]|)
// Expected Auxiliary Space: O(n * max|contact[i]|)

// Constraints:
// 1 ≤ n ≤ 50
// 1 ≤ |contact[i]| ≤ 50
// 1 ≤ |s| ≤ 6 

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        for(int i = 0; i < n-1; ++i)
           for( int j = i+1; j < n; ++j)
           {
              if(contact[i] > contact[j])
              {
                string temp = contact[i];
                contact[i] = contact[j];
                contact[j] = temp;
              }
        }
        
        vector<vector<string>> v;
        for(int i=0;i<s.length();i++){
            string str=s.substr(0, (i+1));
            vector<string> v1;
            for(int j=0;j<n;j++){
                string str1=contact[j].substr(0, (i+1));
                if(str==str1){
                    v1.push_back(contact[j]);
                }
            }
            if(v1.size()==0){
                v1.push_back("0");
                v.push_back(v1);
            }
            std::sort(v1.begin(), v1.end());
            v1.erase(std::unique(v1.begin(), v1.end()), v1.end());
            v.push_back(v1);
                
            
        }
        return v;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends