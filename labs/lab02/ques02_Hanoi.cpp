#include <iostream>
using namespace std;

void hanoi(int n, char first, char second, char third)
{
    if (n == 1)
    {
        cout << "1 " << first << " " << second << endl;
        return;
    }
    hanoi(n - 1, first, third, second);
    cout << n << " " << first << " " << second << endl;
    hanoi(n - 1, third, second, first);
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
