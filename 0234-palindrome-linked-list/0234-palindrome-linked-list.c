/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rev(struct ListNode* head){
    struct ListNode* prev = NULL, * curr = head, * next = NULL;
    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if(head->next == NULL) return true;

    struct ListNode* slow = head, * fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* right = rev(slow);

    while(right != NULL){
        if(right->val != head->val) return false;
        right = right->next;
        head = head->next;
    }
    return true;
}