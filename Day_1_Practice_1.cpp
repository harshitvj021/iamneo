#include <iostream>
using namespace std;

int maxProfit(int prices[], int size) {
    int maxProfit = 0;
    for (int i = 1; i < size; i++)
        if (prices[i] > prices[i - 1])
            maxProfit += prices[i] - prices[i - 1];
    return maxProfit;
}

int main() {
    int n;
    cin >> n;
    int price[n];
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    cout << maxProfit(price, n) << endl;
    return 0;
}