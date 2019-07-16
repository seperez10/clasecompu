#include <math.h>
#include<iostream>
#include <fstream>
using namespace std;
ofstream outfile;

double aceleracion(double , double );
double velocidad();
double LeapFrog();
double Runge4();




int main(){
    
    //////Todo en UA y en agnos////
    int n=1000;
    double t[n];
    double rE[n], xE[n], yE[n], vxE[n], vyE[n];
    double rL[n], xL[n], yL[n], vxL[n], vyL[n];
    double rR[n], xR[n], yR[n], vxR[n], vyR[n];
    t[0]=0.0;
    t[n-1]=20.0;
    int i,j,k;
    
     xE[0]=0.1163;
    xL[0]=0.1163;
    xR[0]=0.1163;
    
     yE[0]= 0.9772;
    yL[0]= 0.9772;
    yR[0]= 0.9772;
    
     vxE[0]=-6.35;
    vxL[0]=-6.35;
    vxR[0]=-6.35;
    
     vyE[0]=0.606;
    vyL[0]=0.606;
    vyR[0]=0.606;
    
     rE[0]= pow((xE[0]*xE[0])+(yE[0]*yE[0]),0.5);
    rL[0]= rE[0];
    rR[0]= rE[0];
    
     //cout << rE[0];
    double dt=(t[n-1]-t[0])/(n-1);
    outfile.open("datoseuler1.dat");
    for (i=1; i<n; i++){
        //cout << i << endl;
        t[i]=t[i-1]+dt;
        xE[i]=(xE[i-1]+ dt*vxE[i-1]);
        yE[i]=(yE[i-1]+ dt*vyE[i-1]);
        vxE[i]= vxE[i-1]+ dt*aceleracion(xE[i-1],rE[i-1]);
        vyE[i]= vyE[i-1]+ dt*aceleracion(yE[i-1],rE[i-1]); 
        rE[i]= pow((xE[i]*xE[i])+(yE[i]*yE[i]),0.5);
        outfile << xE[i] <<","<< yE[i] << endl;
        
    }
    
        
    
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



double LeapFrog(){
 
    
}


        