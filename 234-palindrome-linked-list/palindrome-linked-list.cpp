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
    ListNode* middleNode(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* current=head;
        ListNode* next=nullptr;

        while(current){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        //3 parts

        //part 1 - finding out the middle
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        //part 2 - reverse second half
        ListNode* newHead=middleNode(slow->next);

        ListNode* first=head;
        ListNode* second=newHead;

        while(first && second){
            if(first->val!=second->val) return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};