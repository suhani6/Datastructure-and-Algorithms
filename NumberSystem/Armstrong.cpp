#include <iostream>
#include<cmath>
using namespace std;
int main() {
    int n;
    cin>>n;
    int sum=0;
    int originaln=n;
    while(n>0){
       int last=n%10;
        sum+=pow(last,3);
        n=n/10;
    }
    if(originaln==sum){
        cout<<"is armstrong";
    }
    else{
        cout<<"not armstrong";
    }
}
