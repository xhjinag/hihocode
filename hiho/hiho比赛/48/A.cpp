# include <bits/stdc++.h>
using namespace std;
double node[109][2];
double dis(int x1,int y1, int x2, int y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
int main()
{
    int n;
    double D = 0;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> node[i][0] >> node[i][1];
        if(i >= 1) 
        D += dis(node[i][0], node[i][1], node[i-1][0], node[i-1][1]);
    }
    double DD1 = 0;
    int j;
    for(j = 1; j < n; j ++)
    {
        DD1 += dis(node[j][0], node[j][1], node[j-1][0], node[j-1][1]);
        if(DD1 * 2 >= D)
        break;
    }
    double len = dis(node[j][0], node[j][1], node[j-1][0], node[j-1][1]);
    double DD2 = DD1 - len;
    double DD3 = D/2 - DD2;
    double px = 0, py = 0;
    px = DD3/len * (node[j][0] - node[j-1][0]);
    py = DD3/len * (node[j][1] - node[j-1][1]);
    printf("%.1lf %.1lf", node[j-1][0] + px, node[j-1][1] + py);
    //cout << node[j-1][0] + px << " " << node[j-1][1] + py << endl;
    system("pause");
    return 0; 
} 