#include<iostream>
using namespace std;


int main(){
int n;
cout<<"Introduzca el valor de n";
cin>>n;
double result=1;
for (int i=1;i<=n;i++){
    result= i*result;}
cout<<result<< endl;
return 0;

}