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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int list_size = 0;
        ListNode *trav = head;
        while(trav != nullptr){
            trav = trav->next;
            list_size++;
        }
        ListNode *temp,*prev;
        if(list_size == n){
            temp = head->next;
            head->next = nullptr;
            head = temp;
        }
        else{
            prev = head;
            temp = head->next;
            int idx = 2;
            while(idx != (list_size - n + 1)){
                prev = temp;
                temp = temp->next;
                idx++;
            }
            prev->next = temp->next;
        }
        return head;
    }
};

int main()
{
    //test case will be used in all future linked list problems;
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(5);
    ListNode *node4 = new ListNode(6);
    ListNode *node5 = new ListNode(7);
    ListNode *node6 = new ListNode(8);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Solution soln;
    ListNode *final_head = soln.removeNthFromEnd(node1,1);

    ListNode *traverse = final_head;
    while(traverse != nullptr){
        cout << traverse->val << endl;
        traverse = traverse->next;
    }


    return 0;
}
