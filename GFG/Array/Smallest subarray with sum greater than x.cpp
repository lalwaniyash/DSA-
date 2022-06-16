// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int left =0;
        int right = 0;
        int sum = 0;
        int shortest = INT_MAX;
        
        while(right<n){
            sum+=arr[right];
            
            if(sum>x){
                while(sum>x){
                    sum-=arr[left];
                    left++;
                }
                shortest = min(shortest,right-left+2);
            }
            right++;
        }
        return shortest;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}  // } Driver Code Ends