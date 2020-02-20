#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    int perm[][4] = {{1, 2, 3, 4},
                    {1, 2, 4, 3},
                    {1, 3, 2, 4},
                    {1, 3, 4, 2},
                    {1, 4, 2, 3},
                    {1, 4, 3, 2},
                    {2, 1, 3, 4},
                    {2, 1, 4, 3},
                    {2, 3, 1, 4},
                    {2, 3, 4, 1},
                    {2, 4, 1, 3},
                    {2, 4, 3, 1},
                    {3, 1, 2, 4},
                    {3, 1, 4, 2},
                    {3, 2, 1, 4},
                    {3, 2, 4, 1},
                    {3, 4, 1, 2},
                    {3, 4, 2, 1},
                    {4, 1, 2, 3},
                    {4, 1, 3, 2},
                    {4, 2, 1, 3},
                    {4, 2, 3, 1},
                    {4, 3, 1, 2},
                    {4, 3, 2, 1}};

    int t;
    long long int totalSum = 0;
    cin >> t;
    while (t--) {

        int req;
        cin >> req;
        int arr[4][4];
        memset(arr, 0, 16 * sizeof(int));
        for(int i = 0; i < req; ++i) {
            char temp;
            int timing;
            cin >> temp >> timing;
            arr[temp - 'A'][(timing / 3) % 4] ++;
        }

        long long int max = LONG_LONG_MIN;
        for (int i = 0; i < 24; ++i) {
            long long int sum = 0;
            vector<int> vect;
            for (int j = 0; j < 4; ++j) {
                int temp = arr[perm[i][j] - 1][j];
                vect.push_back(temp);
            }

            sort(vect.begin(), vect.end(), greater<int>());

            int count = 100;
            for (auto j = vect.begin();  j != vect.end() ; ++j) {
                if(*j != 0) {
                    sum += (count * (*j));
                } else{
                    sum -= 100;
                }
                count -= 25;
            }
            if(sum > max) {
                max = sum;
            }

        }
        cout << max << "\n";
        totalSum += max;
    }
    cout << totalSum <<"\n";

}
