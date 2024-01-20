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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(!head)return nullptr;
        if(!head->next)return head;
        if(l == r) return head;
        ListNode *temp = head;
        ListNode *prev = nullptr;
        ListNode *prevleft = nullptr;
        ListNode *left = nullptr;
        ListNode *right = nullptr;
        int count = 1;
        if(l == 1){
            left = head;
            count = 1;
        }
        else{
            while(count!=l){
                prevleft = temp;
                temp = temp->next;
                ++count;
            }
            left = temp;
        }
        prev = left;
        // cout<<prevleft->val<<" ";
        while(temp && count<=r){
            if(count > l) {
                ListNode *t = temp->next;
                temp->next = prev;
                prev = temp;
                temp = t;
                
            }
            else{
               prev = temp; 
               temp = temp->next;                 
            }
            ++count;
            
        }
        
        right = prev;
        if(prevleft)prevleft->next = right;
        if(temp)left->next = temp;
        else left->next = nullptr;
        if(!prevleft){
            return right;
        }
        
        return head;

    }
};
