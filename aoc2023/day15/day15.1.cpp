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

int hash_string(string pat) {
    int cur=0;
    for(auto it:pat) {
        // if(it=='-' || it=='=') break;
        cur+=it; cur=(cur*17)%256;
    }
    return cur;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    // cin>>num_cycles;
    string s,t=""; vector<string> mat;
    fstream fin("day15.txt", fstream::in);
    getline(fin, s);
    for(int i=0;i<s.length();i++) {
        if(s[i]==',' || i==s.length()-1) {
            if(i==s.length()-1 && s[i]!=',') t.push_back(s[i]);
            int num=hash_string(t); ans+=num; t="";
            // cout<<num<<"\n";
        }
        else t.push_back(s[i]);
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
