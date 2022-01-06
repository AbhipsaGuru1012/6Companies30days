// // M items are to be delivered in a circle of size N. Find the position where the M-th item will be delivered if we start from a given position K. Note that items are distributed at adjacent positions starting from K.

// Examples : 
 

// Input : N = 5 // Size of circle
//         M = 2 // Number of items
//         K = 1 // Starting position
// Output : 2
// The first item will be given to 1st 
// position. Second (or last) item will 
// be delivered to 2nd position

// Input : N = 5 
//         M = 8 
//         K = 2
// Output : 4
// The last item will be delivered to 
// 4th position

#include <bits/stdc++.h>
using namespace std;

int lastPosition(int n, int m, int k)
{

    if (m <= n - k + 1)
        return m + k - 1;

    m = m - (n - k + 1);

    return (m % n == 0) ? n : (m % n);
}

// Driver code
int main()
{
    int n = 5;
    int m = 8;
    int k = 2;
    cout << lastPosition(n, m, k);
    return 0;
}