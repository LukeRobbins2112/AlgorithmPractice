// MaxSubarray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "limits.h"
#include <Windows.h>

struct subarrayData {

	subarrayData() {

	}

	subarrayData(int l, int r, int s) : left(l), right(r), sum(s) 
	{
		//initialized with initialization list
	}

	int left;
	int right;
	int sum;
};

subarrayData findMaxCrossingSubarray(int * arr, int low, int mid, int high) {

	int leftSum = INT_MIN;
	int sum = 0;
	int maxLeft = mid;

	for (int i = mid; i >= low; i--) {
		sum += arr[i];
		if (sum > leftSum) {
			leftSum = sum;
			maxLeft = i;
		}
	}


	int rightSum = INT_MIN;
	sum = 0;
	int maxRight = mid + 1;

	for (int i = mid + 1; i <= high; i++) {
		sum += arr[i];
		if (sum > rightSum) {
			rightSum = sum;
			maxRight = i;
		}
	}

	return subarrayData(maxLeft, maxRight, leftSum + rightSum);
}

subarrayData findMaxSubarray(int * arr, int low, int high) {

	subarrayData leftData;
	subarrayData rightData;
	subarrayData crossData;

	if (low == high)
		return subarrayData(low, high, arr[low]);
	else {
		int mid = (low + high) / 2;
		leftData = findMaxSubarray(arr, low, mid);
		rightData = findMaxSubarray(arr, mid + 1, high);
		crossData = findMaxCrossingSubarray(arr, low, mid, high);
	}

	if (leftData.sum >= rightData.sum && leftData.sum >= crossData.sum)
		return leftData;
	else if (rightData.sum >= leftData.sum && rightData.sum >= crossData.sum)
		return rightData;
	else
		return crossData;
}

int main()
{
	int values[16] = { 4, -1, -2, 6, -1, 9, -3, -2 , 12, -5, 6, 2, -1, 2, -1, 1};

	subarrayData result = findMaxSubarray(values, 0, sizeof(values) / sizeof(values[0]) - 1);

	printf("Low index: %d -- High index: %d -- Sum: %d", result.left, result.right, result.sum);
	system("PAUSE");

    return 0;
}

