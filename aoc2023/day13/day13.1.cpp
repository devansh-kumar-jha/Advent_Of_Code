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

bool check_reflect(vector<string>& mat,int x,int flag) {
    int n=mat.size(),m=mat[0].length();
    if(flag==1) {
        for(int p=0;x-p>-1 && x+p+1<n;p++) {
            for(int j=0;j<m;j++) {
                if(mat[x-p][j]!=mat[x+p+1][j]) return false;
            }
        }
    }
    else {
        for(int p=0;x-p>-1 && x+p+1<m;p++) {
            for(int i=0;i<n;i++) {
                if(mat[i][x-p]!=mat[i][x+p+1]) return false;
            }
        }
    }
    return true;
}

int find_score(vector<string>& mat) {
    int n=mat.size(),m=mat[0].length();
    for(int i=0;i<n-1;i++) {
        bool flag=check_reflect(mat,i,1);
        if(flag==true) return (100*(i+1));
    }
    for(int j=0;j<m-1;j++) {
        bool flag=check_reflect(mat,j,2);
        if(flag==true) return (j+1);
    }
    return 0;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s; vector<string> mat;
    fstream fin("day13.txt", fstream::in);
    while(getline(fin, s)) {
        if(s=="") {
            int num=find_score(mat); ans+=num;
            // cout<<num<<"\n";
            mat={};
        }
        else mat.push_back(s);
    }
    if(!mat.empty()) {
        int num=find_score(mat); ans+=num;
        // cout<<num<<"\n";
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
