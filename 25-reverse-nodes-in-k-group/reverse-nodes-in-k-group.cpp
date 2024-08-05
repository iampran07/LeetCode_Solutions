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
    ListNode* findKnodes(ListNode* temp, int k) {
        k = k - 1;
        while (k-- && temp != NULL) {
            temp = temp->next;
        }
        return temp;
    }

    ListNode* reverseNodes(ListNode* temp) {
        ListNode* current = temp;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while (current) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while (temp) {
            ListNode* kthnode = findKnodes(temp, k);
            if (kthnode == NULL) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }
            ListNode* nextNode = kthnode->next;
            kthnode->next = nullptr;
            reverseNodes(temp);
            if (temp == head) {
                head = kthnode;
            } else {
                prevNode->next = kthnode;
            }
            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};