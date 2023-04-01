移除数组中的val值
int removeElement(int* nums, int numSize, int val)
{
	int src = 0, dst = 0;
	while (src < numSize)
	{
		if(nums[src] != val)
		{
			nums[dst++] = nums[src++];
		}
		else
		{
			src++;
		}
	}
	return dst;
}

移除数组中的重复值
int removeDuplicates(int* nums, int numSize)
{
	int src = 0, dst = 0;
	while (src < numSize)
	{
		if (nums[src] == nums[dst])
		{
			src++;
		}
		else
		{
			nums[dst++] = nums[src++];
		}
	}
}

将两个数组合并且按升序排列
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
	int end1 = m - 1, end2 = n - 1;
	int end = m + n - 1;

	while (end1 >= 0 && end2 >= 0)
	{
		if (nums1[end1] > nums2[end2])
		{
			nums1[end--] = nums1[end1--];
		}
		else
		{
			nums1[end--] = nums2[end2--];
		}
	}

	while (end2 >= 0)
	{
		nums1[end--] = nums2[end2--];
	}
}

找出链表倒数第k个元素的值
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	struct ListNode* slow, * fast;
	slow = fast = pListHead;
	//fast先走k步
	while (k--)
	{
		fast = fast->next;
	}

	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return slow;
}

//合并两个有序链表
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
	struct ListNode* head, * tail;
	//带哨兵位的头结点
	head = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
	tail->next = NULL;

	while (list1 && list2)
	{
		if (list1 && list2)
		{
			tail->next = list1;
			tail = tail->next;

			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			tail = tail->next;

			list2 = list2->next;
		}
	}
	if (list1)
		tail->next = list1;
	if (list2)
		tail->next = list2;

	struct ListNode* list = head->next;
	free(head);
	return list;
}

//链表分割（c++）
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		struct ListNode* greaterhead, * greatertail, * lesshead, * lesstail;
		greaterhead = greatertail = (struct ListNode*)malloc(sizeof(struct ListNode));
		lessehead = lesstail = (struct ListNode*)malloc(sizeof(struct ListNode));
		greatertail->next = NULL;
		lesstail->next = NULL;

		struct ListNode* cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				lesstail->next = cur;
				lesstail = lesstail->next;
			}
			else
			{
				greatertail->next = cur;
				greatertail = greatertail->next;
			}

			cur = cur->next;
		}

		lesstail->next = greaterhead->next;
		greatertail->next = NULL;

		struct ListNode* head = lesshead->next;
		free(greaterhead);
		free(lesshead);

		return head;
	}
};

倒序链表
struct ListNode* reverseList(struct ListNode* head) {
	if (head == NULL)
		return NULL;

	struct ListNode* n1, * n2, * n3;
	n1 = NULL;
	n2 = head;
	n3 = n2->next;
	while (n2)
	{
		//倒指向
		n2->next = n1;

		//迭代
		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;
	}

	return n1;
}

找链表的中间结点
struct ListNode* middleNode(struct ListNode* head) {
	struct ListNode* slow, * fast;
	slow = fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

//链表的回文结构
//要求时间复杂度为O(N),空间复杂度为O(1)
//1->2->3->2->1
//1->2->2->1
