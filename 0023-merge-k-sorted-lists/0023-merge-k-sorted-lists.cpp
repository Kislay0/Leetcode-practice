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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode* head = nullptr;
        vector<int> pos(n , 0);
        pair<int,int> mini = {-1, 100001};
        bool flag = true;
        for (int i = 0; i<n; i++){
            if(lists[i] == nullptr) continue;
            flag = false;
            if(lists[i]->val < mini.second){
                mini = {i, lists[i]->val};
            }
        }
        if (flag) return head;
        head = lists[mini.first];
        ListNode* temp = head;
        lists[mini.first]= lists[mini.first]->next;
        flag = true;
        while (true){
            flag = true;
            mini = {-1, 100001};
            for (int i = 0; i<n; i++){
                if(lists[i] == nullptr) continue;
                flag = false;
                if(lists[i]->val < mini.second){
                    mini = {i, lists[i]->val};
                }
            }
            if (flag) break;
            temp->next = lists[mini.first];
            lists[mini.first] = lists[mini.first]->next;
            temp = temp->next;
        }
        return head;
    }
};