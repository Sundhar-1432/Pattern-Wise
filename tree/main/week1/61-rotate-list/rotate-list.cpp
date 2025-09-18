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
    ListNode* reverse(ListNode* head){
       
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr){
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next)return head;
        ListNode*dup=head;
        int count=0;
        while(dup){
            count++;
            dup=dup->next;
        }
        cout<<count<<" "<<k;
        if(count<k){
           k=k%count;
           if(k==0)return head;
        }
        //cout<<k;
        ListNode* demo=reverse(head);
        int cnt=0;
        ListNode* after=nullptr;
        ListNode* reversed_list=demo;
        while(reversed_list){
            cnt++;
            if(cnt==k){
                after=reversed_list->next;
                reversed_list->next=nullptr;
                break;
            }
            reversed_list=reversed_list->next;
        }
        after=reverse(after);
        ListNode* temp=demo;
        demo=reverse(demo);
        temp->next=after;
        return demo;

    }
};