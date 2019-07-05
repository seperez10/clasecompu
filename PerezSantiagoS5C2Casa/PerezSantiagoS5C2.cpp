#include <math.h>
#include<iostream>
#include <fstream>
using namespace std;


double func(double x, double y){
    return -y;}




int main(){
    double H= 0.1;
    double minx= 0.0;
    double maxx= 2.0;
    int puntos = int((maxx-minx)/H);
    double x[puntos]; 
    double y[puntos];
    double *px;
    double h = (maxx-minx)/(puntos-1);
    px= x;
    double *py;
    py= y;
    x[0]= minx;
    y[0]= 1.0;
    
    double xr[puntos]; 
    double yr[puntos];
    double *pxr;
    pxr= xr;
    double *pyr;
    pyr= yr;
    xr[0]= minx;
    yr[0]= 1.0;
    
    double xl[puntos]; 
    double yl[puntos];
    double *pxl;
    pxl= xl;
    double *pyl;
    pyl= yl;
    xl[0]= minx;
    yl[0]= 1.0;
    
    ofstream outfile;
   outfile.open("datos.dat");
    //EULERRR
    for (int i=1; i<=puntos;i++){
        x[i]= (x[i-1])+h;
        y[i]= (y[i-1]+(h*-y[i-1]));
        outfile << *px<<","<< *py<<endl;
        *px++;
        *py++;
    } outfile.close();   
    
   outfile.open("datos1.dat");
    //Rungekutta
    for (int j=1; j<=puntos;j++){
        double k1=h * func(xr[j-1],yr[j-1]);
        double k2=h * func(xr[j-1]+0.5 * h , yr[j-1]+0.5 * k1);
        double k3=h * func(xr[j-1]+0.5 * h ,yr[j-1]+0.5 * k2);
        double k4=h * func(xr[j-1]+h ,yr[j-1]+ k3);
        double promedio = (k1+ (2.0 * k2)+ (2.0 * k3)+k4)/6.0;
        xr[j]= (xr[j-1])+h;
        yr[j]= (yr[j-1]) + promedio;
        
        outfile << *pxr<<","<<*pyr<<endl;
        *pxr++;
        *pyr++;
    
    }outfile.close();
    
    outfile.open("datos2.dat");
    
    xl[1]= minx +h;
    yl[1]= yl[0] + h*func(x[0],y[0]);
    for (int k=2; k<=puntos;k++){
        xl[k]= xl[k-1]+h;
        yl[k]= yl[k-2]+ 2 * h * func(xl[k-1],yl[k-1]);
        outfile << *pxl << "," << *pyl << endl;
        *pxl++;
        *pyl++;
    }
    
    
    
    
    
    
    return 0;}
