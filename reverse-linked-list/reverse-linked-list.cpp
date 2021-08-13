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
    void recReverse(ListNode*& head1, ListNode* head2){
        if(head2 != nullptr){
            recReverse(head1, head2->next);
            if(head1 == nullptr){
                head1 = new ListNode(head2->val);
            }else{
                ListNode* temp = head1;
                while(temp->next != nullptr){
                    temp = temp->next;
                }
                temp->next = new ListNode(head2->val);
            }
        }
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode* newHead = nullptr;
        recReverse(newHead, head);
        return newHead;
    }
};