#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;
string cleanBoard(string board) {
    bool changed = true;
    while (changed) {
        changed = false;
        for (int i = 0; i < (int)board.size();) {
            int j = i;
            while (j < (int)board.size() && board[j] == board[i]) j++;
            if (j - i >= 3) {
                board.erase(i, j - i);
                changed = true;
                break;
            }
            i = j;
        }
    }
    return board;
}
int dfs(string board, unordered_map<char, int>& hand) {
    board = cleanBoard(board);
    if (board.empty()) return 0;
    int ans = INT_MAX;
    for (int i = 0; i < (int)board.size();) {
        int j = i;
        while (j < (int)board.size() && board[j] == board[i]) j++;
        char color = board[i];
        int need = 3 - (j - i);
        if (hand[color] >= need) {
            hand[color] -= need;
            int rest = dfs(board.substr(0, i) + board.substr(j), hand);
            if (rest != -1) ans = min(ans, need + rest);
            hand[color] += need;
        }
        i = j;
    }
    return ans == INT_MAX ? -1 : ans;
}
int main() {
    string board = "WWRRBBWW", handText = "WRBRW";
    unordered_map<char, int> hand;
    for (char c : handText) hand[c]++;
    cout << "Minimum balls needed = " << dfs(board, hand) << '\n';
    return 0;
}
