#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define vl vector<ll>

int sol()
{
}

class Solution
{
public:
    int dp[101][101][101];
    
};

int main()
{
    Solution obj;
    int i, j, k, l, m, n, t;
    cin >> t;
    while (t--)
    {
        cin >> k >> n;
        vector<vector<int>> v(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[j][j];
            }
        }
        cout << obj.nop(n, k, v) << endl;
    }
    return 0;
}