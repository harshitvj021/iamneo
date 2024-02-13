#include <iostream>
using namespace std;

void subarraySum(int arr[], int n, int s, int &start, int &end) {
    int sum = 0;
    start = 0;
    end = -1;
    int i = 0, st = 0;

    while (i < n) {
        sum += arr[i];

        while (sum > s) {
            sum -= arr[st];
            st++;
        }

        if (sum == s) {
            start = st + 1;
            end = i + 1;
            return;
        }
        i++;
    }
}

int main() {
    int l, sum;
    cin >> l;
    int arr[l];
    cin >> sum;
    for (int i = 0; i < l; i++) {
        cin >> arr[i];
    }

    int start = 0, end = -1;
    subarraySum(arr, l, sum, start, end);

    if (end == -1) {
        cout << "-1";
    } else {
        cout << start << " " << end;
    }
    return 0;
}