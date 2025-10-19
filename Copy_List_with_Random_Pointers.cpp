#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << "Val: " << temp->val << ", ";
        if (temp->random)
            cout << "Random: " << temp->random->val;
        else
            cout << "Random: NULL";
        cout << "\n";
        temp = temp->next;
    }
    cout << "---------------------\n";
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head ==nullptr)
            return nullptr;
        Node *current = head;
        while(current){
            Node *nxt = current->next;

            current->next = new Node(current->val);
            current->next->next = nxt;
            current = nxt;
        }
        current = head;
        while(current){
            if(current->random !=nullptr){
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        Node *curr1 = head;
        Node* Head = head->next;
        while(curr1){
            Node* cp = curr1->next;
            curr1->next = cp->next;
            if(cp->next)
                cp->next = cp->next->next;
            curr1 = curr1->next;
        }

        return Head;
    }
};

int main() {
    // Create nodes
    Node* n1 = new Node(7);
    Node* n2 = new Node(13);
    Node* n3 = new Node(11);
    Node* n4 = new Node(10);
    Node* n5 = new Node(1);

    // Connect next pointers
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    // Connect random pointers
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n1;

    cout << "Original List:\n";
    printList(n1);

    Solution sol;
    Node* copied = sol.copyRandomList(n1);

    cout << "Copied List:\n";
    printList(copied);

    // Clean up memory (optional for demonstration)
    // Normally you’d free both lists, omitted for brevity

    return 0;
}
