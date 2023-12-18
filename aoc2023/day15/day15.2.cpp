#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define inf 1e18

struct ListNode {
    string label;
    int focal;
    struct ListNode* next;
};

void incx(ListNode** head,ListNode** tail,string label,int focal,int flag) {
    if(flag==0) {
        ListNode *temp=(*(head)); int done=0;
        while(temp!=NULL) {
            if(temp->label==label) {
                temp->focal=focal;
                done=1; break;
            }
            temp=temp->next;
        }
        if(done==0) {
            ListNode* temp=new ListNode;
            temp->label=label; temp->focal=focal; temp->next=NULL;
            if((*(tail))!=NULL) (*(tail))->next=temp;
            (*(tail))=temp;
            if((*(head))==NULL) (*(head))=temp;
        }
    }
    else {
        ListNode *temp=(*(head)),*prev=NULL;
        while(temp!=NULL) {
            if(temp->label==label) {
                if(prev!=NULL && (temp->next)!=NULL) prev->next=temp->next;
                else if(prev!=NULL) { prev->next=NULL; (*(tail))=prev; }
                else if((temp->next)!=NULL) (*(head))=temp->next;
                else { (*(head))=NULL; (*(tail))=NULL; }
                delete temp; break;
            }
            prev=temp; temp=temp->next;
        }
    }
    return;
}

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
        if(it=='-' || it=='=') break;
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
    vector<ListNode*> head(256,NULL),tail(256,NULL);
    fstream fin("day15.txt", fstream::in);
    getline(fin, s);
    for(int i=0;i<s.length();i++) {
        if(s[i]==',' || i==s.length()-1) {
            if(i==s.length()-1 && s[i]!=',') t.push_back(s[i]);
            // cout<<t<<"\n";
            int num=hash_string(t);
            // cout<<num<<"\n";
            string label=((t.back()=='-')?(t.substr(0,t.length()-1)):(t.substr(0,t.length()-2)));
            int focal=(t.back()-'0'),flag=((t.back()=='-')?1:0);
            // cout<<label<<" "<<num<<" "<<focal<<" "<<flag<<"\n";
            // return 0;
            incx(&head[num],&tail[num],label,focal,flag); t="";
        }
        else t.push_back(s[i]);
    }
    // return 0;
    for(int i=0;i<256;i++) {
        struct ListNode* temp=head[i]; int j=0;
        while(temp!=NULL) {
            int num=((i+1)*(j+1)*(temp->focal)); ans+=num;
            // cout<<num<<"\n";
            temp=(temp->next); j++;
        }
    }
    cout<<ans<<"\n";
    //

    cerr<<"Time:"<<1000*((double)clock())/(double)CLOCKS_PER_SEC<<"ms/n";
    return 0;
}
