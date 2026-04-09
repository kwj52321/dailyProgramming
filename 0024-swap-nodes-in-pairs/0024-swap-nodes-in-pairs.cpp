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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr){
            return head;
        }

        ListNode* recur_head = head->next->next;
        ListNode* swap_head = head->next;
        swap_head->next = head;
        swap_head->next->next = swapPairs(recur_head);

        return swap_head;        
    }
};