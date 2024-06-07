#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(NULL) {}
};

class Solution{
public:
    ListNode* mergeSort(ListNode*& head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* mid = middle(head);
        ListNode* newhead = mid->next;
        mid->next = NULL;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(newhead);

        return mergeList(left, right);
    }

    ListNode* middle(ListNode*& head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* mergeList(ListNode* left, ListNode* right) {
        if (left == NULL || right == NULL) {
            return (left == NULL) ? right : left;
        }

        ListNode* ans = new ListNode(0);
        ListNode* curr = ans;

        while (left != NULL && right != NULL) {
            if (left->val <= right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }

        if (left != NULL) {
            curr->next = left;
        }
        if (right != NULL) {
            curr->next = right;
        }

        return ans->next;
    }

    void printLinkedList(ListNode* head) {
        ListNode* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    ListNode* head = new ListNode(12);
    ListNode* node1 = new ListNode(-1);
    ListNode* node2 = new ListNode(1);
    ListNode* node3 = new ListNode(10);
    ListNode* node4 = new ListNode(0);
    ListNode* node5 = new ListNode(91);
    ListNode* node6 = new ListNode(0);
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Solution s;
    s.printLinkedList(head);  // Print the original linked list

    head = s.mergeSort(head);  // Update the head pointer after sorting

    s.printLinkedList(head);  // Print the sorted linked list

    return 0;
}
