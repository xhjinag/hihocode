#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
int node[109][2];
double dp[109][109][109] = {0};
double dis(int x1, int y1, int x2, int y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
    
}
double size(int i, int j, int k) // 利用海伦公式 sqrt(p*(p-a)*(p-b)*(p-c))
{
    double dis1 = dis(node[i][0], node[i][1], node[j][0], node[j][1]);
    double dis2 = dis(node[i][0], node[i][1], node[k][0], node[k][1]);
    double dis3 = dis(node[j][0], node[j][1], node[k][0], node[k][1]);
    double p = 0.5 * (dis1 + dis2 + dis3);
    return sqrt(p * (p-dis1) * (p-dis2) * (p-dis3));
}
int main()
{
    int m,n;
    cin >> n >> m;
    for(int i = 0; i < n; i ++) 
        cin >> node[i][0] >> node[i][1];
    for(int k = 3; k <= m; k ++)
    for(int i = 0; i < n; i ++)
    {
        for(int j = i + k-1; j < n; j ++)
        {
            for(int s = i + 1; s < j; s ++)
            {
                dp[i][j][k] = max(dp[i][s][k-1] + size(i,s,j), dp[i][j][k]);
            }
        }
    }
    double ans = -1;
    for(int i = 0; i < n; i ++)
        for(int j = i + m - 1; j < n; j ++)
        {
            ans = max(ans,dp[i][j][m]);
        }
    cout << setiosflags(ios::fixed) << setprecision(2) << ans <<endl;
    //system("pause");
    return 0;
}