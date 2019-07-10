#include <math.h>
#include<iostream>
#include <fstream>
#define PI 3.14159265
using namespace std;
ofstream outfile;



int main(){
    double L=1.0;
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
    double uiniFi[n];
   
    
    upresenteFi[0]=0.0;
    upresenteFi[n-1]=0.0; 
    upasadoFi[0]=0.0;
    upasadoFi[n-1]=0.0;
    ufuturoFi[0]=0.0;
    ufuturoFi[n-1]=0.0;
    
    double upresenteFiLi[n];
    double ufuturoFiLi[n];
    double upasadoFiLi[n];
    double uiniFiLi[n];
    
    upresenteFiLi[0]=0.0;
    upresenteFiLi[n-1]=0.0;
    upasadoFiLi[0]=0.0;
    upasadoFiLi[n-1]=0.0;
    ufuturoFiLi[0]=0.0;
    ufuturoFiLi[n-1]=0.0;
    
    double upresenteLi[n];
    double ufuturoLi[n];
    double upasadoLi[n];
    double uiniLi[n];
    
    upresenteLi[0]=0.0;
    upresenteLi[n-1]=0.0;
    upasadoLi[0]=0.0;
    upasadoLi[n-1]=0.0;
    ufuturoLi[0]=0.0;
    ufuturoLi[n-1]=0.0;
    double m= A0/(L/2);
    
    double x[n];
    x[0]=0.0;
    ///Para las condiciones iniciales
    outfile.open("datosini.dat");
    for(int j=1;j<n;j++)
    {
        x[j]= x[j-1]+dx;
        if(x[j]<=L/2.0){
            
            uiniFi[j]= m*x[j];
           
        }
            
        else{
            
            uiniFi[j]=-m*x[j]+(2.0*A0);
            
            }
        upasadoFi[j]= uiniFi[j];
        outfile << upasadoFi[j]<<endl;
    }outfile.close();
    
    
    for(int i=1;i<n-1;i++){
        upresenteFi[i]=upasadoFi[i] + ((r*r)/2.0) * (upasadoFi[i+1] - 2.0 * upasadoFi[i] + upasadoFi[i-1]);
upasadoFi[i]= uiniFi[i];
        //cout << upresenteFi[i] << endl;
    }
    
    
    outfile.open("datos1.dat");
    int tiempo=1;
    for (int h=0; h<tiempo ; h++){
        h=h+0.01;
        for (int k=1; k<n; k++){
            ufuturoFi[k]= (2.0*(1.0-(r*r))*upresenteFi[k] - upasadoFi[k] + (r*r)*(upresenteFi[k+1]+upresenteFi[k-1]));}
            for (int m=1; m<n; m++){
                           upasadoFi[m]=upresenteFi[m];
                           upresenteFi[m]=ufuturoFi[m];
                              outfile << upresenteFi[m] << endl;         
                           }
                          
} outfile.close();
    
    return 0;}
