#include<bits/stdc++.h>
using namespace std;


void find(int arr[], int n) {   
    vector<int> count(n + 1, 0);

    int repeating, missing;

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        if (count[arr[i]] == 2) {
            repeating = arr[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        if (count[i] == 0) {
            missing = i;
            break;
        }
    }

    cout << "missing=" << missing << endl;
    cout << "repeating=" << repeating << endl;
}

int main() {
    int N;
    cout<<"Enter the value of N: ";
    cin >> N;

    int arr[N];
    cout<<"Enter value: ";

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    

    find(arr, N);

    return 0;
}
