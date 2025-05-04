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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Result = new ListNode();
        ListNode* pointer = Result;
        int x = 0, y = 0, carry = 0, sum = 0;

        while (l1 != nullptr || l2 != nullptr) {
            x = (l1 != nullptr) ? l1->val : 0;
            y = (l2 != nullptr) ? l2->val : 0;
            sum = x + y + carry;   // Include the carry from the previous step
            carry = sum / 10;     // Update carry
            sum %= 10;            // Keep only the last digit

            pointer->next = new ListNode(sum);

            pointer = pointer->next;
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // If there's a carry left after the last addition
        if (carry > 0) {
            pointer->next = new ListNode(carry);
        }

        return Result->next; // Skip the dummy head
    }
};

// Helper function to create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int value : values) {
        if (head == nullptr) {
            head = new ListNode(value);
            tail = head;
        } else {
            tail->next = new ListNode(value);
            tail = tail->next;
        }
    }

    return head;
}

// Helper function to print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating test linked lists
    ListNode* l1 = createList({9, 4, 5, 2, 1});
    ListNode* l2 = createList({7, 5, 2});

    // Adding the numbers
    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Printing the result
    printList(result);

    return 0;
}
