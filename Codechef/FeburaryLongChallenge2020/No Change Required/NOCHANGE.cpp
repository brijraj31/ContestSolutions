#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        int *arr = new int[n];
        bool flag = true;
        int index = -1;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
            if(flag && (p % arr[i] != 0)) {
                flag = false;
                index = i;
            }
        }
        if(!flag) {
            cout << "YES ";
            for (int i = 0; i < n; ++i) {
                if(i != index) {
                    cout << "0 ";
                } else{
                    cout << (int)(ceil((p * 1.0) / arr[index])) <<" ";
                }
            }
            cout << "\n";
            continue;
        }


        for (int i = 1; i < n; ++i) {
            if(arr[i] % arr[i - 1] != 0) {
                index = i - 1;
                flag = false;
                break;
            }
        }

        if(!flag) {
            cout << "YES ";
            for(int i = 0; i < n; ++i) {
                if(i == index) {
                    cout << (int)(ceil((p * 1.0 - arr[index + 1]) / arr[index])) << " ";
                }
                else if(i == index + 1) {
                    cout << "1 ";
                } else cout << "0 ";
            }
            cout << "\n";
            continue;
        }

        cout << "NO\n";
    }
}
