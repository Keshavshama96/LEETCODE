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
    ListNode* reverseList(ListNode* head) {
        ListNode*temp=head;//head ko point karega
        ListNode*prev=nullptr;//nullptr ko point karega
        while(temp!=nullptr){
            ListNode*front=temp->next;
            temp->next=prev;//reverse kar diya link
            prev=temp; //prev ko aahe bdha diya
            temp=front;
        }
        return prev;
    }
};