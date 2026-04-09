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

    ListNode* left;
    bool stop = false;

    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next){
            return;
        }
        left = head;
        stop = false;

        helper(head);
    }

    void helper(ListNode* right) {
        if (!right){
            return;
        }
        helper(right->next);
        if (stop){
            return;
        }

        if (left == right || left->next == right){
            right->next = nullptr;
            stop = true;
            return;
        }
        ListNode* nextLeft = left->next;
        left->next = right;
        right->next = nextLeft;
        left = nextLeft;
    }

};