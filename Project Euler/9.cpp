#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define space " "
int main() {
    for (int i = 0; i <= 1000; i++) {
        for (int j = i + 1; j <= 1000; j++) {
            if(2000*i + 2000*j - 2 * j * i == 1000*1000) {
                cout << i << space << j << space << 1000 - i - j  << space ;
                cout << i * j *1LL *  (1000 - i  - j ) <<endl;
            }
        }
    }
}
