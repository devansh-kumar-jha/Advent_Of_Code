#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18
#define mod 1000000007
#define width 7

void dkj()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

// O(1) matrix adjustment function
void create(vector<vector<char>>& cave,int i,int j,int num)
{
    // cerr<<num<<"creating"<<" ";
    if(num==0) { for(int k=j;k<=j+3;k++) cave[i][k]='#'; }
    else if(num==1) { for(int k=j;k<=j+2;k++) cave[i][k]='#'; cave[i-1][j+1]=cave[i+1][j+1]='#'; }
    else if(num==2) { for(int k=j;k<=j+2;k++) cave[i][k]='#'; for(int k=i-1;k>=i-2;k--) cave[k][j+2]='#'; }
    else if(num==3) { for(int k=i;k>=i-3;k--) cave[k][j]='#'; }
    else { for(int k=j;k<=j+1;k++) cave[i][k]=cave[i-1][k]='#'; }
    return;
}

// O(1) sliding function for block
void slide(vector<vector<char>>& cave,int& i,int& j,int num,int flag)
{
    // cerr<<num<<"sliding"<<" ";
    if(num==0) {
        if(flag==0) { if(j>0 && cave[i][j-1]=='.') j--; }
        if(flag==1) { if(j<width-4 && cave[i][j+4]=='.') j++; }
    }
    else if(num==1) {
        if(flag==0) { if(j>0 && cave[i][j-1]=='.' && cave[i+1][j]=='.' && cave[i-1][j]=='.') j--; }
        if(flag==1) { if(j<width-3 && cave[i][j+3]=='.' && cave[i+1][j+2]=='.' && cave[i-1][j+2]=='.') j++; }
    }
    else if(num==2) {
        if(flag==0) { if(j>0 && cave[i][j-1]=='.' && cave[i-1][j+1]=='.' && cave[i-2][j+1]=='.') j--; }
        if(flag==1) { if(j<width-3 && cave[i][j+3]=='.' && cave[i-1][j+3]=='.' && cave[i-2][j+3]=='.') j++; }
    }
    else if(num==3) {
        if(flag==0) { if(j>0 && cave[i][j-1]=='.' && cave[i-1][j-1]=='.' && cave[i-2][j-1]=='.' && cave[i-3][j-1]=='.') j--; }
        if(flag==1) { if(j<width-1 && cave[i][j+1]=='.' && cave[i-1][j+1]=='.' && cave[i-2][j+1]=='.' && cave[i-3][j+1]=='.') j++; }
    }
    else {
        if(flag==0) { if(j>0 && cave[i][j-1]=='.' && cave[i-1][j-1]=='.') j--; }
        if(flag==1) { if(j<width-2 && cave[i][j+2]=='.' && cave[i-1][j+2]=='.') j++; }
    }
    return;
}

// O(1) fall function for block
int fall(vector<vector<char>>& cave,int& i,int& j,int num,int size)
{
    // cerr<<num<<"falling"<<" ";
    int ret=-1;
    if(num==0) { if(i<size-1 && cave[i+1][j]=='.' && cave[i+1][j+1]=='.' && cave[i+1][j+2]=='.' && cave[i+1][j+3]=='.') i++,ret++; }
    else if(num==1) { if(i<size-2 && cave[i+1][j]=='.' && cave[i+2][j+1]=='.' && cave[i+1][j+2]=='.') i++,ret++; }
    else if(num==2) { if(i<size-1 && cave[i+1][j]=='.' && cave[i+1][j+1]=='.' && cave[i+1][j+2]=='.') i++,ret++; }
    else if(num==3) { if(i<size-1 && cave[i+1][j]=='.') i++,ret++; }
    else { if(i<size-1 && cave[i+1][j]=='.' && cave[i+1][j+1]=='.') i++,ret++; }
    return ret;
}

void simulate(vector<vector<char>>& cave,int size,int num,int& i,int& j,string& s,int& id,int& top)
{
    int flag=0,dir=0;
    do {
        if(s[id]=='>') dir=1; else dir=0;
        id=(id+1)%(s.length());
        slide(cave,i,j,num,dir);
        flag=fall(cave,i,j,num,size);
    }while(flag!=-1);
    if(num==0) top=__min(top,i);
    else if(num==1) top=__min(top,i-1);
    else if(num==2) top=__min(top,i-2);
    else if(num==3) top=__min(top,i-3);
    else top=__min(top,i-1);
    return;
}

int32_t main()
{
    dkj();

    // Code for the programming exercise //
    // This is yet to be solved fully. It is like a CP pattern study problem. //
    string s;
    fstream fin("day17.txt", fstream::in);
    getline(fin, s);
    cout<<s.length()<<"\n";
    int size=100000;
    vector<vector<char>> cave(size,vector<char>(width,'.'));
    int counter=0,id=0,top=size;
    int limit; cin>>limit;
    while(counter<limit) {
        int i=top-4,j=2;
        if(counter%5==1) i--;
        // cerr<<"Enterred"<<" ";
        simulate(cave,size,counter%5,i,j,s,id,top);
        create(cave,i,j,counter%5);
        counter++;
        if((counter-1010)%1745==0) cout<<counter<<" "<<(size-top)<<" "<<id<<"\n";
    }
    // cerr<<"\n";
    // for(int i=top;i<size;i++) {
    //     cerr<<'|';
    //     for(int j=0;j<width;j++) cerr<<cave[i][j];
    //     cerr<<'|'<<"\n";
    // }
    // cerr<<'+';
    // for(int i=0;i<width;i++) cerr<<'-';
    // cerr<<'+'<<"\n";
    cout<<counter<<" "<<(size-top)<<" "<<id<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
