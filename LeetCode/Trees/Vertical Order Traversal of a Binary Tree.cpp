/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;  // <vertical, level, multinodes>
        queue<pair<TreeNode*, pair<int, int>>>todo; // <node, vertical, level>
        todo.push({ root, {0, 0}});
        
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left, {x-1,y+1}});
            }
            if(node->right){
                todo.push({node->right, {x+1,y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                for(auto r:q.second){
                    col.push_back(r);
                }
                
                //col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }    
        return ans;      
    }
};