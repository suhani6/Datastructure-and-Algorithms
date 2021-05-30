#include <iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string s="acvgg";
    transform(s.begin(),s.end(),s.begin(), ::toupper);
    cout<<s;

}
