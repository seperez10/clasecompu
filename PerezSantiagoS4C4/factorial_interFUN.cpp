    
#include <iostream>
using namespace std;

int factorial(int, int);
int main(){
int n;
cout<<"Introduzca el valor de n";
cin>>n;
int resultado=1;
cout<<(factorial(n,resultado))<<std::endl;
return 0;
}
int factorial(int n, int resultado=1)
{
for (int i=1;i<=n;i++){
    resultado= i*resultado;
}return resultado;
}