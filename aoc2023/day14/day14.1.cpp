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
    int num=0,flag=0;
    if(s[i]=='-') { flag=1; i++; }
    while(i<s.length() && s[i]>='0' && s[i]<='9') { num=num*10+(s[i]-'0'); i++; }
    if(flag==0) return num;
    else return (-1*num);
}

void push_north(vector<string>& mat) {
    int n=mat.size(),m=mat[0].length();
    for(int j=0;j<m;j++) {
        int cur=0;
        for(int i=0;i<n;i++) {
            if(mat[i][j]=='#') cur=(i+1);
            else if(mat[i][j]=='.') continue;
            else { swap(mat[cur][j],mat[i][j]); cur++; }
        }
    }
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s; vector<string> mat;
    fstream fin("day14.txt", fstream::in);
    while(getline(fin, s)) mat.push_back(s);
    push_north(mat);
    int n=mat.size(),m=mat[0].length();
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(mat[i][j]=='O') ans+=(n-i);
        }
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
