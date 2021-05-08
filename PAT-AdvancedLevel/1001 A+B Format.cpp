/*** 
 * @Author: zqliu
 * @Date: 2021-04-27 15:30:07
 * @LastEditTime: 2021-05-08 18:33:21
 * @Description: PAT
 */
#include<bits/stdc++.h>
using namespace std;
//#define DEBUG

int main()
{
#ifdef DEBUG
    freopen("1001in.txt","r",stdin);
    freopen("1001out.txt","w",stdout);
#endif
    int a,b,c;
    cin>>a>>b;
    c=a+b;
    if(c<0){
        cout<<"-";
        c*=-1;
    }else if(c==0){
        cout<<0;
        return 0;
    }
    stack<char> st;
    int cnt=0;
    while(c){
        st.push(c%10+'0');
        cnt++;
        if(cnt==3&&c>9){
            st.push(',');
            cnt=0;
        }
        c/=10;
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    return 0;
}
