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
    int ans=0; string s;
    fstream fin("day4.txt", fstream::in);
    while(getline(fin, s)) {
        int n=s.length(),i=0;
        int num1=0,num2=0,num3=0,num4=0;
        while(s[i]!='-') { num1=num1*10+(s[i]-'0'); i++; }
        i++;
        while(s[i]!=',') { num2=num2*10+(s[i]-'0'); i++; }
        i++;
        while(s[i]!='-') { num3=num3*10+(s[i]-'0'); i++; }
        i++;
        while(i!=n) { num4=num4*10+(s[i]-'0'); i++; }
        if(num1<=num3 && num4<=num2) ans++;
        else if(num3<=num1 && num2<=num4) ans++;
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
