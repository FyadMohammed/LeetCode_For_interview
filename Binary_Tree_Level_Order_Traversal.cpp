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
    vector<vector<int>> levelOrder(TreeNode* root) {
        //code here
        vector<vector<int>> res;

        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int length = q.size();
            while(length--){
                TreeNode *temp = q.front();
                level.push_back(temp->val);
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
            if(!level.empty())
                res.push_back(level);
        }
        return res;
    }
};

int main() {
    // Construct the test tree:
    /*
             3
            / \
           9   20
               / \
              15  7
    */

    // Level 3
    TreeNode* node15 = new TreeNode(15);
    TreeNode* node7 = new TreeNode(7);

    // Level 2
    TreeNode* node9 = new TreeNode(9);
    TreeNode* node20 = new TreeNode(20, node15, node7);

    // Level 1 (Root)
    TreeNode* root = new TreeNode(3, node9, node20);

    Solution sol;

    // Test Case 1: Standard Tree
    vector<vector<int>> result = sol.levelOrder(root);

    cout << "Test 1: Level Order Traversal of the Tree:" << endl;

    // Expected output: [[3], [9, 20], [15, 7]]
    for (const auto& level : result) {
        cout << "[";
        for (size_t i = 0; i < level.size(); ++i) {
            cout << level[i] << (i == level.size() - 1 ? "" : ", ");
        }
        cout << "]" << endl;
    }

    cout << "\nTest 2: Empty Tree (Edge Case):" << endl;
    TreeNode* empty_root = nullptr;
    vector<vector<int>> result_empty = sol.levelOrder(empty_root);
    cout << "Result Size: " << result_empty.size() << endl; // Expected output: 0

    // Cleanup memory
    delete node15;
    delete node7;
    delete node9;
    delete node20;
    delete root;

    return 0;
}
