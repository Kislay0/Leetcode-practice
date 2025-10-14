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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* r = head;
        ListNode* h = r;
        for (int i = 0; i<n; i++){
            if (h == nullptr) return head;
            h = h->next;
        }if (h == nullptr) return head->next;
        while(h->next != nullptr){
            h= h->next;
            r = r->next;
        }
        r->next = r->next->next;
        return head;
    }
};