#include <bits/stdc++.h>

using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Traversal {
public:
    void preorder(TreeNode* root) {
        if (!root) return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }

    void postorder(TreeNode* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        cout << root->val << " ";
    }

    void levelOrder(TreeNode* root) {
        if (!root) return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* node = q.front(); q.pop();
                cout << node->val << " ";
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cout << endl; // newline for each level
        }
    }
};


class Solution {
public:
int checkHeight(TreeNode* node){
            
            if (node == nullptr){
                return 0;
            }

            //Recursion to left
            int leftHeight = checkHeight(node->left);

            if(leftHeight == -1){
                return -1;
            }
            
            //Recursion to right
            int rightHeight = checkHeight(node->right);

            if(rightHeight == -1){
                return -1;
            }

            if(abs(leftHeight-rightHeight) > 1){
                return -1;
            }

            return 1 + max(leftHeight,rightHeight);
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1; 
}
};

int main() {
    // Constructing a level-5 binary tree:
    //
    //                    1
    //                 /     \
    //               2         3
    //             /   \      / \
    //           4      5    6   7
    //          / \    / \      / 
    //         8  9  10 11    14
    //        /       \
    //       15        16
    //
    // Some nodes are missing intentionally to make it asymmetrical.

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->right->left = new TreeNode(14);

    root->left->left->left->left = new TreeNode(15);
    root->left->right->left->right = new TreeNode(16);

    Traversal t;

    cout << "Preorder: ";
    t.preorder(root);
    cout << "\nInorder: ";
    t.inorder(root);
    cout << "\nPostorder: ";
    t.postorder(root);
    cout << "\nLevel Order:\n";
    t.levelOrder(root);

    Solution soln;
    cout << soln.isBalanced(root) << endl;
    return 0;
}