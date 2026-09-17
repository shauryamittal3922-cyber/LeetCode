/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* slow = NULL, * fast = head;

    for(int i = 0; i < n; i++){
        fast = fast->next;
    }
    if(fast == NULL) return head->next;
    slow = head;

    while(fast->next != NULL){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;
    return head;
}