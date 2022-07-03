// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        long long sum[n];
        sum[0] = a[0];
        
        if(n ==1) return 1;
        
        for(int i = 1; i<n; i++){
            sum[i] = sum[i-1] + a[i];
        }
        int total = sum[n-1];
        
        for(int i = 1; i<n; i++){
            int leftSum = sum[i] - a[i];
            int rightSum = total - sum[i];
            if(leftSum == rightSum)
                return i+1;
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