#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> reverseWords(const vector<char>& a)
{

	//Reverse whole arrray
	vector<char> arr = a;
	reverse(begin(arr), end(arr));

	int first = 0;
	int last = 0;

	while (first < arr.size() && arr[first] == ' ') first++;

	while (first < arr.size()) {
		while (last < arr.size() && arr[last] != ' ')
			last++;

		for (int i = 0; i < (last - first + 1) / 2; i++)
			swap(arr[first + i], arr[last - i - 1]);

		first = last + 1;
		while (first < arr.size() && arr[first] == ' ') first++;
		last = first;
	}

	return arr;
}



int main() {
	vector<char> input = { 'p', 'e', 'r', 'f', 'e', 'c', 't', ' ', 'm', 'a', 'k', 'e', 's', ' ', 'p', 'r', 'a', 'c', 't', 'i', 'c', 'e' };

	vector<char> result = reverseWords(input);

	return 0;

}