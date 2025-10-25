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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        
        if((!p || !q) || (p->val != q->val)){
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right,q->right);
    }
};

class Traversal {
public:
    // Existing single-tree traversal methods (preorder, inorder, postorder, levelOrder) are kept for context.
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

    // --- CORRECTED dualTraverse FUNCTION ---
    /**
     * @brief Performs a pre-order style dual traversal on two trees, safely handling null pointers
     * and printing the values (or "NULL") at each step.
     * @param p Pointer to the current node in the first tree.
     * @param q Pointer to the current node in the second tree.
     */
    void dualTraverse(TreeNode* p, TreeNode *q){
        // 1. Base Case: Stop only when both pointers are null.
        if (!p && !q) {
            return;
        }



        // 2. Safe Access (Pre-order step): Safely print the value or "NULL" if the node is missing.
        // This prevents the segmentation fault.
        string p_val = p ? to_string(p->val) : "NULL";
        string q_val = q ? to_string(q->val) : "NULL";

        cout << "First Tree element: " << p_val << " Second Tree element: " << q_val << endl;

        // 3. Safe Recursion: For the next call, we must safely determine the child pointers.
        // If the parent (p or q) is null, we must pass 'nullptr' for its child in the next call.
        
        // Traverse Left: Safely pass p->left or nullptr, and q->left or nullptr
        dualTraverse(p ? p->left : nullptr, q ? q->left : nullptr);
        
        // Traverse Right: Safely pass p->right or nullptr, and q->right or nullptr
        dualTraverse(p ? p->right : nullptr, q ? q->right : nullptr);
    }
};

// Helper function to clean up memory
void deleteTree(TreeNode* root) {
    if (root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    cout << "--- Dual Traversal Example ---" << endl;
    
    // Tree 1 (Asymmetrical)
    //       1
    //      / \
    //     2   3
    //    / \ /
    //   4   5 6
    TreeNode *tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->left->left = new TreeNode(4);
    tree1->left->right = new TreeNode(5);
    tree1->right = new TreeNode(3);
    tree1->right->left = new TreeNode(6); // Node 3 has left child 6, right is NULL

    // Tree 2 (Asymmetrical, different shape on the right)
    //       1
    //      / \
    //     2   3
    //    / \   \
    //   4   5   6
    TreeNode *tree2 = new TreeNode(1);
    tree2->left = new TreeNode(3);
    tree2->left->left = new TreeNode(4);
    tree2->left->right = new TreeNode(5);
    tree2->right = new TreeNode(2);
    tree2->right->right = new TreeNode(6); // Node 3 has right child 6, left is NULL

    Traversal t;

    cout << "Performing dualTraverse (Pre-order style):" << endl;
    // The previous code would crash here when trying to access tree2->right->left->val 
    // where tree2->right->left is NULL (on step 13 in the trace).
    t.dualTraverse(tree1, tree1);

    Solution soln;
    if(soln.isSameTree(tree1,tree1)){
        cout << " Same Tree" << endl;
    }
    else{
        cout << "Not the same tree" << endl;
    }

    // Cleanup
    deleteTree(tree1);
    deleteTree(tree2);
    
    return 0;
}
