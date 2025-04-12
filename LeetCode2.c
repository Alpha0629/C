#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* createNewNode(int val){
	struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *result = NULL;
	struct ListNode *current = NULL;
	int carry = 0;
	
    while(l1 != NULL || l2 != NULL || carry != 0){
    	int val1 = (l1 != NULL) ? l1->val : 0;
    	int val2 = (l2 != NULL) ? l2->val : 0;
    	
    	int sum = val1 + val2 + carry;
    	int now = sum % 10;
    	carry = sum / 10; //0或1 
    	
    	if(result == NULL){
    		result = createNewNode(now);
    		current = result;
		} else {
			current->next = createNewNode(now);
			current = current->next;
		}
		
		if(l1 != NULL) l1 = l1->next;
		if(l2 != NULL) l2 = l2->next;
	}
	
	return result;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // 示例1: 342 + 465 = 807
    struct ListNode* l1 = createNewNode(2);
    l1->next = createNewNode(4);
    l1->next->next = createNewNode(3); 

    struct ListNode* l2 = createNewNode(5);
    l2->next = createNewNode(6);
    l2->next->next = createNewNode(4);

    struct ListNode* result = addTwoNumbers(l1, l2);
    printList(result); // 输出: 7 0 8

    // 释放内存
    free(l1->next->next);
    free(l1->next);
    free(l1);
    free(l2->next->next);
    free(l2->next);
    free(l2);
    free(result->next->next);
    free(result->next);
    free(result);

    return 0;
}
