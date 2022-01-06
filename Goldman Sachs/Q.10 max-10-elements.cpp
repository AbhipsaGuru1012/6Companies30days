//Find Max Ten Numbers in a Million Entries Given.

#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector<int> maxTenNumbers(vector<int> arr, int n)
    {
    
        vector<int> max;

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for (int i = 0; i < 10; i++)
        {
            minHeap.push(arr[i]);
        }

        for (int i = 10; i < n; i++)
        {
            if (arr[i] > minHeap.top())
            {
                minHeap.pop();
                minHeap.push(arr[i]);
            }
        }

        while (!minHeap.empty())
        {
            max.push_back(minHeap.top());
            minHeap.pop();
        }
        return max;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int i;
        int k;
        cin >> k;
        vector<int> arr;
        for(i=1;i<=1000000;i++){
            cin>>arr[i];
        }
        vector<int> v;
        Solution obj;
        v=obj.maxTenNumbers(arr, k);
        for(int k=0;k<10;k++){
            cout<<v[k]<<" ";
        }
    }
    return 0;
}