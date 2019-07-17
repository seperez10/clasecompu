#include <math.h>
#include<iostream>
#include <fstream>
using namespace std;
ofstream outfile;

double aceleracion(double , double );
double velocidad();
double LeapFrog(double, double);
double Runge4();
double Euler(double , double );
double dt; ///Me toco definir esto como variable global si no la funcion no me funcionaba



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
     dt=(t[n-1]-t[0])/(n-1);
    outfile.open("datoseuler1.dat");
    for (i=1; i<n; i++){
        //cout << i << endl;
        t[i]=t[i-1]+dt;
        xE[i]=Euler(xE[i-1],vxE[i-1]);
        yE[i]=Euler(yE[i-1],vyE[i-1]);
        vxE[i]= vxE[i-1]+ dt*aceleracion(xE[i-1],rE[i-1]);
        vyE[i]= vyE[i-1]+ dt*aceleracion(yE[i-1],rE[i-1]); 
        rE[i]= pow((xE[i]*xE[i])+(yE[i]*yE[i]),0.5);
        outfile << xE[i] <<","<< yE[i] << endl;
        
    }outfile.close();
    
    xL[1]= xE[1];
    yL[1]= yE[1];
    vxL[1]= vxE[1];
    vyL[1]= vyL[1];
    
        outfile.open("datosleap1.dat");
    for (i=2; i<n; i++){
        //cout << i << endl;
        t[i]=t[i-2]+dt;
        xL[i]=LeapFrog(xL[i-2],vxL[i-2]);
        yL[i]=LeapFrog(yL[i-2],vyL[i-2]);
        vxL[i]= vxL[i-2]+ dt*aceleracion(xL[i-2],rL[i-2]);
        vyL[i]= vyL[i-2]+ dt*aceleracion(yL[i-2],rL[i-2]); 
        rL[i]= pow((xL[i]*xL[i])+(yL[i]*yL[i]),0.5);
        outfile << xL[i] <<","<< yL[i] << endl;
        
    }outfile.close();
        
        
    
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

double Euler(double xviejo, double vviejo){
   
    return xviejo +dt*vviejo;
}

double LeapFrog(double xviejo, double vviejo){

 return  xviejo + 2.0*dt*vviejo;
}


        