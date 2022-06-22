// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    stack<int>s;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        s.push(a);
    }
    while(!s.empty()){
        int a = s.top();
        s.pop();
        q.push(a);
    }
    return q;
}
