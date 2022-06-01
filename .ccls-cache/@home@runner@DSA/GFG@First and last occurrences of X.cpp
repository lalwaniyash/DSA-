// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
    int firstOcc(vector<int>arr, int key){
        int n = arr.size();
        int s = 0, e = n-1;
        int mid = s + ((e-s)/2);
        int ans = -1;
        
        
        while(s <= e){
            if(arr[mid] == key){
                ans = mid;
                e = mid-1;
            }
            
            if(key > arr[mid]){
                s = mid + 1;
            }
            
            else if(key < arr[mid]){
                e = mid - 1;
            }
            
            mid = s + ((e - s)/2);
        }
        
        return ans;
        
    }
    
    
    int lastOcc(vector<int>arr, int key){
        int n = arr.size();
        int s = 0, e = n-1;
        int mid = s + ((e-s)/2);
        int ans = -1;
        
        
        while(s <= e){
            if(arr[mid] == key){
                ans = mid;
                s = mid+1;
            }
            
            if(key > arr[mid]){
                s = mid + 1;
            }
            
            else if(key < arr[mid]){
                e = mid - 1;
            }
            
            mid = s + ((e - s)/2);
        }
        
        return ans;
        
    }
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        vector<int>result;
        
        int f1 = firstOcc(arr, x);
        result.push_back(f1);
        
        if(result[0] == -1){
            return result;
        }
        
        
        else{
            int f2 = lastOcc(arr, x);
            result.push_back(f2);
        
            return result;
            
        }
        
        /*int f2 = lastOcc(arr, x);
        result.push_back(f2);
        
        return result;*/
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> ans= obj.firstAndLast(arr, n, x) ;
        for(int i:ans){
            cout<<i<<" ";
        }
        cout<< endl;
    }
    return 0;
}
  // } Driver Code Ends