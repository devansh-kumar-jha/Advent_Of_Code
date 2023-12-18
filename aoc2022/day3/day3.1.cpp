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
    int ans=0; char ch;
    string s;
    fstream fin("day3.txt", fstream::in);
    while (fin >> noskipws >> ch) {
        if(ch=='\n') {
            map<char,int> mp;
            int n=s.length();
            for(int i=0;i<n/2;i++) mp[s[i]]=1;
            for(int i=n/2;i<n;i++) {
                if(mp[s[i]]==1) {
                    if(s[i]>='a' && s[i]<='z') ans+=(s[i]-'a'+1);
                    else ans+=(s[i]-'A'+27);
                    mp[s[i]]++;
                }
            }
            s.clear();
        }
        else s.push_back(ch);
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
