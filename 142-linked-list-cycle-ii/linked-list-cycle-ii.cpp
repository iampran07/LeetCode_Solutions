/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode* ,int>mp;
        ListNode* temp=head;

        while(temp){
            if(mp.find(temp)==mp.end()){
                mp[temp]++;
                temp=temp->next;
            }
            else{
                break;
            }
        }
        return temp;
    }
};