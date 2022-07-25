#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>p1, pair<int,int>p2){
    if(p1.second>p2.second)
        return true;
    else if(p1.second == p2.second && p1.first < p2.first) return true;
    return false;
}

vector<int> sortarr(int arr[], int n){
    unordered_map<int,int>mp;
    
    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }
    vector<pair<int,int>>v;
    
    for(auto it : mp){
        v.push_back({it.first, it.second});
    }
    sort(v.begin(),v.end(), comp);
    
    vector<int> ans;
    for(auto it : v){
        int s = it.second;
         while(s--){
            ans.push_back(it.first);
    }
}
    return ans;
    
}

int main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        
        for(int i = 0; i < n; i++){
            cin>>arr[i];
        }
        vector<int> ans = sortarr(arr,n);
        for(auto it:ans) cout<<it<<" ";
        
        cout<<endl;
    }
    return 0;
}