#include <iostream>
#include <cmath>
 
using namespace std;
int main() {
    long long n ;
    cin>>n;
    long long   m = n;
    long long bits = 0;
    while(m)
    {
        bits++;
        m/=10;
    }
    long long  big = (bits-1) * 9;
//    cout<<big;
    long long  carry = n - (pow(10,bits-1)-1);
    while(carry)
    {
        big+=carry%10;
        carry/=10;
    }
 
    cout<<big;
    return 0;
}
