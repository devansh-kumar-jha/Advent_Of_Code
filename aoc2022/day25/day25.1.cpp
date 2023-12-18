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

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    string s;  int ans=0;
    fstream fin("day25.txt", fstream::in);
    while(getline(fin, s)) {
        int num=0,pow=1;
        for(int i=s.length()-1;i>-1;i--) {
            int ctr=0;
            switch(s[i]) {
                case '-': { ctr=-1; break; }
                case '=': { ctr=-2; break; }
                case '0': { ctr=0; break; }
                case '1': { ctr=1; break; }
                case '2': { ctr=2; break; }
                default: break;
            }
            num+=(ctr*pow); pow=pow*5;
        }
        ans+=num;
    }
    cerr<<ans<<"\n";
    string console="";
    while(ans>0) {
        int num=ans%5; ans=ans/5;
        if(num<=2) console.push_back('0'+num);
        else if(num==3) { console.push_back('='); ans++; }
        else { console.push_back('-'); ans++; }
    }
    reverse(console.begin(),console.end());
    cout<<console<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
