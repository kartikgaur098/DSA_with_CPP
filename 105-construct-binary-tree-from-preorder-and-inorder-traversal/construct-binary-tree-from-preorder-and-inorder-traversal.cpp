class Solution {
public:

    int getIndex(vector<int>& inorder, int element){
        for(int i = 0; i < inorder.size(); i++){
            if(element == inorder[i]){
                return i;
            }
        }
        return -1;
    }

    TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder,
                            int inorderStart, int inorderEnd,
                            int &preorderIndex, int size){

        if(inorderStart > inorderEnd || preorderIndex >= size){
            return NULL;
        }

        int element = preorder[preorderIndex++];
        TreeNode* root = new TreeNode(element);

        int index = getIndex(inorder, element);

        root->left = constructTree(preorder, inorder, inorderStart, index - 1, preorderIndex, size);
        root->right = constructTree(preorder, inorder, index + 1, inorderEnd, preorderIndex, size);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inorderStart = 0;
        int inorderEnd = inorder.size() - 1;
        int preorderIndex = 0;
        int size = inorder.size();

        return constructTree(preorder, inorder, inorderStart, inorderEnd, preorderIndex, size);
    }
};