#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int trappedWater(vector<int>& h) {
    int left = 0, right = (int)h.size() - 1;
    int leftMax = 0, rightMax = 0, water = 0;
    while (left < right) {
        if (h[left] <= h[right]) {
            leftMax = max(leftMax, h[left]);
            water += leftMax - h[left];
            left++;
        } else {
            rightMax = max(rightMax, h[right]);
            water += rightMax - h[right];
            right--;
        }
    }
    return water;
}
int main() {
    vector<int> h = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Trapped rainwater = " << trappedWater(h);
    return 0;
}
