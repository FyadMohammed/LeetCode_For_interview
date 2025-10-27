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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL || subRoot == NULL) return root == subRoot; 
        if(isSameTree(root,subRoot) && root->val == subRoot->val){
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right,subRoot);
    }
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

int main()
{
    Solution sol;
    
    // --- Test Case 1: Successful Subtree Match ---
    
    // Define the main tree (root)
    /*
             3 
            / \
           4   5
          / \
         1   2
    */
    TreeNode* root_3 = new TreeNode(3);
    TreeNode* root_4 = new TreeNode(4);
    TreeNode* root_5 = new TreeNode(5);
    TreeNode* root_1 = new TreeNode(1);
    TreeNode* root_2 = new TreeNode(2);
    
    root_4->left = root_1;
    root_4->right = root_2;
    root_3->left = root_4;
    root_3->right = root_5;
    
    // Define the subtree to find (subRoot)
    /*
           4  
          / \
         1   2
    */
    TreeNode* sub_4 = new TreeNode(4);
    TreeNode* sub_1 = new TreeNode(1);
    TreeNode* sub_2 = new TreeNode(2);
    
    sub_4->left = sub_1;
    sub_4->right = sub_2;

    bool result1 = sol.isSubtree(root_3, sub_4);
    cout << "Test 1 (Match Expected): " << (result1 ? "TRUE" : "FALSE") << endl; // Should be TRUE

    // --- Test Case 2: Unsuccessful Subtree Match (Structural Mismatch) ---
    
    // Define a subRoot with a structural difference
    /*
           4  
          /
         1   
    */
    TreeNode* sub_4_mismatch = new TreeNode(4);
    TreeNode* sub_1_mismatch = new TreeNode(1);
    sub_4_mismatch->left = sub_1_mismatch; // Note: right child is missing (null)

    bool result2 = sol.isSubtree(root_3, sub_4_mismatch);
    cout << "Test 2 (Mismatch Expected): " << (result2 ? "TRUE" : "FALSE") << endl; // Should be FALSE

    // --- Test Case 3: Unsuccessful Subtree Match (Value Mismatch) ---
    
    // Define a subRoot with a value difference
    /*
           4  
          / \
         1   99 <--- Different value
    */
    TreeNode* sub_4_val_mismatch = new TreeNode(4);
    TreeNode* sub_1_val_mismatch = new TreeNode(1);
    TreeNode* sub_99_val_mismatch = new TreeNode(99);
    
    sub_4_val_mismatch->left = sub_1_val_mismatch;
    sub_4_val_mismatch->right = sub_99_val_mismatch;

    bool result3 = sol.isSubtree(root_3, sub_4_val_mismatch);
    cout << "Test 3 (Value Mismatch Expected): " << (result3 ? "TRUE" : "FALSE") << endl; // Should be FALSE
    
    // Clean up allocated memory (important for complete code)
    // Note: A real cleanup function would be better, but this is a simple example.
    delete root_1; delete root_2; delete root_4; delete root_5; delete root_3;
    delete sub_1; delete sub_2; delete sub_4;
    delete sub_1_mismatch; delete sub_4_mismatch;
    delete sub_1_val_mismatch; delete sub_99_val_mismatch; delete sub_4_val_mismatch;
    
    return 0;
}