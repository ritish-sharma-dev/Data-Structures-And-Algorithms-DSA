// LEETCODE - 25


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLL(ListNode* head, ListNode* t1){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != t1){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) { 
        if (head == NULL || head->next == NULL ) return head;
        int cnt = 0;
        ListNode* t1 = head;
        while (t1 != NULL && cnt != k){
            cnt++;
            t1 = t1->next;
        }

        if (cnt == k){
            ListNode* tail = head;
            head = reverseLL(head, t1);
            ListNode* newHead = reverseKGroup(t1, k);
            tail->next = newHead;
        }
        return head;
    }
};