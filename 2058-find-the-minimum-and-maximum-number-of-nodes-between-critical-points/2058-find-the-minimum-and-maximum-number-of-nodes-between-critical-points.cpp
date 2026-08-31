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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
         ListNode* p = head;
         if(p==NULL || p->next == NULL || p->next->next==NULL)return {-1,-1};
         vector<int>v;
         int x=0;
         while(p->next->next){
            x++;
            ListNode* prev = p;
            ListNode* curr = p->next;
            ListNode* nxt = p->next->next;
            if((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val)){
                v.push_back(x);
            }
            p=p->next;
         }
         if(v.size()<2){
            return {-1,-1};
         }
         int mn = INT_MAX;
         for(int i=1;i<v.size();i++){
            mn = min(mn,v[i]-v[i-1]);
         }
         int mx = v[v.size()-1]-v[0];
         return {mn,mx};
    }
};