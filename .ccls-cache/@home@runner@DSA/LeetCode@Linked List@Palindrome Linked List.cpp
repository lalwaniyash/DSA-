/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool check(vector<int>arr){
        int n = arr.size();
        int s = 0;
        int e = n-1;
        
        while(s<=e){
            if(arr[s++]!=arr[e--]) return 0;
        }
        return 1;
    }
    
    
    bool isPalindrome(ListNode* head) {
        
        vector<int>arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        return check(arr);
        
    }
};