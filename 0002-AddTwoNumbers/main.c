#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

int get_rdigit_rmove(int* number)
{
	int result = *number % 10;
	*number = *number / 10;
	return result;
}

struct ListNode* llist_create(int number)
{
	if (number <= 0)
		return NULL;

	int rdigit;
	struct ListNode* hnode = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	struct ListNode* cnode = hnode;

	while (number != 0)
	{
		cnode->val = get_rdigit_rmove(&number);

		if (number != 0)
		{
			struct ListNode* next = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			cnode->next = next;
			cnode = next;
		}
	}

	return hnode;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

	struct ListNode* hresult = (struct ListNode*)calloc(1, sizeof(struct ListNode));
	struct ListNode* cresult = hresult;

	int buf = 0;

	do 
	{	
		int v1,v2;

		v1 = (l1) ? l1->val : 0;
		v2 = (l2) ? l2->val : 0;	

		cresult->val = ( v1 + v2 + buf ) % 10;
		printf("%d + %d + %d\n", v1, v2, buf);
		buf = ( v1 + v2 + buf > 9 ) ? 1 : 0;

		if (l1)
			l1 = l1->next;

		if (l2)
			l2 = l2->next;

		if (l1 || l2 || buf)
		{
			cresult->next = (struct ListNode*)calloc(1, sizeof(struct ListNode));
			cresult = cresult->next;
		}

	} while (l1 != NULL || l2 != NULL || buf);

	return hresult;
}

int main()
{
	// int l1[] = { 2, 4, 3 }; 
	// int l2[] = { 5, 6, 4 };
	// int expected_output[] = { 7, 0, 8 };

	struct ListNode* l1 =	llist_create(9999999);
	struct ListNode* l2 = llist_create(9999);

	struct ListNode* result = addTwoNumbers(l1, l2);
}
