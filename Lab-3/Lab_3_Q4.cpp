#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> a = {-7, 1, 5, 2, -4, 3, 0};
    long long rightSum = 0, leftSum = 0;
    for (int x : a) rightSum += x;
    cout << "Equilibrium indices: ";
    bool found = false;
    for (int i = 0; i < (int)a.size(); i++) {
        rightSum -= a[i];
        if (leftSum == rightSum) {
            cout << i << " ";
            found = true;
        }
        leftSum += a[i];
    }
    if (!found) cout << "None";
    return 0;
}
