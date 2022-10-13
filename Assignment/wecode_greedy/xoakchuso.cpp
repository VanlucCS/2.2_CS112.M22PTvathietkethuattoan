#include <iostream>
#include <math.h>
#include <stack>
#include <vector>
using namespace std;
string num;
stack <char> chuoiso;
void xoakso(int n)
{
    string ans = num;
    int k =num.size();
    if(num.size() < n)
    {
        cout<<"error";
        return;
    }
    for(int i =0 ; i < k ;i++)
    {
        //so truoc lon hon thi xoa di
        while(chuoiso.empty() == false && n > 0 && num[i] < chuoiso.top())
        {
            chuoiso.pop();
            n--;
        }
        //them so vao stack neu khac khong
        if(!chuoiso.empty() || num[i] != '0')
            chuoiso.push(num[i]);
    }
    //xoa so sau cung <=> so lon nhat
    while(chuoiso.empty()==false && n >0)
    {
        chuoiso.pop();
        n--;
    }
    if(chuoiso.empty())
        cout<<0;
    while(chuoiso.empty()== false)
    {
        ans[k-1] = chuoiso.top();
        chuoiso.pop();
        k--;
    }
    cout<< ans.substr(k);
    return;
}

int main()
{
    int n;
    cin>> num;
    cin >> n;
    xoakso(n);
    return 0;
}
