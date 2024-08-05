/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void createCopy(Node* head){
        Node* temp=head;
        while(temp){
            Node* copy=new Node(temp->val);
            Node* nextNode=temp->next;
            temp->next=copy;
            copy->next=nextNode;
            temp=nextNode;
        }
    }

    void randompointers(Node* head){
        Node* temp=head;
        while(temp){
            Node* copy=temp->next;
            if(temp->random){
                copy->random=temp->random->next;
            }else{
                copy->random=nullptr;
            }
            temp=copy->next;
        }
    }

    Node* extractLL(Node* head){
        Node* dummyNode=new Node(-1);
        Node* res=dummyNode;
        Node* temp=head;
        while(temp){
            res->next=temp->next;
            res=res->next;
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }

    Node* copyRandomList(Node* head) {
        createCopy(head);
        randompointers(head);
        return extractLL(head);
    }
};