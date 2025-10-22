#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int level = 0;
        queue<TreeNode*>q;
        if(root != nullptr){
            q.push(root);
        }
        while(!q.empty()){
            int q_size = q.size();
            for(int i = 0;i < q_size;i++){
                TreeNode *temp = q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            level++;
        }
        return level;
    }
    //void InOrder(TreeNode* node);
    //void PreOrder(TreeNode* node);
    //void PostOrder(TreeNode* node);
};

int main()
{
    // Building the test tree:
    //         4
    //        / \
    //       2   7
    //      / \ / \
    //     1  3 6  9

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));

    Solution soln;
    cout << soln.maxDepth(root) << endl;

}

void Solution::InOrder(TreeNode *root){
    if(!root) return;
    InOrder(root->left);
    cout << root->val << " ";
    InOrder(root->right);
}

void Solution::PreOrder(TreeNode *root){
    if(!root) return ;
    cout << root->val << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void Solution::PostOrder(TreeNode *root){
    if(!root) return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->val << " ";
}
