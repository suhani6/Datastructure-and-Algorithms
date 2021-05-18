#include <iostream>
using namespace std;
int decimalToBin(int n){
    int x=1;
    int ans= 0;
    while(x<=n)
        x*=2; 
    x/=2;
    while(x>0){
        int last=n/x;
        n-=last*x;
        x/=2;
        ans=ans*10+last;
    
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    cout<<decimalToBin(n);
}
