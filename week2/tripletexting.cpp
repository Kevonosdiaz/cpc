#include <iostream>

int main() {
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;

    int n = input.size();
    int p1 = 0, p2 = n/3, p3 = 2*n/3;
    for (int i = 0; i < n/3; i++) {
        if (input[p1] != input[p2] || input[p2] != input[p3]) {
            if (input[p1] != input[p2]) {
                // Whichever matches p3 is good
                if (input[p1] == input[p3]) {
                    cout << input.substr(0, n/3);
                    return 0;
                }
                else {
                    cout << input.substr(n/3, n/3);
                    return 0;
                }
            } else { 
                cout << input.substr(0, n/3);
                return 0;
            }
        }
        p1++;
        p2++;
        p3++;
    }

    cout << input.substr(0, n/3);
    return 0;
}