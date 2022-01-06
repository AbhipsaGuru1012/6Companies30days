// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
       vector<int> v;
        vector<int> v1;
        for(int i=1;i<=n;i++){
            v1.push_back(i);
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){   
            v.push_back(arr[i]);
        }
        sort(v.begin(), v.end());
        int k=1;
        for(int i=1;i<=n;i++){
            if(v[i-1]==v[i]){
                    // cout<<v[i];
                    b=v[i];
                    v[i]=v[n-1]+2;
                    break;
            }       
            
        }
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++){
            
            if(v[i]!=v1[i]){
                
                a=v1[i];
                break;
            }
        }
        
        int* arr1=new int[2];
        arr1[0]=b;
        arr1[1]=a;
        return arr1;
    }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends