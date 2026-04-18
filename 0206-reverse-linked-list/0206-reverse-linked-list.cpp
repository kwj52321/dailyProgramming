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
    ListNode* normal_head = nullptr;
    ListNode* reverse_head = nullptr;
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr ) {
            return head;
        } else {
            reverse_helper(head);
            return reverse_head;
        }
    }

    ListNode* reverse_helper(ListNode* node){
        ListNode* prev;
        if (node->next == nullptr) {
            reverse_head = node;
        } else {
            prev = reverse_helper(node->next);
            prev->next = node;
            node->next = nullptr;            
        } 
        return node;
    }
};