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
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        int count = left.first + right.first + 1;
        int sum = left.second + right.second + root->val;
        int avg = sum/count;
        if(root->val == avg){
            ans++;
        }
        return {count,sum};
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};