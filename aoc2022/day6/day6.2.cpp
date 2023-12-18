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
    int ans=-1; char ch;
    string s;
    fstream fin("day6.txt", fstream::in);
    while (fin >> noskipws >> ch) s.push_back(ch);
    for(int i=13;i<s.length();i++) {
        int flag=0;
        map<char,int> mp;
        for(int j=0;j<14;j++) {
            mp[s[i-j]]++;
            if(mp[s[i-j]]==2) flag=1;
        }
        if(flag==0) { ans=i+1; break; }
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
