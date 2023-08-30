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
    ListNode* merge(ListNode* a,ListNode* b){
       
        if (a==nullptr)
            return b;
        if (b==nullptr) 
            return a;

        ListNode* result = nullptr;
        if (a->val <= b->val) {
            result = a;
            result->next = merge(a->next, b);
        } 
        else {
            result = b;
            result->next = merge(a, b->next);
        }
        return result;
    }
  
    ListNode* merge_sort(ListNode* head){
        
        if (head==nullptr || head->next==nullptr) 
            return head;

        ListNode*slow=head;
        ListNode*fast=head->next;

        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode*second=slow->next;
        slow->next=NULL;

        ListNode*left=merge_sort(head);
        ListNode*right=merge_sort(second);
        
        return merge(left,right);

    }
    ListNode* sortList(ListNode* head) {
        return merge_sort(head);
    }
};
