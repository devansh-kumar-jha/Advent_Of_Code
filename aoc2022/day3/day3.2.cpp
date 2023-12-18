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
    vector<string> grp;
    fstream fin("day3.txt", fstream::in);
    while (fin >> noskipws >> ch) {
        if(ch=='\n') {
            grp.push_back(s);
            s.clear();
        }
        else s.push_back(ch);
        if(grp.size()==3) {
            map<char,int> mp[3];
            int ctr=0;
            for(auto s:grp) {
                int n=s.length();
                for(int i=0;i<n;i++) mp[ctr][s[i]]=1;
                ctr++;
            }
            for(char x='a';x<='z';x++) {
                if(mp[0][x]==1 && mp[1][x]==1 && mp[2][x]==1) {
                    ans+=(x-'a'+1);
                    break;
                }
                else if(mp[0][x+'A'-'a']==1 && mp[1][x+'A'-'a']==1 && mp[2][x+'A'-'a']==1) {
                    ans+=(x-'a'+27);
                    break;
                }
            }
            // cout<<ans<<"\n";
            grp.clear();
        }
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
