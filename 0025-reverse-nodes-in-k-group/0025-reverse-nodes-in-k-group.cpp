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
    // function to get the kth node
    ListNode* kthnode(ListNode* temp, int k) {
        k = k - 1;
        while (temp != nullptr && k > 0) {
            k--;
            temp = temp->next;
        }
        return temp;
    }

    // function to reverse the linkedlist
    ListNode* reversell(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // main function
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevlast = NULL;

        while (temp != NULL) {
            ListNode* knode = kthnode(temp, k);

            if (knode == NULL) {
                if (prevlast)
                    prevlast->next = temp;
                break;
            }

            // storing the next node before reversing
            ListNode* nextnode = knode->next;

            // separate the linked list
            knode->next = NULL;

            // reverse current group
            reversell(temp);

            if (temp == head) {
                head = knode;
            } else {
                prevlast->next = knode;
            }

            // store prevlast
            prevlast = temp;

            // shift temp to next group
            temp = nextnode;
        }
        return head;
    }
};

