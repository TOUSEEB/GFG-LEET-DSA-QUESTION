class Solution {
public:

//************POSTODER TRAVERSAL***************left->right->root
    int solve(Node* root , int &maxSum ){
        if(root==NULL) return 0 ;
        
        int leftSum = solve(root->left, maxSum);
        int rightSum = solve(root->right, maxSum);
        
        int subtreeSum = leftSum + rightSum + root->data;
        maxSum = max(subtreeSum, maxSum);
        
        return subtreeSum;
    }
    
    // Function to find largest subtree sum.
    int findLargestSubtreeSum(Node* root)
    {
        if(root==NULL) return 0;
        int maxSum = INT_MIN;
        
        
        solve(root , maxSum );
        return maxSum;
    }
};
