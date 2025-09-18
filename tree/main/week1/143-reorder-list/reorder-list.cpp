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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* speed=head;

        while(speed&&speed->next){
            slow=slow->next;
            speed=speed->next->next;
        }
        
        ListNode* rev=reverse(slow);
        while(rev&&rev->next){
            ListNode* temp1=head->next;
            ListNode* temp2=rev->next;
            head->next=rev;
            rev->next=temp1;
            head=temp1;
            rev=temp2;
            
        }
       
    }
};