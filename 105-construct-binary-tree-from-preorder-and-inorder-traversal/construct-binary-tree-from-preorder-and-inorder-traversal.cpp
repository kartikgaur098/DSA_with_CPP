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

    void createMapping(unordered_map<int , int> &valueMapping,vector<int> inorder){
        for(int i=0 ; i<inorder.size() ; i++){
            int element = inorder[i];
            int index = i;
            valueMapping[element]=index;
        }
    }
    TreeNode* constructTree(unordered_map<int , int> &valueMapping,vector<int>& preorder,vector<int>& inorder,int &preIndex, int inorderStart ,int inorderEnd, int size){
        if(preIndex >= size){    
            return NULL;
        }
        if(inorderStart>inorderEnd){
            return NULL;
        }
        int element = preorder[preIndex];
        preIndex++;
        TreeNode* root = new TreeNode(element);
        int elementIndexInsideInorder = valueMapping[element];

        root->left= constructTree(valueMapping,preorder , inorder,preIndex, inorderStart , elementIndexInsideInorder-1,size);
        root-> right= constructTree(valueMapping,preorder , inorder,preIndex, elementIndexInsideInorder+1 , inorderEnd,size);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex =0;
        int inorderStart = 0;
        int inorderEnd= inorder.size()-1;
        int size= inorder.size();
        unordered_map<int , int> valueMapping;
        createMapping(valueMapping, inorder);
        TreeNode* root = constructTree(valueMapping,preorder , inorder,preIndex, inorderStart , inorderEnd,size);
        return root;        
    }
};