#include <iostream>
#include <vector>
#include <regex>
#include <bits/stdc++.h>
 
 
using namespace std;
 
bool well(string s1, string s2, string s3) {
    int k = (int) s1.length();
    bool ok = true;
    for (int i = 0; i < k; ++i) {
        bool f = s1[i] == s2[i] && s3[i] == s2[i];
        bool l = s1[i] != s2[i] && s3[i] != s2[i];
        if (!(f || l)) { return false; }
    }
    return true;
}
 




































