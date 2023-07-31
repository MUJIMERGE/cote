#include <stdio.h>
#include <iostream>

long long mod = 1234567891;

int main() {
    int l;
    char * str;
    unsigned long long result = 0;
    
    scanf("%d", &l);
    str = new char[l];
    
    scanf("%s", str);
    
    for(int i = 0; i < l; i++) {
        int a = str[i]-96;
        unsigned long long r = a;
        for (int j = 0; j < i; j++) {
            r *= 31;
            r %= mod;
        }
        result += r;
    }
    
    printf("%lld", result%mod);
}