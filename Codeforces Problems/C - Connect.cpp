#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
bool visited[55][55];
vector<pair<int, int> > vec1;
vector<pair<int, int> > vec2;
string grid[55];
int n;
void bfs(int x, int y, int a){
    if (x<0 || x>=n  || y<0 || y>=n || visited[x][y] || grid[x][y]=='1') return;
    if(a)vec1.push_back(make_pair(x,y));
    else vec2.push_back(make_pair(x,y));
    visited[x][y]=true;
    bfs(x+1,y,a);
    bfs(x,y+1,a);
    bfs(x,y-1,a);
    bfs(x-1,y,a);
}
int getanswer() {
int ans=1e8;
if (!vec2.size()) return 0;
    for (int i = 0; i < vec1.size(); ++i) {
        for (int j = 0; j < vec2.size(); ++j) {
            ans =min(ans , (vec1[i].first-vec2[j].first)*(vec1[i].first-vec2[j].first)+(vec1[i].second-vec2[j].second)*(vec1[i].second-vec2[j].second));
        }
    }
return  ans;
}
int main() {
        cin >> n;
        int x1,x2,y1,y2;
        cin >> x1; x1--;
        cin >> y1; y1--;
        cin >> x2; x2--;
        cin >> y2; y2--;
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        bfs(x1,y1,1);
        bfs(x2,y2,0);
        cout<<getanswer();
        return 0;
 
    }
