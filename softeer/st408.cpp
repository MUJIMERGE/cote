// https://softeer.ai/practice/info.do?idx=1&eid=408
#include<iostream>


using namespace std;

int main(int argc, char** argv)
{
	int num[8];
	int cond;

	cin >> num[0] >> num[1] >> num[2] >> num[3] >> num[4] >> num[5] >> num[6] >> num[7];

	if (num[0] == 1) {
		cond = 1;
	} else if (num[0] == 8) {
		cond = -1;
	} else {
		cout << "mixed";
		return 0;
	}

	for (int i = 1; i < 8; i++) {
		if ((num[i] - num[i-1]) != cond) {
			cout << "mixed";
			return 0;
		}
	}

	if (cond == 1) cout << "ascending";
	else cout << "descending";

	return 0;
}