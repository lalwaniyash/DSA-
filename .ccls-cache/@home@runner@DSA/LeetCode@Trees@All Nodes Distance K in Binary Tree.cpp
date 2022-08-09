/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void makeLink(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &nodeToParent, TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                nodeToParent[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                nodeToParent[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }
    
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        makeLink(root, nodeToParent, target);
        
        unordered_map<TreeNode*, bool>visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target] = true;
        int dist = 0;
        
        while(!q.empty()){
            int size = q.size();
            if(dist++ == k) break;
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(nodeToParent[curr] && !visited[nodeToParent[curr]]){
                    q.push(nodeToParent[curr]);
                    visited[nodeToParent[curr]] = true;
                }
            }
        }
        
        vector<int>ans;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;        
    }
};