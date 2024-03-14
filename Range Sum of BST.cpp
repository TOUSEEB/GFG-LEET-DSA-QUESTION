//Aproach1: Simple Inorder traversal
//T.C = O(n)
//S.C = O(n)
class Solution {
public:

        void  solve(TreeNode* root , int low , int high , int &sum){
            if(root==NULL) return ;

            solve(root->left , low , high , sum);
            if(root->val >= low && root->val <= high){
                sum += root->val;
            }
            solve(root->right , low , high , sum);
          
            
        }

    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL) return 0;
        int sum = 0;

         solve(root, low, high , sum);
        return sum;
    }
};

//Aproach 2 : using binary search tree property
//T.C : O(n)
//S.C : O(1) (Ignoging recursion stack space)
class Solution {
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root)
            return 0;
        
        //Within Range
        if(root->val >= low && root->val <= high) {
            return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
        }
        
        //When outside the range (Less than low) - Go right
        if(root->val < low)
            return rangeSumBST(root->right, low, high);

        //When outside the range (Greater than high) - Go left
        return rangeSumBST(root->left, low, high);
    }
};
