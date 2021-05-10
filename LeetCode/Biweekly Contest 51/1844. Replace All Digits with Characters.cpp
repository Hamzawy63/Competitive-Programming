class Solution {
public:
    char shift(char a , int delta) {
        return (char)(a + delta) ; 
    }
    string replaceDigits(string s) {
        int n = (int)s.size() ; 
        for(int i=0;i<n;i++){
            if(i%2 == 1 ) {
                s[i] = shift(s[i-1] , s[i] - '0')  ;
            }
        }
        return s ; 
    }
    
};