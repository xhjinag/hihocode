#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+9;
long long jc[100000 + 10];

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    jc[0] = 1;
    for(int i = 1; i <= 100000; i ++)
        jc[i] = jc[i-1] * i % mod;
    long long ans = 0;
    for(int i = 2; i <= min(a, n-1); i ++)
    {
        if(b >= n - i)
            ans = (ans + jc[a] * jc[b] % mod * jc[a-1] % mod *
            ksm(jc[a-i] * jc[i-1], mod - 2) * jc[b-1] % mod *
            ksm(jc[b-n+i] * jc[n-i-1], mod - 2) % mod *(i-1) % mod) % mod;
    }
    cout << ans << endl;
    system("pause");
    return 0;
}