//{ Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* getIntersection(Node* head){
        if(head==NULL) return NULL;
        Node* slow = head;
        Node* fast = head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast) return slow;
        }
        return NULL;
    }
    
    Node* getStartOfLoop(Node* head){
        if(head==NULL) return NULL;
        Node* intersection = getIntersection(head);
        if(intersection == NULL) return NULL;
        Node* slow=head;
        while(slow!=intersection){
            slow=slow->next;
            intersection=intersection->next;
        }
        return slow;
    }
    
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        if(head==NULL) return;
        Node* startOfLoop = getStartOfLoop(head);
        if(startOfLoop == NULL) return;
        Node* tmp=startOfLoop;
        while(tmp->next!=startOfLoop){
            tmp=tmp->next;
        }
        tmp->next=NULL;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends