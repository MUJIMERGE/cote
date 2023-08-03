// https://softeer.ai/practice/info.do?idx=1&eid=395
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool cost(int* &a1, int* &a2) {
	if(a1[1] == a2[1]) return a1[0] > a2[0];
	else return a1[1] > a2[1];
}

int main(int argc, char** argv)
{
	int n, w;
	vector<int*> vec;
	int result = 0;

	cin >> w >> n;

	for(int i = 0; i < n; i++) {
		int m, p;
		cin >> m >> p;
		int* arr = new int[2];
		arr[0] = m;
		arr[1] = p;
		vec.push_back(arr);
	}

	sort(vec.begin(), vec.end(), cost);

	for(int i = 0; i < n; i++) {
		int m = vec[i][0];
		int p = vec[i][1];
		if (w >= m) {
			w -= m;
			result += m*p;
		} else {
			result += w*p;
			break;
		}
	}

	cout << result;

	return 0;
}