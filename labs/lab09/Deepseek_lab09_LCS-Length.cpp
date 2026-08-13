#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    if (n == 0)
    {
        cout << 0 << endl;
        return 0;
    }

    int current_max = a[0];
    int global_max = a[0];
    int current_start = 0, current_end = 0;
    int global_start = 0, global_end = 0;

    for (int i = 1; i < n; ++i)
    {
        if (current_max + a[i] > a[i])
        {
            current_max += a[i];
            current_end = i;
        }
        else
        {
            current_max = a[i];
            current_start = current_end = i;
        }

        if (current_max > global_max)
        {
            global_max = current_max;
            global_start = current_start;
            global_end = current_end;
        }
    }

    cout << global_max << endl;
    for (int i = global_start; i <= global_end; ++i)
    {
        cout << a[i];
        if (i != global_end)
        {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}