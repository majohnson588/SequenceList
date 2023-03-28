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

