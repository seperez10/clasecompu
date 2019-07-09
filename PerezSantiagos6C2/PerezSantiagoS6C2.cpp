#include <math.h>
#include<iostream>
#include <fstream>
#define PI 3.14159265
using namespace std;
ofstream outfile;



int main(){
    double xf=1.0;
    double dx=0.01;
    int n=100;
    double tf=0.1;
    int nt=500;
    double c= 300.0;
    double dt=0.1*tf/nt;
    double A0= 0.01;
    double r= c*(dt/dx);
    double upresenteFi[n];
    double upasadoFi[n];
    double ufuturoFi[n];
    
    upresenteFi[0]=0.0;
    upresenteFi[n-1]=0.0; 
    upasadoFi[0]=0.0;
    upasadoFi[n-1]=0.0;
    ufuturoFi[0]=0.0;
    ufuturoFi[n-1]=0.0;
    
    double upresenteFiLi[n];
    double ufuturoFiLi[n];
    double upasadoFiLi[n];
    
    upresenteFiLi[0]=0.0;
    upresenteFiLi[n-1]=0.0;
    upasadoFiLi[0]=0.0;
    upasadoFiLi[n-1]=0.0;
    ufuturoFiLi[0]=0.0;
    ufuturoFiLi[n-1]=0.0;
    
    double upresenteLi[n];
    double ufuturoLi[n];
    double upasadoLi[n];
    
    upresenteLi[0]=0.0;
    upresenteLi[n-1]=0.0;
    upasadoLi[0]=0.0;
    upasadoLi[n-1]=0.0;
    ufuturoLi[0]=0.0;
    ufuturoLi[n-1]=0.0;
    
    
    ///Para las condiciones iniciales
    for(int j=0;j<n;j++)
    {
        if(j*dx>0.1 && j*dx < 0.2){
            upresenteFi[j]=0.1;
            upresenteFiLi[j]=0.1;}
        else{
            upresenteFi[j]=0.0;
            upresenteFiLi[j]=0.0;}
    }
    
    
    for(int i=1;i<n-1;i++){
        ufuturoFi[i]=upresenteFi[i] + ((r*r)/2.0) * (upresenteFi[i+1] - 2.0 * upresenteFi[i] + upresenteFi[i-1]);
        ufuturoFiLi[i]=upresenteFiLi[i] + ((r*r)/2.0) * (upresenteFiLi[i+1] - 2.0 * upresenteFiLi[i] + upresenteFiLi[i-1]);
        ufuturoLi[i]=upresenteLi[i] + ((r*r)/2.0) * (upresenteLi[i+1] - 2.0 * upresenteLi[i] + upresenteLi[i-1]);
    }
    for(int k=0;k<n;k++){
        upasadoFi[k] = upresenteFi[k];
        upasadoFiLi[k] = upresenteFiLi[k];
        upasadoLi[k] = upresenteLi[k];
    }
    
    return 0;}
