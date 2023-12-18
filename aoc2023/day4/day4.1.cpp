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

int read_num(string& s,int i)
{
    if(s[i]==' ') return (s[i+1]-'0');
    else return (s[i]-'0')*10+(s[i+1]-'0');
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s; vector<string> mat;
    fstream fin("day4.txt", fstream::in);
    while(getline(fin, s)) {
        int i=0; map<int,int> wins;
        while(s[i]!=':') i++;
        i+=2;
        while(s[i]!='|') {
            int num = read_num(s,i);
            wins[num]++; i+=3;
        }
        int score=0; i+=2;
        while(i<s.length()) {
            int num = read_num(s,i);
            if(wins[num]>0) {
                if(score==0) score=1;
                else score=score*2;
            }
            i+=3;
        }
        ans+=score;
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
