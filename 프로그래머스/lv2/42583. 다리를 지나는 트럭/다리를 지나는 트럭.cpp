#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <numeric> // accumulate 배열으 ㅣ합

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	queue<int> trucks;
	for (int i : truck_weights) {
		trucks.push(i);
	}

	deque<int> on_bridge(bridge_length, 0);
	
	while (!on_bridge.empty()) {
		answer++;
		on_bridge.pop_front();

		int hap = accumulate(on_bridge.begin(), on_bridge.end(), 0);
		int front = 0;
		if (!trucks.empty()) {
			front = trucks.front();
		}
		
		if (trucks.empty() && hap == 0) break;

		if (hap + front  <= weight) {
			if (!trucks.empty()) {
				trucks.pop();
			}

			on_bridge.push_back(front);
		}
		else {
			on_bridge.push_back(0);
		}
	}
	
	return answer;
}