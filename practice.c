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
