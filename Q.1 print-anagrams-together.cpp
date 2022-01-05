// Given an array of strings, return all groups of strings that are anagrams. The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.


// Example 1:

// Input:
// N = 5
// words[] = {act,god,cat,dog,tac}
// Output:
// act cat tac 
// god dog
// Explanation:
// There are 2 groups of
// anagrams "god", "dog" make group 1.
// "act", "cat", "tac" make group 2.
// Example 2:

// Input:
// N = 3
// words[] = {no,on,is}
// Output: 
// no on
// is
// Explanation:
// There are 2 groups of
// anagrams "no", "on" make group 1.
// "is" makes group 2. 

// Your Task:
// The task is to complete the function Anagrams() that takes a list of strings as input and returns a list of groups such that each group consists of all the strings that are anagrams.


// Expected Time Complexity: O(N*|S|*log|S|), where |S| is the length of the strings.
// Expected Auxiliary Space: O(N*|S|), where |S| is the length of the strings.


// Constraints:
// 1<=N<=100

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>> v1;
        for(int i=0;i<string_list.size();i++){
            string s1=string_list[i];
            vector<string> v;
            v.push_back(s1);
            if(i==string_list.size()-1){
                v1.push_back(v);
            }
            for(int j=i+1;j<string_list.size();j++){
                string s2=string_list[j];
                string s=s1;
                string str=s2;
                sort(s.begin(),s.end());
                sort(str.begin(), str.end());
                if(s.length()!=str.length()){
                    if(j==(string_list.size()-1)){
                        v1.push_back(v);
                    }
                    continue;
                }
                for(int k=0;k<s.length();k++){
                    if(s[k]!=str[k]){
                        break;
                    }else if(k==(s.length()-1)){
                        v.push_back(s2);
                        string_list.erase(string_list.begin()+j);
                        j--;
                    }
                }
                if(j==(string_list.size()-1)){
                    v1.push_back(v);
                }
            }
        }
        return v1;
    }
};

