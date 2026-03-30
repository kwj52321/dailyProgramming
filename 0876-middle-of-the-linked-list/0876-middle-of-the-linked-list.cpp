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
    ListNode* middleNode(ListNode* head) {
        ListNode* two_step = head;
        ListNode* one_step = head;
        while ( two_step != nullptr && two_step->next != nullptr){
            two_step = two_step->next->next;
            one_step = one_step->next;
        }
        return one_step; 
    }
};