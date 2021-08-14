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
    
    class Compare{
        public:
            bool operator() (ListNode* l1, ListNode* l2){
                return l1->val > l2->val;
            }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* toReturn = nullptr;
        ListNode* insert;
        std::priority_queue<ListNode*, vector<ListNode*>, Compare> q;
        for(ListNode* node : lists) if(node != nullptr) q.push(node);
        while(q.size() > 0){
            ListNode* temp = q.top();
            q.pop();
            if(toReturn == nullptr){
                toReturn = new ListNode;
                toReturn->val = temp->val;
                insert = toReturn;
            }else{
                insert->next = new ListNode;
                insert->next->val = temp->val;
                insert = insert->next;
            }
            temp = temp->next;
            if(temp != nullptr) q.push(temp);
        }
        return toReturn;
    }
};