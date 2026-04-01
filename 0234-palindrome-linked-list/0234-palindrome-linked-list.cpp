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
    bool isPalindrome(ListNode* head) {
        if ( head == nullptr or head->next == nullptr){
            return true;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;
        }
        if ( fast != nullptr){
            slow = slow->next;
        }

        ListNode* prev = nullptr;

        while ( slow != nullptr){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        while ( prev != nullptr){
            if ( prev->val != head->val ){
                return false;
            }
            prev = prev->next;
            head = head->next;
        }

        return true;
    }
};