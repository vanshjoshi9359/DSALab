#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int nthLargest(vector<int>& a, int n) {
    vector<int> top;
    for (int x : a) {
        bool seen = false;
        for (int y : top)
            if (x == y) seen = true;
        if (seen) continue;
        int i = 0;
        while (i < (int)top.size() && top[i] > x) i++;
        top.insert(top.begin() + i, x);
        if ((int)top.size() > n) top.pop_back();
    }
    if (n <= 0 || (int)top.size() < n) return INT_MIN;
    return top[n - 1];
}
int main() {
    vector<int> a = {12, 35, 1, 10, 34, 1, 35, 20};
    int n = 3;
    int ans = nthLargest(a, n);
    if (ans == INT_MIN)
        cout << "Not enough distinct elements";
    else
        cout << "Nth largest distinct element = " << ans;
    return 0;
}
