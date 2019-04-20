#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

	void PrintVec(vector<int> & nums) {
		cout << "Printing Vector: ";
		for (int i : nums) cout << i << " ";
		cout << endl;
	}

	int partition(vector<int> & nums, int low, int high) {

		int pivot = nums[high];
		int i = (low - 1);


		for (int j = low; j < high; j++) {
			if (nums[j] <= pivot) {
				i++;
				swap(nums[i], nums[j]);
			}
		}
		swap(nums[i + 1], nums[high]);

		return (i + 1);
	}

	void quicksort(vector<int> & nums, int low, int high) {

		if (low < high) {
			int pi = partition(nums, low, high);
			quicksort(nums, low, pi - 1);
			quicksort(nums, pi + 1, high);
		}

	}


	vector<int> sortArray(vector<int>& nums) {
		quicksort(nums, 0, nums.size() - 1);
		return nums;
	}
};


int main() {

	Solution s;
	vector<int> input = { 6, 2, 1, 4, 7, 3, 8, 5 };
	vector<int> result = s.sortArray(input);
	s.PrintVec(result);


}