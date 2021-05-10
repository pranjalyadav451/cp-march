// { Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
#define ll long long
class Solution {
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        ll preSum = 0, sum = 0, i_ptr = 0;
        for (int i = 0; i < n; i++) sum += a[i];

        for (int i = 0; i < n; i++) {
            if (preSum == sum - a[i]) return i + 1;
            preSum += a[i]; sum -= a[i];
        }
        return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;

    //taking testcases
    cin >> t;

    while (t--) {
        long long n;

        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends