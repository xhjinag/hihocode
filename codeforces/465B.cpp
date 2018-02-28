#include <iostream>
using namespace std;
int main()
{
    int n;
    string str;
    cin >> n;
    cin >> str;
    int above = 0,below = 0, ans = 0, x = 0, y = 0;
    for(int i = 0; i < n; i ++)
    {
        if(str[i] == 'U')
            y ++;
        else
            x ++;
       // cout << x << y << above << below;
        if(x > y)
        {
            below = 1;
            if(above == 1)
            {
                ans ++;
                above = 0;
            }
        }
        if(x < y)
        {
            above = 1;
            if(below == 1)
            {
                ans ++;
                below = 0;
            }
        }
    }
    cout << ans << endl;
    //system("pause");
    return 0;
}