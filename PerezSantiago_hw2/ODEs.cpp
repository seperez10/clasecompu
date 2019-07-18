#include <math.h>
#include<iostream>
#include <fstream>
using namespace std;
ofstream outfileEu;
ofstream outfileLeap;
ofstream outfileEu2;
ofstream outfileLeap2;
ofstream outfileEu3;
ofstream outfileLeap3;
ofstream outfileR4;

int i,k;

double aceleracion(double , double );
double velocidad();
double LeapFrog(double, double, double);
double Runge4(double, string);
double Euler(double , double, double  );
double dt,dt1;

    int n=1000;
    double t[1000];
    double rE[1000], xE[1000], yE[1000], vxE[1000], vyE[1000],enerE[1000];
    double rL[1000], xL[1000], yL[1000], vxL[1000], vyL[1000],enerL[1000];
    double rR[1000], xR[1000], yR[1000], vxR[1000], vyR[1000],enerR[1000];///Me toco definir esto como variable global si no la funcion no me funcionaba


int main(){
    
    //////Todo en UA y en agnos////
    
        double G= 1.982*(pow(10,-29));
    double m= 1.99*(pow(10,30));

    t[0]=0.0;
    t[n-1]=20.0;
    enerE[0]=0.0;
    enerL[0]=0.0;
    enerR[0]=0.0;
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
    dt1= 0.001;
    //cout << dt << endl;
    outfileEu.open("datoseuler1.dat");
    outfileLeap.open("datosleap1.dat");
    
    for (i=1; i<n; i++){
        //cout << i << endl;
        t[i]=t[i-1]+dt;
        xE[i]=Euler(xE[i-1],vxE[i-1],dt);
        yE[i]=Euler(yE[i-1],vyE[i-1],dt);
        vxE[i]= vxE[i-1]+ dt*aceleracion(xE[i-1],rE[i-1]);
        vyE[i]= vyE[i-1]+ dt*aceleracion(yE[i-1],rE[i-1]); 
        rE[i]= pow((xE[i]*xE[i])+(yE[i]*yE[i]),0.5);
        enerE[i]=m*vxE[i]*vxE[i];
        outfileEu << xE[i] <<","<< yE[i]<<"," <<t[i]<<","<<enerE[i]<< endl;
        
    
    xL[1]= xE[1];
    yL[1]= yE[1];
    vxL[1]= vxE[1];
    vyL[1]= vyE[1];
    rL[1]= pow((xL[1]*xL[1])+(yL[1]*yL[1]),0.5);
    
    //outfileLeap << xL[0] <<","<< yL[0] << endl;
    //outfileLeap << xL[1] <<","<< yL[1] << endl;
        
    
if(i>=2)
{
        t[i]=t[i-1]+dt;
        xL[i]=LeapFrog(xL[i-2],vxL[i-1],dt);
        yL[i]=LeapFrog(yL[i-2],vyL[i-1],dt);
        vxL[i]= vxL[i-2]+ 2*dt*aceleracion(xL[i-1],rL[i-1]);
        vyL[i]= vyL[i-2]+ 2*dt*aceleracion(yL[i-1],rL[i-1]); 
        enerL[i]=m*vxL[i]*vxL[i];
        //cout << aceleracion(xL[i-1],rL[i-1])<< endl;
        rL[i]= pow((xL[i]*xL[i])+(yL[i]*yL[i]),0.5);
}
        
        outfileLeap << xL[i] <<","<< yL[i] <<","<<enerL[i]<< endl;
    } outfileEu.close(); outfileLeap.close();
    
    
    
        
    Runge4(0.020, "datosRunge.dat");
    Runge4(0.001, "datosRunge2.dat");
    Runge4(0.0015, "datosRunge3.dat");
    
    
    outfileEu2.open("datoseuler2.dat");
    outfileLeap2.open("datosleap2.dat");
    
        for (i=1; i<n; i++){
        //cout << i << endl;
        t[i]=t[i-1]+dt1;
        xE[i]=Euler(xE[i-1],vxE[i-1],dt1);
        yE[i]=Euler(yE[i-1],vyE[i-1],dt1);
        vxE[i]= vxE[i-1]+ dt1*aceleracion(xE[i-1],rE[i-1]);
        vyE[i]= vyE[i-1]+ dt1*aceleracion(yE[i-1],rE[i-1]); 
        rE[i]= pow((xE[i]*xE[i])+(yE[i]*yE[i]),0.5);
        enerE[i]=m*vxE[i]*vxE[i];
        outfileEu2 << xE[i] <<","<< yE[i] <<"," <<t[i]<<","<<enerE[i]<< endl;
        
    
    xL[1]= xE[1];
    yL[1]= yE[1];
    vxL[1]= vxE[1];
    vyL[1]= vyE[1];
    rL[1]= pow((xL[1]*xL[1])+(yL[1]*yL[1]),0.5);
    
    //outfileLeap << xL[0] <<","<< yL[0] << endl;
    //outfileLeap << xL[1] <<","<< yL[1] << endl;
        
    
if(i>=2)
{
        t[i]=t[i-1]+dt1;
        xL[i]=LeapFrog(xL[i-2],vxL[i-1],dt1);
        yL[i]=LeapFrog(yL[i-2],vyL[i-1],dt1);
        vxL[i]= vxL[i-2]+ 2*dt1*aceleracion(xL[i-1],rL[i-1]);
        vyL[i]= vyL[i-2]+ 2*dt1*aceleracion(yL[i-1],rL[i-1]); 
        enerL[i]=m*vxL[i]*vxL[i];
        rL[i]= pow((xL[i]*xL[i])+(yL[i]*yL[i]),0.5);
}
        
        outfileLeap2 << xL[i] <<","<< yL[i]<<","<<enerL[i] << endl;
    } outfileEu2.close(); outfileLeap2.close();
    
    
    double dt2= 0.0015;
    
    
    
    
       outfileEu3.open("datoseuler3.dat");
    outfileLeap3.open("datosleap3.dat");
    
        for (i=1; i<n; i++){
        //cout << i << endl;
        t[i]=t[i-1]+dt2;
        xE[i]=Euler(xE[i-1],vxE[i-1],dt2);
        yE[i]=Euler(yE[i-1],vyE[i-1],dt2);
        vxE[i]= vxE[i-1]+ dt2*aceleracion(xE[i-1],rE[i-1]);
        vyE[i]= vyE[i-1]+ dt2*aceleracion(yE[i-1],rE[i-1]); 
        rE[i]= pow((xE[i]*xE[i])+(yE[i]*yE[i]),0.5);
        enerE[i]=m*vxE[i]*vxE[i];
        outfileEu3 << xE[i] <<","<< yE[i] <<"," <<t[i]<<","<<enerE[i]<< endl;
        
        
    
    xL[1]= xE[1];
    yL[1]= yE[1];
    vxL[1]= vxE[1];
    vyL[1]= vyE[1];
    rL[1]= pow((xL[1]*xL[1])+(yL[1]*yL[1]),0.5);
    
    //outfileLeap << xL[0] <<","<< yL[0] << endl;
    //outfileLeap << xL[1] <<","<< yL[1] << endl;
        
    
if(i>=2)
{
        t[i]=t[i-1]+dt2;
        xL[i]=LeapFrog(xL[i-2],vxL[i-1],dt2);
        yL[i]=LeapFrog(yL[i-2],vyL[i-1],dt2);
        vxL[i]= vxL[i-2]+ 2*dt2*aceleracion(xL[i-1],rL[i-1]);
        vyL[i]= vyL[i-2]+ 2*dt2*aceleracion(yL[i-1],rL[i-1]); 
        enerL[i]=m*vxL[i]*vxL[i];
        rL[i]= pow((xL[i]*xL[i])+(yL[i]*yL[i]),0.5);
    
}
        
        outfileLeap3 << xL[i] <<","<< yL[i]<<","<<enerL[i] << endl;
    } outfileEu3.close(); outfileLeap3.close();
    
    
    
    return 0;
}

double velocidad(double v){
    return v;
}

double aceleracion(double xprevio, double rprevio){
    double G= 1.982*(pow(10,-29));
    double m= 1.99*(pow(10,30));
    return -(G*m*xprevio)/(rprevio*rprevio*rprevio);
}

double Euler(double xviejo, double vviejo,double dt){
   
    return xviejo +dt*vviejo;
}

double LeapFrog(double xviejo, double vviejo,double dt){

 return  xviejo + 2.0*dt*vviejo;
}

double Runge4(double dt, string nombre){
    outfileR4.open(nombre);
    for (int j=1; j<n; j++){
    
        double k1x= velocidad(vxR[j-1]);
    double k1x2= aceleracion(xR[j-1], rR[j-1]);
    double k1y= velocidad(vyR[j-1]);
    double k1y2= aceleracion(yR[j-1], rR[j-1]);
    double k1posx= xR[j-1] + (dt/2.0) * k1x;
    double k1posy= yR[j-1] + (dt/2.0) * k1y;
    double k1vx= vxR[j-1]+ (dt/2.0) * k1x2;
    double k1vy= vyR[j-1]+ (dt/2.0) * k1y2;
        
         double k2x= k1vx;
    double k2x2= aceleracion(k1posx, rR[j-1]);
    double k2y= k1vy;
    double k2y2= aceleracion(k1posy, rR[j-1]);
    double k2posx= xR[j-1] + (dt/2.0) * k2x;
    double k2posy= yR[j-1] + (dt/2.0) * k2y;
    double k2vx= vxR[j-1]+ (dt/2.0) * k2x2;
    double k2vy= vyR[j-1]+ (dt/2.0) * k2y2;
               
           double k3x= k2vx;
    double k3x2= aceleracion(k2posx, rR[j-1]);
    double k3y= k2vy;
    double k3y2= aceleracion(k2posy, rR[j-1]);
    double k3posx= xR[j-1] + (dt) * k3x;
    double k3posy= yR[j-1] + (dt) * k3y;
    double k3vx= vxR[j-1]+ (dt) * k3x2;
    double k3vy= vyR[j-1]+ (dt) * k3y2;
               
           double k4x= k3vx;
    double k4x2= aceleracion(k3posx, rR[j-1]);
    double k4y= k3vy;
    double k4y2= aceleracion(k3posy, rR[j-1]);

    double promediokx1=(k1x+2.0*k2x+2.0*k3x+k4x)/6.0;
    double promediokx2=(k1x2+2.0*k2x2+2.0*k3x2+k4x2)/6.0;
    double promedioky1=(k1y+2.0*k2y+2.0*k3y+k4y)/6.0;
    double promedioky2=(k1y2+2.0*k2y2+2.0*k3y2+k4y2)/6.0;
    
        
    xR[j]= xR[j-1]+ dt*promediokx1;    
    vxR[j]= vxR[j-1]+ dt*promediokx2;
    yR[j]= yR[j-1]+ dt*promedioky1;    
    vyR[j]= vyR[j-1]+ dt*promedioky2;
        
    rR[j]=  pow((xR[j]*xR[j])+(yR[j]*yR[j]),0.5);
    //cout << j << endl;
    outfileR4 << xR[j] << "," << yR[j]<<","<<vxR[j]<<","<<vyR[j]<<","<<t[j]<< endl;
    } 
outfileR4.close();
}



        