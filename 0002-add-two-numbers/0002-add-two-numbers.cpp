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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0, cur = 0;
        cur = l1->val +l2->val;
        c = cur/10;
        ListNode* head = new ListNode (cur%10);
        ListNode* temp = head;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 && l2){
            cur = c + l1->val +l2->val;
            ListNode* newnode = new ListNode (cur%10);
            temp->next = newnode;
            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
            c = cur/10;
        }
        while(l1){
            cur = c + l1->val;
            ListNode* newnode = new ListNode (cur%10);
            temp->next = newnode;
            temp = temp->next;
            l1 = l1->next;
            c = cur/10;
        }
        while(l2){
            cur = c + l2->val;
            ListNode* newnode = new ListNode (cur%10);
            temp->next = newnode;
            temp = temp->next;
            l2 = l2->next;
            c = cur/10;
        }
        if (c){
            ListNode* newnode = new ListNode (c);
            temp->next = newnode;
        }
        return head;
    }
};