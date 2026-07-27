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
int ans=INT_MIN;
int solve(TreeNode* root){
    if(root==nullptr) return 0;

    int leftgain=max(0,solve(root->left));
    int rightgain=max(0,solve(root->right));
    int currpath=root->val + leftgain +rightgain;
    ans =max(ans,currpath);

    return root->val + max(leftgain,rightgain);

}
    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
        
    }
};
