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

// Returns a list of size 3 containing [red, green, blue] in this order.
vector<int> colors(string& s,int& i) {
    if(i>=s.length()) return {-1};
    vector<int> marbs(3,0),order(3,-1);
    int cur = 0;
    while(i<s.length()) {
        marbs[cur] = read_num(s,i); i++;
        if(s[i]=='r') { order[cur]=0; i+=3; }
        else if(s[i]=='b') { order[cur]=2; i+=4; }
        else { order[cur]=1; i+=5; }
        cur++;
        if(i>=s.length() || s[i]==';') break;
        else i+=2;
    }
    vector<int> fin(3,0);
    for(int i=0;i<3;i++) {
        if(order[i]!=-1) fin[order[i]]=marbs[i];
    }
    return fin;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    int ans=0;
    string s;
    fstream fin("day2.txt", fstream::in);
    while (getline(fin, s)) {
        int i=5,id=read_num(s,i),flag=0; i+=2;
        vector<int> marbs,mx(3,0);
        do{
            marbs=colors(s,i); i+=2;
            if(marbs[0]!=-1) {
                for(int i=0;i<3;i++) mx[i]=max(mx[i],marbs[i]);
            }
        }while(marbs[0]!=-1);
        ans+=(mx[0]*mx[1]*mx[2]);
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
