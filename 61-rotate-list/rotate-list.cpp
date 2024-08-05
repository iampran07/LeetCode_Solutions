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
    ListNode* findKnode(ListNode* head, int k){
        int cnt=1;
        while(head){
            if(cnt==k) break;
            cnt++;
            head=head->next;
        }
        return head;
    }


    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* temp=head;
        int len=1;

        while(temp->next)
        {
            len++;
            temp=temp->next;
        }

        if(k%len==0) return head;

        k=k%len;

        temp->next=head;
        ListNode* newNode=findKnode(head,len-k);

        head=newNode->next;
        newNode->next=nullptr;

        return head;
    }
};