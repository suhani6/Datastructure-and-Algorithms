#include <iostream>
using namespace std;
int octalToDec(int n){
    int ans=0;
    int x=1;
    while(n>0){
        int y=n%10;
        ans+=x*y;
        x*=8;
        n=n/10;
    }
    return ans;
}
int main() {
    int n;
    cin>>n;
    cout<<octalToDec(n);
}