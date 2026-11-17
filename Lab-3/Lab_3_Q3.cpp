#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int circularMaxSum(vector<int>& a) {
    int total = a[0], curMax = a[0], maxSum = a[0];
    int curMin = a[0], minSum = a[0];
    for (int i = 1; i < (int)a.size(); i++) {
        total += a[i];
        curMax = max(a[i], curMax + a[i]);
        maxSum = max(maxSum, curMax);
        curMin = min(a[i], curMin + a[i]);
        minSum = min(minSum, curMin);
    }
    if (maxSum < 0) return maxSum;
    return max(maxSum, total - minSum);
}
int main() {
    vector<int> a = {5, -3, 5};
    cout << "Maximum circular subarray sum = "
         << circularMaxSum(a);
    return 0;
}
