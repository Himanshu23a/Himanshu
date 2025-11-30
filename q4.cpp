#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        freq[arr[i]]++;
    }

    int ans = -1;
    for (int x : arr) {
        if (freq[x] == 1) {
            ans = x;
            break;
        }
    }

    cout << ans << endl;
    return 0;
}
