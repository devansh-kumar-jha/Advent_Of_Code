#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007
#define width 50

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

void change(int& i,int& j,int n,int m)
{
    if(i>=0 && i<=n && j>=0 && j<=m) return;
    if(i<=width) {}
    else if(i<=2*width) {}
    else if(i<=3*width) {}
    else {}
    return;
}

int next(vector<string>& mat,int& i,int& j,int n,int m,int dir) {
    int old_i=i,old_j=j,flag=0;
    if(dir==0) { do{ j++; change(i,j,n,m); }while(mat[i][j]=='0'); }
    else if(dir==1) { do{ i++; change(i,j,n,m); }while(mat[i][j]=='0'); }
    else if(dir==2) { do{ j--; change(i,j,n,m); }while(mat[i][j]=='0'); }
    else { do{ i--; change(i,j,n,m); }while(mat[i][j]=='0'); }
    if(mat[i][j]=='#') { i=old_i; j=old_j; flag=1; }
    return flag;
}

int trace_path(vector<string>& mat,string& s)
{
    int n=mat.size(),m=mat[0].length();
    int len=0,dir=0,row=0,col=0;
    for(col=0;col<m;col++) { if(mat[0][col]=='.') break; }
    // right -> dir=(dir+1)%4; left -> dir=(dir+3)%4;
    while(len<s.length()) {
        // cerr<<row<<" "<<col<<"\n";
        int num=read_num(s,len),flag=0;
        do { flag=next(mat,row,col,n,m,dir); num--; }while(num>0 && flag==0);
        if(len==s.length()) break;
        if(s[len]=='R') dir=(dir+1)%4;
        else dir=(dir+3)%4;
        len++;
    }
    int ans=1000*(row+1)+4*(col+1)+dir;
    return ans;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;
    fstream fin("day22.txt", fstream::in);
    int max_val=-1*inf;
    vector<string> mat;
    while(getline(fin, s)) {
        if(s.size()==0) break;
        mat.push_back(s);
        max_val = __max(max_val,s.length());
    }
    for(int i=0;i<mat.size();i++) {
        for(int j=0;j<max_val;j++) {
            if(j<mat[i].length() && mat[i][j]==' ') mat[i][j]='0';
            else if(j==mat[i].length()) mat[i].push_back('0');
        }
        // cerr<<mat[i]<<"\n";
    }
    getline(fin, s);
    int ans=trace_path(mat,s);
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
