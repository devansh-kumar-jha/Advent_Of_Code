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

int read_num(string& s,int& i)
{
    int num=0;
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    return num;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=INT32_MAX;
    vector<vector<int>> seeds(8);
    string s;
    fstream fin("day5.txt", fstream::in);
    for(int part=0;part<8;part++) {
        getline(fin, s);
        map<vector<int>,vector<int>> mapping;
        do {
            if(part==0) {
                int i=7;
                while(i<s.length()) {
                    seeds[part].push_back(read_num(s,i));
                    i++;
                }
            }
            else if(s[0]<'0' || s[0]>'9') continue;
            else {
                int i=0; int a=read_num(s,i);
                i++; int b=read_num(s,i);
                i++; int c=read_num(s,i);
                mapping[{b,b+c-1}]={a,a+c-1};
            }
        }while(getline(fin, s) && s!="");

        if(part>0) {
            for(auto it:seeds[part-1]) {
                seeds[part].push_back(it);
                for(auto range:mapping) {
                    if(it<range.first[0] || it>range.first[1]) continue;
                    seeds[part].back()=range.second[0]+(it-range.first[0]);
                    break;
                }
            }
        }
        // for(int i=0;i<seeds[part].size();i++) cout<<seeds[part][i]<<" ";
        // cout<<"\n";
    }
    for(int i=0;i<seeds[7].size();i++) ans = (((ans) < (seeds[7][i])) ? (ans) : (seeds[7][i]));
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
