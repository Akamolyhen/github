#include <bits/stdc++.h>
using namespace std;
 
#define INF 1e-9
 
struct node {
    int w, h;
};
 
bool cmp(node a, node b) {
    if (a.w * a.h < b.w * b.h) return true;
    else if (a.w * a.h > b.w * b.h) return false;
    else {
        double wa = a.w, ha = a.h, wb = b.w, hb = b.h;
        double v1 = min(wa / ha, ha / wa);
        double v2 = min(wb / hb, hb / wb);
        if (v1 - v2 < -INF) return false;//v1<v2
        else if (v1 - v2 > INF) return true;//v1>v2
        else {
            if (a.w < b.w) return true;
            else return false;
        }
    }
}
 
int main() {
     
    int n;
    cin>>n;
    vector<node> res(n);
    for (int i = 0; i < n; ++i) {
        cin>>res[i].w>>res[i].h;
      
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 0; i < n; ++i) {
        cout<<res[i].w<<" "<<res[i].h<<endl;
    }
     
    return 0;
}


