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
    ListNode* reverseList(ListNode* head) {
        if(head ==  nullptr|| head->next == nullptr) return head;
        ListNode* current;
        ListNode* prev;
        ListNode* temp;
        prev = head;
        temp = head->next;
        head->next = nullptr;
        while(temp->next != nullptr){
            current = temp->next;
            temp->next = prev;
            prev = temp;
            temp = current;
        }
        temp->next = prev;
        head = temp;
        return head;
    }
};

int main()
{

}
