// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  private:
    int gcd(long long a, long long b){
    if(a==0){
             return b;
         } else if(b==0){
             return a;
             
         }
        if (a>b){
           return gcd(a%b,b);
       }else{
           return gcd(a,b%a);
       }
   }
  
  public:
    vector<long long> lcmAndGcd(long long A , long long B) {
        vector<long long> ans;
        long long a = gcd(A, B);
        long long b = (A * B)/a;
        ans.push_back(b);
        ans.push_back(a);
        return ans;
        
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends