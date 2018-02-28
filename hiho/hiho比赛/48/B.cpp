#include <bits/stdc++.h>
using namespace std;
int num[109];
void fun(int L, int R)
{
    if(L > R)
        return ;
    int Min = num[L], Mini = L;
    for(int i = L; i <= R; i ++)
    {
        if(num[i] < Min)
        {
            Min = num[i];
            Mini = i;
        }
    }
    cout << Min << endl;
    fun(L, Mini - 1);
    fun(Mini + 1, R);
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> num[i];
    fun(0, n-1);
    //system("pause");
    return 0;
}