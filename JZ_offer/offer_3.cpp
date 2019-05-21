/*
 * 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 *
 * Note: The returned array must be malloced, assume caller calls free().
 * 这里定义链表长度最大为10，或者以0作为结束数字
 */
#include <cstdio>
#include <malloc.h>

#define LEN sizeof(struct ListNode)
#define MAXLength 10

struct ListNode{
    int val;
    struct ListNode *pNext;
};

void printListReversingly(struct ListNode* pHead) {
    int array[10];
    int i;
    for (i = 0; i<10 ; i++) {
        array[i] = pHead->val;
        if(pHead->val == 0){
            i++;
            break;
        }else{
            pHead = pHead->pNext;
        }
    }
    for (int j = i-1; j >= 0 ; j--) {
        printf("%d ",array[j]);
    }
}

int main(){
    struct ListNode *pHead,*pTail,*pNew;//构造链表指针，pHead是头指针，pTail是尾指针，pNew是每次要动态添加的指针
    pHead = (struct ListNode *)malloc(LEN);
    scanf("%d",&pHead->val);
    pTail = pHead;
    int flag = 0;
    while(flag < 9 && pTail->val!=0){
        pNew = (struct ListNode*)malloc(LEN);
        scanf("%d",&pNew->val);
        pNew->pNext = NULL;
        pTail->pNext = pNew;
        pTail = pNew;
        flag++;
    }
//    printf("\n");
//    for (int i = 0;i<10; ++i) {
//        printf("%d ",pHead->val);
//        if(pHead->val == 0){
//            break;
//        }
//        pHead = pHead->pNext;
//    }
    printListReversingly(pHead);
    return 0;
}