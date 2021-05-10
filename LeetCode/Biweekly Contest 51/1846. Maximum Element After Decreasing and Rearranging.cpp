class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        int n =(int)a.size() ; 
        if(!std::is_sorted(a.begin() , a.end())) {
            sort(a.begin() , a.end()) ; 
        }
        if(a[0] > 1 ) {
            a[0] = 1 ; 
        }
        for(int i=1;i<n;i++){
            if(abs(a[i] - a[i-1]) > 1  ) {
                a[i] = a[i-1] + 1  ;
            }
        }
        return a[n-1] ;
        
    }
};