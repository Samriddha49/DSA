/*
	Program to enter a user-defined node and create a cycle at a given count.
*/


#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

struct NODE{
	int val;
	struct NODE *next;
};
typedef struct NODE NODE;

struct NODE *createLL(int n) {
	struct NODE *head = NULL;
	struct NODE *currentEnd, *tmp2;

	while (n-- > 0) {
		printf("Enter value: ");

		if (head == NULL) {
			head = (struct NODE *) malloc(sizeof(struct NODE));
			scanf("%d", &(head->val));
			head->next = NULL;

			head->next = NULL;
			currentEnd = head;

		} else {
			struct NODE *tmp2 = (struct NODE *) malloc(sizeof(struct NODE));
			scanf("%d", &(tmp2->val));
			tmp2->next = NULL;

			currentEnd->next = tmp2;
			currentEnd = currentEnd->next;
		}


	}

	return head;
}


NODE* createCycle(struct NODE *head, int cycleStart, int length) {
	int nodeCount = 1;
	NODE *currentNode = head;
	NODE *cycleStartNode;

	while (nodeCount < length){
		if (nodeCount == cycleStart) {
			cycleStartNode = currentNode;
		}
		
		currentNode = currentNode->next;
		nodeCount++;
	}

	currentNode->next = cycleStartNode;
    return head;
}

bool cycle_detection (NODE * head) 
{ 
NODE * fast = head; 
NODE * slow = head;
		
while (fast && fast->next) 
{ 
slow = slow->next;
		
fast = fast->next->next; 
if (slow == fast) 
 return true; 
}
		
return false; 
}

int main() {
	int length;
	printf("Enter size of Linked List: ");
	scanf("%d", &length);

	struct NODE *head = createLL(length);

	int cycleStart;
	printf("Enter cycle start node count: ");
	scanf("%d", &cycleStart);

	createCycle(head, cycleStart, length);

    if(cycle_detection(createCycle(head,cycleStart,length)))
    printf("Yes");
    else
    printf("No");
}
