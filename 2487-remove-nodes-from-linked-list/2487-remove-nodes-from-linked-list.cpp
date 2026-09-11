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
ListNode* rev(ListNode* head){
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* nxt = NULL;
   while(curr){
    nxt = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nxt;
   }
   return prev;
}
    ListNode* removeNodes(ListNode* head) {
       ListNode* h = rev(head);
       unordered_map<ListNode*,int>f;
        ListNode* hd = h;
       int mx = h->val;
       while(h){
        if(h->val < mx){
            f[h]=-1;
        }
        else if(h->val > mx){mx=h->val;}
        h=h->next;
       }
       hd = rev(hd);
       ListNode* ans = new ListNode(0);
       ListNode* t = ans;
       ListNode* p = hd;
       while(p){
        if(f[p]==0){
            t->next = p;
            t=t->next;
        }
        p=p->next;
       }
     return ans->next;
    }
};