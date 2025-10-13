#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    
 };


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast_ptr = head;
        ListNode *slow_ptr = head;
        while(fast_ptr != nullptr || fast_ptr->next != nullptr){
            
            fast_ptr = fast_ptr->next->next;
            slow_ptr = slow_ptr->next;
            
            if(fast_ptr == slow_ptr){
                return true;
            }
        }
        return false;
    }
};

int main()
{
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;
    
    Solution sol;
    cout << sol.hasCycle(node1) << endl;
}