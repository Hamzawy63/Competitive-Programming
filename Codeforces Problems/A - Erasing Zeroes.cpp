#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <cstring>
#include <map>
#include <unordered_set>
#include <cmath>
#include <iomanip>
 
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef long long int ll;
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define f first
#define s second
#define linebreak "\n"
#define space " "
#define PI atan(1)*4
#define E 10
#define ACCURATE cout << fixed << setprecision(20)
#define MAX 1e9
#define MOD (int)(1000000007)
#define vi vector<int>
#define N (int)(1e7)
using namespace std;
 
int main() {
    IO;
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        int st = 0, end = -1;
        int edit = 0;
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] == '1') {
                st = i;
                break;
            }
        }
        for (int i = (int) s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {end = i;break ;}
        }
        for (int i = st; i <= end; i++) {
            if (s[i] == '0') edit++;
        }
        cout << edit << endl;
 
    }
    return 0;
}
