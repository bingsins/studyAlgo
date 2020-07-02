#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;
    vector< pair<int, int> > input(n);

    for(int i = 0; i < n; i++)
    {
        cin >> input[i].first;
        input[i].second = i;
    }

    sort(input.begin(), input.end());

    int res = 0;
    for(int i = 0; i < n; i++)
    {
        res = max(res, input[i].second - i);
    }

    cout << res;

    return 0;
}
