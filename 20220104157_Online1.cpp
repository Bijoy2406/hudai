#include <bits/stdc++.h>

using namespace std;

void SMA(int m[], int x, int y, int n) {
    for (int i = x - y; i < x; i++) {
        double sma = 0;
        for (int j = i - n + 1; j <= i; j++) {
            sma += m[j];
        }
        sma /= n;
        cout << fixed << setprecision(2) << sma << " ";
    }
    cout << endl;
}

int main() {
    int x, y, n;

    cout << "size of the array: ";
    cin >> x;

    int m[x];

    cout << "elements of the array:" << endl;
    for (int i = 0; i < x; i++) {
        cin >> m[i];
    }

    cout << "y: ";
    cin >> y;

    cout << "n: ";
    cin >> n;

    if (n <= 0 || n > x) {
        cout << "average." << endl;
        return 0;
    }

    SMA(m, x, y, n);

    return 0;
}
