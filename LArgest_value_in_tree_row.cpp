// Apporach 1 : BFS
// Time Complexity : O(n) ... as we are vising each node in the tree  
// Space Complexity : O(n/2) == o(n) ... maximum number of elements in queue at any time
//                                   ... which is equivalent to all leaf nodes i.e. n/2
//
// Apporach 2 : DFS
// Time Complexity : O(n) ... as we are vising each node in the tree      
// Space Complexity : O(h) ... h is hight of tree, in worst case scenario h can be equal to n
//                             in skewed tree
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :
/*
Leetcode : https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed)
*/


/**
 * 
 * Approach 1 : BFS
*/


class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            int maxVal = INT_MIN;

            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();
                if(maxVal < temp->val) maxVal = temp->val;

                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
            }

            result.push_back(maxVal);
        }
        
        return result;
    }
};



/**
 * Approach 2 : DFS
*/

class Solution {
    vector<int>result;
public:
    vector<int> largestValues(TreeNode* root) {
        dfs(root, 0);
        return result;
    }

    void dfs(TreeNode* root, int level){
        if(root == nullptr) return;

        if(level == result.size()){
            result.push_back(root->val);
        } else if(root->val > result[level]) {
            result[level] = root->val;
        }

        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
};