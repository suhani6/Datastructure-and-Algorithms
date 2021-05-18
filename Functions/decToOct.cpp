#include <iostream>
using namespace std;
int decToOct(int n){
    int x=1;
    int ans=0;
    while(x<=n)
        x*=8;
    x/=8;
    while(x>0){
        int last=n/x;
        n-=last*x;
        x/=8;
        ans=ans*10+last;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    cout<<decToOct(n);
}
