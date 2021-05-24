#include <iostream>
using namespace std;
int main() {
    int n,m;
    cin>>n>>m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
     int x;
     cin>>x;
     int r=0;
     int c=m-1;
     bool found=false;

     while(r<n and c>=0){
         if(arr[r][c]==x){
         found=true;
        }
        if(arr[r][c]>x){
            c--;
        }
        else{
            r++;
        }
     }
     if(found){
         cout<<"found";
     }
     else{
         cout<<"not found";
     }

}
