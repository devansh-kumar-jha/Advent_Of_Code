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
    int ans=0; char ch;
    int flag=0;
    char a,b;
    fstream fin("day2.txt", fstream::in);
    while (fin >> noskipws >> ch) {
        if(ch==' ') continue;
        else if(ch=='\n') {
            ans+=(b-'X'+1);
            int num1=b-'X',num2=a-'A';
            if(num1==num2+1 || num1==num2-2) ans+=6;
            else if(num1==num2) ans+=3;
            // cout<<ans<<"\n";
        }
        else {
            if(flag==0) a=ch;
            else b=ch;
            flag=1-flag;
        }
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
