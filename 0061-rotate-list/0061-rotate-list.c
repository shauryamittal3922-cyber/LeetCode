/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head == NULL || head->next == NULL) return head;

    int n = 1;
    struct ListNode* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
        n++;
    }

    k = k % n;
    if(k == 0) return head;
    tail->next = head;

    struct ListNode* new_tail = head;
    for(int i = 0; i < n-k-1; i++){
        new_tail = new_tail->next;
    }

    struct ListNode* new_head = new_tail->next;
    new_tail->next = NULL;

    return new_head;
}