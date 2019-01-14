
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

int findcapital(vector<int> & T) {
	for (int i = 0; i < T.size(); i++) {
		if (T[i] == i) {
			return i;
		}
	}
}

void dfs(vector<int> & result, vector<int> & T, int currCity, int curDepth) {

	for (int i = 0; i < T.size(); i++) {
		if (result[i] >= 0) {
			continue;
		}
		if (T[i] == currCity) {
			result[i] = curDepth;
			dfs(result, T, i, curDepth + 1);
		}
	}

}

vector<int> solution(vector<int> &T) {

	vector<int> result(T.size() - 1, 0);
	vector<int> dist(T.size(), -1);
	int capital = findcapital(T);
	dist[capital] = 0;

	dfs(dist, T, capital, 1);

	for (int i = 0; i < dist.size(); i++) {
		if (dist[i] > 0)
			result[dist[i] - 1]++;
	}

	return result;
}
int main()
{
	vector<int> test = { 9, 1, 4, 9, 0, 4, 8, 9, 0, 1 };
	vector<int> result = solution(test);

	return 0;
}

