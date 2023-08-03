// https://softeer.ai/practice/info.do?idx=1&eid=584
#include<stdio.h>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int n, m;
	vector<int*> nVec;
	vector<int*> mVec;
	int repeat = 0;
	int nCnt = 0;
	int mCnt = 0;
	int result = 0;

	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		int nn, nm;
		int* arr = new int[2];
		scanf("%d %d", &nn, &nm);
		arr[0] = nn;
		arr[1] = nm;
		nVec.push_back(arr);
	}

	for (int i = 0; i < m; i++) {
		int mn, mm;
		int* arr = new int[2];
		scanf("%d %d", &mn, &mm);
		arr[0] = mn;
		arr[1] = mm;
		mVec.push_back(arr);
	}

	while(nCnt < nVec.size() && mCnt < mVec.size()) {
		int nLen = nVec[nCnt][0];
		int mLen = mVec[mCnt][0];
		int nSpd = nVec[nCnt][1];
		int mSpd = mVec[mCnt][1];

		if (nLen < mLen) {
			mLen -= nLen;
			nLen = 0;
			nVec[nCnt][0] = nLen;
			mVec[mCnt][0] = mLen;
			nCnt++;
		} else if (mLen < nLen) {
			nLen -= mLen;
			mLen = 0;
			nVec[nCnt][0] = nLen;
			mVec[mCnt][0] = mLen;
			mCnt++;
		} else {
			nCnt++;
			mCnt++;
		}

		int check = 0;
		if (nSpd < mSpd) check = mSpd - nSpd;
		if (check > result) result = check;
	}

	printf("%d", result);

	return 0;
}