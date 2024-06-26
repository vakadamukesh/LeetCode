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
vector<TreeNode*>solve(int s,int e)
{
    if(s>e)
    return {NULL};
    if(s==e)
    {
        TreeNode *u=new TreeNode(s);
        return {u};
    }
    vector<TreeNode*>res;
    for(int i=s;i<=e;i++)
    {
       vector<TreeNode*>l=solve(s,i-1);
        vector<TreeNode*>r=solve(i+1,e);
        for(TreeNode *ll:l)
        {
            for(TreeNode *rr:r)
            {
                TreeNode *root=new TreeNode(i);
                root->left=ll;
                root->right=rr;
                res.push_back(root);
            }
        }
    }
    return res;
}
    vector<TreeNode*> generateTrees(int n) {
     return solve(1,n);   
    }
};