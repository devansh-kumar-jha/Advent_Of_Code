#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18

void dkj()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    char ch; string s;
    fstream fin("day1.txt", fstream::in);
    while (getline(fin, s)) {
        int cur1=-1,cur2=-1;
        for(auto ch:s) {
            if(ch<'0' || ch>'9') continue;
            else {
                if(cur1==-1) cur1=(ch-'0');
                cur2=(ch-'0');
            }
        }
        if(cur1!=-1) ans=(ans+cur1*10+cur2);
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
