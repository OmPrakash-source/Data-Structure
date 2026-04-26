#include<iostream>
using namespace std;


class ListNode{
    int val;
    ListNode *next;
    ListNode *head;
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Remove all matching nodes from the start
        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->next->val == val) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};
