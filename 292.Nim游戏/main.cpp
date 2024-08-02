
class Solution {
public:
	int canWin(int n, int turn) {
		if (n <= 3) {
			if (turn == 1)
				return 1;
			else return -1;
		}
		if (turn == 1) {
			if ((canWin(n - 1, turn * (-1)) + canWin(n - 2, turn * (-1)) + canWin(n - 3, turn * (-1))) == -3)
				return -1;
			else return 1;
		}
		else {
			if ((canWin(n - 1, turn * (-1)) + canWin(n - 2, turn * (-1)) + canWin(n - 3, turn * (-1))) == 3)
				return 1;
			else return -1;
		}

	}
	bool canWinNim(int n) {
		if (canWin(n, 1) == 1)
			return true;
		else return false;
	}
};

int main() {
	Solution s;
	bool x;
	x = s.canWinNim(35);
}