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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        if(a==NULL && b==NULL)return NULL;
        if(a==NULL)return b;
        if(b==NULL)return a;
        ListNode* ha =  a;
        ListNode* hb =  b;
        ListNode* ansh = new ListNode(4);
        ListNode* ans = ansh;

        while(ha && hb){
            if(ha->val <= hb->val){
                ans->next = new ListNode(ha->val);
                ans=ans->next;
                ha=ha->next;
            }
            else{
                ans->next = new ListNode(hb->val);
                ans=ans->next;
                hb=hb->next;
            }
        }
        while(ha){
            ans->next = new ListNode (ha->val);
                ans=ans->next;
                ha=ha->next;
        }
        while(hb){
            ans->next = new ListNode(hb->val);
                ans=ans->next;
                hb=hb->next;
        }
        return ansh->next;
    }
};