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
    ListNode* merge2lists(ListNode* list1 , ListNode* list2){
        ListNode* dummyNode=new ListNode(-1);
        ListNode* temp=dummyNode;
        ListNode* t1=list1;
        ListNode* t2=list2;

        while(t1 && t2){
            if(t1->val < t2->val){
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }else{
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }

        if(t1) temp->next=t1;
        else temp->next=t2;

        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* middleNode=findMiddle(head);
        ListNode* firstHead=head;    
        ListNode* secondHead=middleNode->next;
        middleNode->next=nullptr;

        firstHead = sortList(firstHead);    
        secondHead = sortList(secondHead);

        return merge2lists(firstHead,secondHead);    
    }
};