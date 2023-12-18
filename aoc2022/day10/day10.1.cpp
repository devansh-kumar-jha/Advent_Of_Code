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
    int ans=0; string s;
    fstream fin("day10.txt", fstream::in);
    int cycle=1,x=1;
    while(getline(fin, s)) {
        if(s[0]=='n') cycle++;
        else {
            int num=0,i=5;
            if(s[5]=='-') i++;
            while(i<s.length()) { num=num*10+(s[i]-'0'); i++; }
            if(s[5]=='-') num=-1*num;
            cycle++;
            if((cycle-20)%40==0 && cycle<221) ans+=(cycle*x);
            x+=num; cycle++;
        }
        if((cycle-20)%40==0 && cycle<221) ans+=(cycle*x);
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
