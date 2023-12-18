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
        for(int i=0;i<s.length();i++) {
            int num=-1;
            if(s[i]<'0' || s[i]>'9') {
                if(i>=2) {
                    string nm=s.substr(i-2,3);
                    if(nm=="one") num=1;
                    else if(nm=="two") num=2;
                    else if(nm=="six") num=6;
                }
                if(i>=4) {
                    string nm=s.substr(i-4,5);
                    if(nm=="three") num=3;
                    else if(nm=="seven") num=7;
                    else if(nm=="eight") num=8;
                }
                if(i>=3) {
                    string nm=s.substr(i-3,4);
                    if(nm=="four") num=4;
                    else if(nm=="five") num=5;
                    else if(nm=="nine") num=9;
                }
            }
            else num=(s[i]-'0');
            if(cur1==-1 && num!=-1) cur1=num;
            if(num!=-1) cur2=num;
        }
        if(cur1!=-1) ans=(ans+cur1*10+cur2);
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
