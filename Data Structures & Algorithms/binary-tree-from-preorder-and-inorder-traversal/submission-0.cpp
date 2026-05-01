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

int findPos(vector<int>& inorder, int target, int start, int end){
    for(int i = start; i <= end; i++){
        if(inorder[i] == target)
            return i;
    }
    return -1;
}

TreeNode* build(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int &index){

    if(inStart > inEnd)
        return NULL;

    TreeNode* root = new TreeNode(preorder[index]);

    int pos = findPos(inorder, preorder[index], inStart, inEnd);

    index++;

    root->left = build(preorder, inorder, inStart, pos-1, index);
    root->right = build(preorder, inorder, pos+1, inEnd, index);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int index = 0;
    return build(preorder, inorder, 0, inorder.size()-1, index);
}
};