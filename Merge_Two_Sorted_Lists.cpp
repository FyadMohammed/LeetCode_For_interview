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
    //Traversal
    ListNode* head;
    Solution() : head(nullptr){}
    void List_traverse(ListNode* list_node){
        ListNode* temp = list_node;
        while(temp != nullptr){
            cout << "Node Element : " << temp->val << " " << endl;
            temp = temp->next;
        }
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode *head = nullptr;
        ListNode *tail = nullptr,*temp;

        while(list1&&list2){
            int val;
            if(list1->val <= list2->val){
                val = list1->val;
                list1 = list1->next;
            }
            else{
                val = list2->val;
                list2 = list2->next;
            }
            ListNode *newNode = new ListNode(val);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                tail = newNode;
            }

        }
        if(list1)tail->next=list1;
        if(list2)tail->next=list2;
        return head;
    }
};

int main()
{
    Solution soln1;
    cout << "Linked List 1: " << endl;
    ListNode* node = new ListNode(1);
    ListNode *head = node;
    ListNode* prev = node;

    node = new ListNode(2);
    prev->next = node;
    prev = node;
    node = new ListNode(4);
    prev->next = node;
    node->next = nullptr;
    soln1.List_traverse(head);

    cout << "List 2:" << endl;
    node = new ListNode(1);
    ListNode* head2 = node;
    prev->next = node;
    prev = node;
    node = new ListNode(3);
    prev->next = node;
    prev = node;
    node = new ListNode(4);
    prev->next = node;
    node->next = nullptr;
    soln1.List_traverse(head2);

    cout << "Merged List:" << endl;
    ListNode *merged_list = soln1.mergeTwoLists(head,head2);
    soln1.List_traverse(merged_list);
}
