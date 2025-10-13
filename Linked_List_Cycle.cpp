#include <bits/stdc++.h>

using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    void List_traverse(ListNode* list_node){
        ListNode* temp = list_node;
        while(temp != nullptr){
            cout << "Node Element : " << temp->val << " " << endl;
            temp = temp->next;
        }
    }

    bool hasCycle(ListNode *head) {

    }
};

int main()
{
    //
}
