#include <bits/stdc++.h>
using namespace std;
vector<int> sieveOfEratosthenes(int n)
{
    vector<bool> v(n + 1, true);
    v[0] = false;
    v[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (v[i] == true)
        {
            for (int j = i * i; j <= n; j += i)
            {
                v[j] = false;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < n + 1; i++)
    {
        if (v[i] == true)
        {
            ans.push_back(i);
        }
    }
    return ans;
}