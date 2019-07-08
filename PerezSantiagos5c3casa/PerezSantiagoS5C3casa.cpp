#include <math.h>
#include<iostream>
#include <fstream>
using namespace std;
ofstream outfile;

double m, k, h, mint, maxt, puntos, t[100],x[100],vx[100],*px,*pt,*pvx;

double func2(double , double , double );

double func(double, double,double);

double Runge4(double,double,double);

int main(){
     m= 2.0;
     k= 300.0;
     mint= 0.0;
     maxt= 5.0;
     puntos = 100;
     h = 0.01;
    pt=t;
    px=x;
    pvx=vx;
    
    t[0]= 0.0;
    x[0]= 0.1;
    vx[0]= 0.0;

outfile.open("datos1.dat");
    
for (int i=1; i<puntos; i++){
    
    double k_1primero= h * func(t[i-1],x[i-1],vx[i-1]);
    double k_1primero2= h * func2(t[i-1],x[i-1],vx[i-1]);
    
    double tn1= t[i-1] + (h);
    double xn1= x[i-1] + (0.5) * k_1primero2;
    double vxn1= vx[i-1] + (0.5) * k_1primero;
    double k_2primero=  h * func(tn1,xn1,vxn1);
    double k_2primero2=  func2(tn1,xn1,vxn1);
    
    
    double tn2= t[i-1] + (h);
    double xn2= x[i-1]  + (0.5) * k_2primero2;
    double vxn2= vx[i-1]  + (0.5) * k_2primero;
    double k_3primero=  func(tn2,xn2,vxn2);
    double k_3primero2=  func2(tn2,xn2,vxn2);
        
    double tn3= t[i-1]  + h;
    double xn3= x[i-1]  +  k_3primero2;
    double vxn3= vx[i-1]  +  k_3primero;
    double k_4primero=  func(tn3,xn3,vxn3);
    double k_4primero2=  func2(tn3,xn3,vxn3);
    
    double promedio1= (k_1primero + (2 * k_2primero)+ (2 * k_3primero) +k_4primero)/6;
    double promedio2= (k_1primero2 + (2 * k_2primero2)+ (2 * k_3primero2) +k_4primero2)/6;
        
     t[i]= t[i-1] + h;
     x[i]= x[i-1] + promedio1;
     vx[i]= vx[i-1] + promedio2;
    
    
    cout << pt[i] << "," << px[i] << "," << pvx[i] << endl;


}outfile.close();

    
    return 0;}

double func(double t, double x, double vx)
{
    return vx;}


double func2(double t, double x, double vx){
    
    return (-(k/m) * x);
}



