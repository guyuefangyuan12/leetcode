#include<vector>
#include<queue>
using namespace std;

class SeatManager
{
public:
	SeatManager(int n)
	{
		seat.push(1);
	}

	int reserve()
	{
		int temp = seat.top();
		seat.pop();
		if (seat.empty())
		{
			seat.push(temp + 1);
		}
		return temp;
	}

	void unreserve(int seatNumber)
	{
		seat.push(seatNumber);
	}
private:
	priority_queue<int,vector<int>,greater<int>> seat;
};

int main() {
	SeatManager* s = new SeatManager(2);
	s->reserve();
	s->unreserve(1);
	s->reserve();
	s->reserve();
	s->unreserve(2);
	s->reserve();
	s->unreserve(1);
	s->reserve();
	s->unreserve(2);
	s->reserve();
}