#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+9;
long long jc[100000+10];
long long inv[100000+200];
long long Ca[100000+10],Cb[100000+10];
void getinv(long long M)
{
    inv[1] = 1;
    for(int i = 2; i <= 100000; i ++)
    {
        inv[i] = inv[M % i] * (M - M / i) % M;
    }
}
void getfac(long long Ca[], int n, long long M)
{
    Ca[0] = 1;
    for(int i = 1; i <= n; i ++) // Ca(i) = Ca(i-1) * (n-i+1) / i
    {
        Ca[i] = Ca[i - 1] * (n - i + 1) % M * inv[i] % M;
    }
}
int main()
{
    int N,A,B;
    jc[0] = 1;
    for(int i = 1; i <= 100000; i ++)
    {
        jc[i] = jc[i-1] * i % mod;
    }
    getinv(mod);
    cin >> N >> A >> B;
    getfac(Ca, A-1, mod);
    getfac(Cb, B-1, mod);
    long long ans = 0;
    for(int i = 2; i <= min(A,N-1); i ++) // A部电影在i天看完
    {
        if(N - i <= B)
        ans = (ans + jc[A] * jc[B] % mod * Ca[i-1] % mod * Cb[N-i-1] % mod * (i-1) % mod) % mod;
    }
    cout << ans % mod << endl;
    //system("pause");
    return 0;
}