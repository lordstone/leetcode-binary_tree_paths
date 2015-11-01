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
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> arrL, arrR, arr;
        if(root == NULL) return arr;
        if(root->right == NULL && root->left == NULL){
            string tmp = to_string(root->val) + "";
            arr.push_back(tmp);
            return arr;
        }
        arrL = binaryTreePaths(root->left);
        arrR = binaryTreePaths(root->right);
        arr.insert(arr.end(),arrL.begin(),arrL.end());
        arr.insert(arr.end(),arrR.begin(),arrR.end());
        for(int i = 0; i < arr.size(); i++){
            string tmp;
            tmp = to_string(root->val) + "->";
            arr[i] = tmp + arr[i];
        }//end for
        return arr;
    }
};
