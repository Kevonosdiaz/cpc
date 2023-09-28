#include <iostream>
#include <stack>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int curr;
    stack<int> st;

    int res = 0;

    for (int i = 0; i < n; i++) {
        cin >> curr;
        // Remove the previous and don't add the current
        if (!st.empty() && (st.top() + curr) % 2 == 0) {
            st.pop();
            res--;
        } else {
            st.push(curr);
            res++;
        }
    }

    cout << res;
    return 0;
}