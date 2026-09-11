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
ListNode* merge(ListNode* a, ListNode* b) {
        if(a==NULL && b==NULL)return NULL;
        if(a==NULL)return b;
        if(b==NULL)return a;
        ListNode* ansh = new ListNode(0);
        ListNode* ans = ansh;
        while(a && b){
            if(a->val <= b->val){
                ans->next = a;
                ans=ans->next;
                a=a->next;
            }
            else{
                ans->next = b;
                ans=ans->next;
                b=b->next;
            }
        }
        while(a){
            ans->next = a;
                ans=ans->next;
            a=a->next;
        }
        while(b){
            ans->next = b;
                ans=ans->next;
                b=b->next;
        }
        return ansh->next;
    }
void ms(int l,int h,vector<ListNode*>&v){
  if(l>=h)return;
  int md = (l+h)/2;
  ms(l,md,v);
  ms(md+1,h,v);
  v[l]=merge(v[l],v[md+1]);
}
    ListNode* mergeKLists(vector<ListNode*>& a) {
        if(a.size()==0)return NULL;
        ms(0,a.size()-1,a);
        return a[0];
    }
};