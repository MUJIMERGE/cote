// https://softeer.ai/practice/info.do?idx=1&eid=407
#include<stdio.h>

using namespace std;

int main(int argc, char** argv)
{
	long long k, p, n;
	long long mod = 1000000007;
	long long multi = 1;
	long long result;

	scanf("%d %d %d", &k, &p, &n);

	for (int i = 0; i < n; i++) {
		multi = (multi*p)%mod;
	}
	result = (multi*k)%mod;
	printf("%d", result);
	
	return 0;
}