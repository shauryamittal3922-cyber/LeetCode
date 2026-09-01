/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    *returnSize = 2;
    int* res = (int *)malloc(2*sizeof(int));
    res[0] = -1;
    res[1] = -1;
    if(!head->next->next) return res;

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;
    int cp1 = -1;
    int cp2 = -1;
    int min = INT_MAX;
    int i = 1;

    while(curr->next != NULL){
        if((curr->val > prev->val && curr->val > curr->next->val) || (curr->val < prev->val && curr->val < curr->next->val)){
            if(cp1 == -1){
                cp1 = i;
                cp2 = i;
            }
            else{
                if(i - cp2 < min) min = i - cp2;
                cp2 = i;
            }
        }

        prev = curr;
        curr = curr->next;
        i++;
    }

    if(cp1 == cp2) return res;

    res[0] = min;
    res[1] = cp2 - cp1;
    return res;
}