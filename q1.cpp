#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<int> s;
    bool dup = false;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        if (s.count(x)) dup = true;
        else s.insert(x);
    }

    cout << (dup ? "true" : "false") << endl;
    return 0;
}
