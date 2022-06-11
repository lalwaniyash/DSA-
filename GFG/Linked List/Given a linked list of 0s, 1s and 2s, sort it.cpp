// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


 // } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int zerocount = 0;
        int onecount = 0;
        int twocount = 0;
        
        Node* temp = head;
        while(temp!=NULL){
            if(temp->data == 0){
                zerocount++;
            }
            else if(temp->data == 1){
                onecount++;
            } 
            else if(temp->data == 2){
                twocount++;
            }
            temp = temp->next;
        }
        temp = head;
        
        while(temp!=NULL){
            if(zerocount!=0){
                temp->data = 0;
                zerocount--;
            }
            else if(onecount!=0){
                temp->data = 1;
                onecount--;
            }
            else if(twocount!=0){
                temp->data = 2;
                twocount--;
            }
            temp = temp->next;
        }
     return head;   
    }
};



// { Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}  // } Driver Code Ends