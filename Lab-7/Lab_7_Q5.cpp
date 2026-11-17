#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
bool canAssign(vector<int>& tasks, vector<int>& workers,
               int pills, int strength, int count) {
    deque<int> available;
    int j = (int)workers.size() - count;
    int used = 0;
    for (int i = count - 1; i >= 0; i--) {
        while (j < (int)workers.size() &&
               workers[j] + strength >= tasks[i]) {
            available.push_back(workers[j]);
            j++;
        }
        if (available.empty()) return false;
        if (available.back() >= tasks[i]) {
            available.pop_back();
        } else {
            if (used == pills) return false;
            used++;
            available.pop_front();
        }
    }
    return true;
}
int maxTaskCount(vector<int>& tasks, vector<int>& workers,
                 int pills, int strength) {
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end());
    int low = 0, high = min(tasks.size(), workers.size());
    while (low < high) {
        int mid = (low + high + 1) / 2;
        if (canAssign(tasks, workers, pills, strength, mid))
            low = mid;
        else
            high = mid - 1;
    }
    return low;
}
int main() {
    vector<int> tasks = {3, 2, 1};
    vector<int> workers = {0, 3, 3};
    cout << "Maximum tasks completed = "
         << maxTaskCount(tasks, workers, 1, 1);
    return 0;
}
