#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> arr = {{3, 49}, {23, 44}, {21, 56}, {26, 55}, {23, 52}, {2, 9}, {1, 48}, {3, 31}};
    int days = 57;

    sort(arr.begin(), arr.end());
    int start = arr[0][0];
    int end = arr[0][1];

    int ans = 0;
    ans += abs(start - 1);
    for (int i = 1; i < arr.size(); i++)
    {
        int first = arr[i][0];
        int second = arr[i][1];

        if (first > end)
        {
            ans += first - end - 1;
            start = first;
            end = second;
        }
        else
        {

            end = max(end, second);
        }
    }

    ans += (days - end);
    cout << ans << endl;
    return 0;
}