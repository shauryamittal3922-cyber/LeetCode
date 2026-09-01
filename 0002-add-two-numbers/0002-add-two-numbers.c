/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* head = NULL, * tail = NULL;
    int c = 0;

    while(l1 != NULL || l2 != NULL || c != 0){
        int sum = c;

        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }

        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        c = sum/10;

        struct ListNode* newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

        newNode->val = sum % 10;
        newNode->next = NULL;

        if(head == NULL){
            head = newNode;
            tail = newNode;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}