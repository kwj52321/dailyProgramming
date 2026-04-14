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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;

        if (head == nullptr || head->next == nullptr){ return nullptr;}

        while ((fast->next != nullptr) && (fast->next->next != nullptr)) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        
        if (fast->next == nullptr){
            prev->next = slow->next;
            delete slow;
        } else {
            prev = slow;
            slow = slow->next;
            prev->next = slow->next;
            delete slow;
        }
        return head;
    }
};