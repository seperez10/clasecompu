#include <math.h>
#include<iostream>
#include <fstream>
using namespace std;
ofstream outfile;

double aceleracion(double , double );
double velocidad();
double LeapFrog();
double Euler();
double Runge4();




int main(){
    
    //////Todo en UA y en agnos////
    int n=1000;
    double t[n];
    double rE[n], xE[n], yE[n], vxE[n], vyE[n];
    double rL[n], xL[n], yL[n], vxL[n], vyL[n];
    double rR[n], xR[n], yR[n], vxR[n], vyR[n];
    t[0]=0.0;
    t[n-1]=1.0;
    
    double x0=0.1163;
    double y0= 0.9772;
    double vx0=6.35;
    double vy0=0.606;
    double dt=(t[n-1]-t[0])/(n-1);
    
    
    return 0;
}
 

double aceleracion(double xprevio, double rprevio){
    double G= 1.9825*(pow(10,-29));
    double m= 1.99*(pow(10,30));
    return -(G*m*xprevio)/(rprevio*rprevio*rprevio);
}
double velocidad(double v0){
    return v0;
}

double Euler(){
    
    
}

double LeapFrog(){
 
    
}


        