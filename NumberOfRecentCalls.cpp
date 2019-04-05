#include <queue>

using namespace std;


/*

** Problem Description **

Write a class RecentCounter to count recent requests.
It has only one method: ping(int t), where t represents some time in milliseconds.
Return the number of pings that have been made from 3000 milliseconds ago until now.
Any ping with time in [t - 3000, t] will count, including the current ping.
It is guaranteed that every call to ping uses a strictly larger value of t than before.
*/

class RecentCounter {
public:
	RecentCounter() {
	}

	int ping(int t) {

		this->pings.push(t);

		while ((t - 3000) > this->pings.front())
			this->pings.pop();

		return this->pings.size();
	}

	std::queue<int> pings;
};


int main() {

	RecentCounter rc;

	int result1 = rc.ping(1);
	int result2 = rc.ping(40);
	int result3 = rc.ping(2999);
	int result4 = rc.ping(3001);
	int result5 = rc.ping(3050);


}