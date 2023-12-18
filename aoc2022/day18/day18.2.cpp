#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007
#define width 7

void dkj() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int read_num(string& s,int& i) {
    if(i>=s.length()) return 0;
    int num=0,flag=0;
    if(s[i]=='-') { flag=1; i++; }
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    if(flag==0) return num;
    else return (-1*num);
}

int counter(vector<vector<int>>& points)
{
    
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day18.txt", fstream::in);
    vector<vector<int>> points;
    while(getline(fin, s)) {
        int i=0;
        int x=read_num(s,i); i++;
        int y=read_num(s,i); i++;
        int z=read_num(s,i);
        points.push_back({x,y,z});
    }
    int ans=counter(points);
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
