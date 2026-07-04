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
    //finding the middle of the linkedlist 
       ListNode* Findmiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;//slight change
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
       }
     //merging the two lists now
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val < list2->val) {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }

    if (list1) temp->next = list1;
    else temp->next = list2;

    return dummyNode->next;
}


  // this is the main  function
    ListNode* sortList(ListNode* head) {
        
        if(head==nullptr ||head->next==nullptr) return head;
        //calling a functn for finding the middle
        ListNode* middle=Findmiddle(head);
        //left part of ll after dividing 
        ListNode* left=head;//left vali yha se start
        //right part of ll after dividing 
        ListNode* right=middle->next;//right vali ll yha se start
        middle->next=nullptr;//ye imp hai because left vali ka last mai nullptr bhi to dena hai beacuse uske pass to kkoi nullptr hai hi nhi 
       

       //again calling the left part
       left =sortList(left);
       //again calling the right part
       right =sortList(right);

       //now the main imp last step is to merge the lists
       return mergeTwoLists(left , right);
    }
};