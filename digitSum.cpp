#include<bits/stdc++.h>
using namespace std;
/*
input:
5
213132
973894
045207
000000
055776
output:
YES
NO
YES
YES
NO
*/
int main(){
    int testCases; cin>>testCases;
    while(testCases--){
        int number; cin>>number;
        int sum1=0; int sum2=0;
        int n=1;int m=4;
        while(true){
            if(n<4){
                int x=number%10;
                sum1+=x;
                n++;
            }
            else if(m<7){
                int x=number%10;
                sum2+=x;
                m++;
                if(m==7) break;
            }
            number=number/10;
            }
            if(sum1==sum2) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
    }
    return 0;
}