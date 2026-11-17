#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
int longestSubarray(vector<int>& a, int k) {
    deque<int> maxQ, minQ;
    int left = 0, best = 0;
    for (int right = 0; right < (int)a.size(); right++) {
        while (!maxQ.empty() && a[maxQ.back()] < a[right])
            maxQ.pop_back();
        maxQ.push_back(right);
        while (!minQ.empty() && a[minQ.back()] > a[right])
            minQ.pop_back();
        minQ.push_back(right);
        while (a[maxQ.front()] - a[minQ.front()] > k) {
            if (maxQ.front() == left) maxQ.pop_front();
            if (minQ.front() == left) minQ.pop_front();
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
}
int main() {
    vector<int> stress = {8, 2, 4, 7};
    int k = 4;
    cout << "Maximum group size = " << longestSubarray(stress, k);
    return 0;
}
