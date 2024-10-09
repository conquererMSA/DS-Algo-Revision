#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, st, sp;
    cin>>n;
    sp=n-1;//initial value for space
    st=1; //initial value of star
    for(int i=1; i<=2*n-1; i++){
       //print space
      for(int j=1; j<=sp; j++){
        cout<<" ";
      }
      //print star
      for(int j=1; j<=st; j++){
        cout<<"*";
      }
      if(i<=n-1){
        sp--;
        st+=2;
      }else{
        sp++;
        st-=2;
      }
       cout<<endl;
    }
    return 0;
}