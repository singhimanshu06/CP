#include<bits/stdc++.h>
using namespace std;

int digit(int a ,long long int b){
          int x = a%10;
          int y = b%4;
         if( x==5 || x==1 || x==6 || x==0) {
                  return x;
          }
          if(y==0) {
             int num = pow(x,4);
             return num%10;
          }
          else {
                  int num = pow(x,y);
                  return num%10;
          }
}
int main()
{
        int t;
        cin>>t;
        while(t--) {
        	int a;
            long long int b;
            cin>>a;
            cin>>b;
            cout<<digit(a,b)<<endl;
        }
}