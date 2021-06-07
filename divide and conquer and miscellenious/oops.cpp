#include <iostream>
#include<string>
using namespace std;
class student{
    public:
    string name;
    int age;
    bool gender;

    student(string s, int a, int g){
        name=s;
        age=a;
        gender=g;
    }

    void print(){
        cout<<name;
        cout<<age;
    }
};
int main() {
    student arr[3];
    for(int i=0;i<3;i++){
        cin>>arr[i].name;
        cin>>arr[i].age;
    }
    for(int i=0;i<3;i++){
        arr[i].print();
    }
}
