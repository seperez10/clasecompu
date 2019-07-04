#include <iostream>
#include<math.h>
using namespace std;

int derivada(int point2){
    

}




int main(){
       int puntos;
cout<<"Introduzca el numero de puntos"<<endl;
    cin >> puntos;
    double inicio;
cout<<"Introduzca el valor de inicio"<<endl;
    cin >> inicio;
    double fin;
cout<<"Introduzca el valor de fin"<< endl;
cin >> fin;
double x[puntos];
double *p;
double cose[puntos];
double *p2;
p2=cose;
p=x;
double h= (fin-inicio)/(puntos-1);
x[0]= inicio;
cose[0]= cos(x[0]);
    for (int i=1; i<=puntos;i++){
        x[i]= (x[i-1])+h;
        cose[i]= cos(x[i]);
    cout << *p <<endl;
  *p++;
    cout << *p2 <<endl;
    *p2++;
    }
    
    
    
    
    return 0;}