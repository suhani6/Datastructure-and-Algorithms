#include <iostream>
#include<string>
using namespace std;
string moveallX(string s){
    if(s.length()==0){
        return "";
    }
    char ch=s[0];
    char ans= moveallX(s.substr(1));
    if(ch=='x'){
        return ans+ch;
    }
    return ch+ans;
}

int main() {
    cout<<moveallX("axxvbfxxdf")<<endl;;
}
