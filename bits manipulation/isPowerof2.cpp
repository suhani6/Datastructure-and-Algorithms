#include <iostream>
using namespace std;
bool ispowof2(int n){
    return (n && !(n & n-1));
}
int main() {
     cout<<ispowof2(16);
}
