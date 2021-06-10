#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        string res;
        if (s[0] == 'o') {
            res = "FILIPINO";
        } else if (s[0] == 'a') {












