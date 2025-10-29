#include <bits/stdc++.h>

using namespace std;


//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q){
            return root;
        }
        if(p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        else if(p->val < root->val && q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else{
            return root;
        }
    }
};

// --- Helper function to build a tree based on a list of values ---
// This assumes an initial BST build or manual creation.
// For simplicity and matching the test cases, we build the tree manually.
TreeNode* build_tree_case1() {
    // Tree: [6, 2, 8, 0, 4, 7, 9, null, null, 3, 5]
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(2);
    root->right = new TreeNode(8);

    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(3);
    root->left->right->right = new TreeNode(5);

    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
    
    return root;
}

// --- Helper function to find a node by its value ---
TreeNode* find_node(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    
    // Search both left and right as this isn't strictly a BST search
    // (though in our test cases it is a BST)
    TreeNode* found = find_node(root->left, val);
    if (found) return found;
    return find_node(root->right, val);
}

// --- Helper function to clean up memory (optional but good practice) ---
void delete_tree(TreeNode* root) {
    if (!root) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}


int main() {
    Solution sol;
    
    // --- Test 1: Standard Case (LCA is the Root) ---
    cout << "\n--- Test Case 1: LCA is Root (6) ---\n";
    TreeNode* root1 = build_tree_case1();
    TreeNode* p1 = find_node(root1, 2);
    TreeNode* q1 = find_node(root1, 8);
    TreeNode* result1 = sol.lowestCommonAncestor(root1, p1, q1);
    cout << "  Nodes: p=2, q=8\n";
    cout << "  Expected LCA: 6\n";
    cout << "  Actual LCA: " << (result1 ? to_string(result1->val) : "NULL") << "\n";
    cout << "  Test Passed: " << (result1 && result1->val == 6 ? "**YES**" : "**NO**") << "\n";
    delete_tree(root1); // Clean up

    // --- Test 2: LCA is one of the nodes (p or q) ---
    cout << "\n--- Test Case 2: LCA is p (2) ---\n";
    TreeNode* root2 = build_tree_case1();
    TreeNode* p2 = find_node(root2, 2);
    TreeNode* q2 = find_node(root2, 4);
    TreeNode* result2 = sol.lowestCommonAncestor(root2, p2, q2);
    cout << "  Nodes: p=2, q=4\n";
    cout << "  Expected LCA: 2\n";
    cout << "  Actual LCA: " << (result2 ? to_string(result2->val) : "NULL") << "\n";
    cout << "  Test Passed: " << (result2 && result2->val == 2 ? "**YES**" : "**NO**") << "\n";
    delete_tree(root2); // Clean up

    // --- Test 3: Deep Ancestry ---
    cout << "\n--- Test Case 3: Deep LCA (4) ---\n";
    TreeNode* root3 = build_tree_case1();
    TreeNode* p3 = find_node(root3, 3);
    TreeNode* q3 = find_node(root3, 5);
    TreeNode* result3 = sol.lowestCommonAncestor(root3, p3, q3);
    cout << "  Nodes: p=3, q=5\n";
    cout << "  Expected LCA: 4\n";
    cout << "  Actual LCA: " << (result3 ? to_string(result3->val) : "NULL") << "\n";
    cout << "  Test Passed: " << (result3 && result3->val == 4 ? "**YES**" : "**NO**") << "\n";
    delete_tree(root3); // Clean up

    cout << "\nAll test cases executed.\n";

    return 0;
}