/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if(head==NULL) return head;

    int len = 1;
    struct ListNode *last = head;
    while(last->next!=NULL){
        len++;
        last = last->next;
    }

    //원형리스트로 만든다.
    last->next = head;
    printf("%d",len);
    //최소 이동 횟수 계산
    int new_k = k % len;
    last = head;

    //new_k 만큼 회전 후 마지막 노드를 구한다. 
    for(int i=0;i<len-1-new_k;i++){
        last = last->next;
    }
    struct ListNode *answer = last->next;
    last->next = NULL;
    

    return answer;
}


