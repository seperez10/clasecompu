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
     h = 0.46;
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
    

    double k_2primero=  (h/2.0) * func(t[i-1] + (h/2.0),x[i-1] + (h/2.0) * k_1primero, vx[i-1] + (h/2.0) * k_1primero2);
    double k_2primero2= (h/2.0) * func2(t[i-1] + (h/2.0),x[i-1] + (h/2.0) * k_1primero, vx[i-1] + (h/2.0) * k_1primero2);
    
    

    double k_3primero= (h/2.0)* func(t[i-1] + (h/2.0),x[i-1] + (h/2.0) * k_2primero,vx[i-1] + (h/2.0) * k_2primero2);
    double k_3primero2= (h/2.0)* func2(t[i-1] + (h/2.0),x[i-1] + (h/2.0) * k_2primero,vx[i-1] + (h/2.0) * k_2primero2);
        

    double k_4primero=  h * func(t[i-1] + h,x[i-1] + h * k_3primero, vx[i-1] + h * k_3primero2);
    double k_4primero2= h * func2(t[i-1] + h,x[i-1] + h * k_3primero, vx[i-1] + h * k_3primero2);
    
    double promedio1= (1.0/6.0)*h*(k_1primero +  2.0*k_2primero+  2.0*k_3primero +k_4primero);
    double promedio2= (1.0/6.0)*h*(k_1primero2 +  2.0*k_2primero2+  2.0*k_3primero2 +k_4primero2);
        
     t[i]= t[i-1] + h;
     x[i]= x[i-1] + promedio1;
     vx[i]= vx[i-1] + promedio2;
    
    
    outfile << t[i] << "," << x[i] << "," << vx[i] << endl;


}outfile.close();

    
    return 0;}

double func(double t, double x, double vx)
{
    return vx;}


double func2(double t, double x, double vx){
    
    return -(k/m) * x;
}



