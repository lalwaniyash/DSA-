//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
private:
    int Rbinarysearch(int arr[], int s, int e, int k){

        //base case
        if(s>e){
         return -1;   
        }
            
        int mid = s  + (e-s)/2;
        
        if(arr[mid] == k){
            return mid;
        }
        
        if(arr[mid] < k){
            return Rbinarysearch(arr, mid+1, e, k);
        }
        
        else{
            return Rbinarysearch(arr, s, mid-1, k);
        }
    }
public:
    int binarysearch(int arr[], int n, int k){
        int s = 0;
        int e = n-1;
        
        return Rbinarysearch(arr, s, e, k);
    }    
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int N;
        cin>>N;
        int arr[N];
        for(int i=0;i<N;i++)
            cin>>arr[i];
        int key;
        cin>>key;
        Solution ob;
        int found = ob.binarysearch(arr,N,key);
        cout<<found<<endl;
    }
}

  // } Driver Code Ends