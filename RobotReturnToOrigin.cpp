#include <utility>
#include <unordered_map>
#include <string>
#include <iostream>

/*
*
* PROBLEM DESCRIPTION
*
There is a robot starting at position (0, 0), the origin, on a 2D plane. 
Given a sequence of its moves, judge if this robot ends up at (0, 0) after it completes its moves.
The move sequence is represented by a string, and the character moves[i] represents its ith move. 
Valid moves are R (right), L (left), U (up), and D (down). 
If the robot returns to the origin after it finishes all of its moves, return true. Otherwise, return false.
*/

class Solution {
public:

	struct Pos {
		int x = 0;
		int y = 0;

		void operator+=(const std::pair<int, int> & move) {
			this->x += move.first;
			this->y += move.second;
		}

		bool atOrigin() {
			return (this->x == 0 && this->y == 0);
		}
	};



	bool judgeCircle(std::string moves) {

		Pos robotPos;

		std::unordered_map<char, std::pair<int, int>> moveDir;
		moveDir.emplace('U', std::pair<int, int>{ 0, 1 });
		moveDir.emplace('D', std::pair<int, int>{ 0, -1 });
		moveDir.emplace('L', std::pair<int, int>{ -1, 0 });
		moveDir.emplace('R', std::pair<int, int>{ 1, 0 });

		for (char c : moves) {
			robotPos += moveDir[c];
		}

		return robotPos.atOrigin();
	}
};

int main() {

	std::string returnInput = "LLURDLURDR";
	std::string noReturnInput = "RLRUDDLRDD";

	Solution s;
	bool returnResult = s.judgeCircle(returnInput);
	bool noReturnResult = s.judgeCircle(noReturnInput);

	std::cout << "First result: " << returnResult << std::endl;
	std::cout << "Second result: " << noReturnResult << std::endl;
	system("pause");

	return 0;
}