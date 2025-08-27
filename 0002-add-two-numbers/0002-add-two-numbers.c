/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* answer = malloc(sizeof(struct ListNode));
    struct ListNode* result = answer;
    int carry = 0;

    //l1 과 l2 중 하나라도 NULL이 아니면 반복, 최고 자리 숫자에서 carry가 발생하면 한 번 더 돌아야한다.
    while(l1!=NULL || l2!=NULL || carry!=0){
        int a = (l1!=NULL) ? l1->val : 0;
        int b = (l2!=NULL) ? l2->val : 0;
        if(l1!=NULL) l1 = l1->next;
        if(l2!=NULL) l2 = l2->next;
        int sum = a + b + carry;
        carry = sum/10;
        sum %= 10;
        result->val = sum;

        //마지막 노드의 next에는 NULL
        if(l1==NULL && l2==NULL && carry==0){
            result->next=NULL;
            break;
        }
        result->next = malloc(sizeof(struct ListNode));
        result = result -> next;

    }
    return answer;

}