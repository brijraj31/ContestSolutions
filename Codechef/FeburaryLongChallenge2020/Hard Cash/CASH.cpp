#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        long long int count = 0;
        for(int i = 0; i < n; ++i) {
            int temp;
            cin >> temp;
            count = (count + temp) % k;
        }

        cout << count << "\n";


    }
}
