/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    if (root == NULL){
        return 0;
    }
    int left_len = maxDepth(root->left);
    int right_len = maxDepth(root->right);
    int max;
    if (left_len > right_len){
        max = left_len;
    } else { max = right_len; }
    return max + 1;
    
}