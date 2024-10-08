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
    ListNode* merge2lists(ListNode* list1, ListNode* list2){
        ListNode* dummy= new ListNode(-1);
        ListNode* temp=dummy;
        ListNode* t1=list1;
        ListNode* t2=list2;

        while(t1 && t2){
            if(t1->val < t2->val){
                temp->next=t1;
                temp=t1;
                t1=t1->next;
            }
            else{
                temp->next=t2;
                temp=t2;
                t2=t2->next;
            }
        }

        if(t1) temp->next=t1;
        else temp->next=t2;

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        ListNode* head=lists[0];
        for(int i=1;i<lists.size();i++){
            head=merge2lists(head,lists[i]);
        }
        return head;
    }
};