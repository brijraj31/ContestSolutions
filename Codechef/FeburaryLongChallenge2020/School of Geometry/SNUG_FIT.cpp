#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t; // number of test cases
    std :: cin >> t;
    while (t-- > 0) {

        int size; // size of the input array

        std :: cin >> size;

        int* arr = new int[size];
        int* brr = new int[size];

        for(int i = 0; i < size; ++i) {
            std :: cin >> arr[i];
        }

        for(int i = 0; i < size; ++i) {
            std :: cin >> brr[i];
        }



        std :: sort(arr, arr + size);
        std :: sort(brr , brr + size);


        long long int count = 0;

        for(int i = 0; i < size; ++i) {
            count += std :: min(arr[i], brr[i]);
        }

        std :: cout << count << "\n";

    }
}
