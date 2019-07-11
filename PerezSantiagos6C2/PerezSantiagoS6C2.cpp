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
    double c= 300.0;
    double dt=(dx*0.5)/c;
    double A0= 0.01;
    double r= c*(dt/dx);
    double upresenteFi[100];
    double upasadoFi[100];
    double ufuturoFi[100];
    double uiniFi[100];
    double sin (double x);
   
    
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
    
    upasadoFiLi[0]=0.0;
    
    ufuturoFiLi[0]=0.0;
    
    double upresenteLi[n];
    double ufuturoLi[n];
    double upasadoLi[n];
    double uiniLi[n];
    
    upresenteLi[n-1]=0.0;
    
    upasadoLi[n-1]=0.0;
    
    ufuturoLi[n-1]=0.0;
    
    

    double m= (A0*2.0)/(L);
    
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
        upasadoFiLi[j]= uiniFi[j];
        //upasadoLi[j]= uiniFi[j];
        outfile << upasadoFi[j]<<endl;
    }outfile.close();
    
    //PARA FIJAAAAAS
    for(int i=1;i<n-1;i++){
        upresenteFi[i]=upasadoFi[i] + ((r*r)/2.0) * (upasadoFi[i+1] - 2.0 * upasadoFi[i] + upasadoFi[i-1]);
        upresenteFiLi[i]=upasadoFiLi[i] + ((r*r)/2.0) * (upasadoFiLi[i+1] - 2.0 * upasadoFiLi[i] + upasadoFiLi[i-1]);
        upresenteLi[i]= upasadoLi[i] + ((r*r)/2.0) * (upasadoLi[i+1] - 2.0 * upasadoLi[i] + upasadoLi[i-1]);
    }
    
         /////TIEMPO 1 PARA CONDICIONES FIJAS //////////////////////////////
    
    outfile.open("datosfijas1.dat");
    
    int tiempo=10;
    for (int h=0; h<tiempo ; h++){
        
        for (int k=1; k<n-1; k++){
            ufuturoFi[k]= ((r*r)*(upresenteFi[k+1]+upresenteFi[k-1]-2*upresenteFi[k])-upasadoFi[k]+2*upresenteFi[k]);
        }
        for (int m=1; m<n-1; m++)
        {
            upasadoFi[m]=upresenteFi[m];
            upresenteFi[m]=ufuturoFi[m];
            
        }
                                
} 
    for (int p=1; p<n-1; p++){
            outfile << upresenteFi[p] << endl;
    }outfile.close();
    
         /////TIEMPO 2 PARA CONDICIONES FIJAS //////////////////////////////
    
        outfile.open("datosfijas2.dat");
    
    int tiempo2=20;
    for (int h=0; h<tiempo ; h++){
        
        for (int k=1; k<n; k++){
            ufuturoFi[k]= ((r*r)*(upresenteFi[k+1]+upresenteFi[k-1]-2*upresenteFi[k])-upasadoFi[k]+2*upresenteFi[k]);
        }
        for (int m=1; m<n; m++)
        {
            upasadoFi[m]=upresenteFi[m];
            upresenteFi[m]=ufuturoFi[m];
            
        }
                                
} 
    for (int p=1; p<n-1; p++){
            outfile << upresenteFi[p] << endl;
    }outfile.close();
    
     /////TIEMPO 3 PARA CONDICIONES FIJAS //////////////////////////////
    
        outfile.open("datosfijas3.dat");
    
    int tiempo3=30;
    for (int h=0; h<tiempo3 ; h++){
        
        for (int k=1; k<n; k++){
            ufuturoFi[k]= ((r*r)*(upresenteFi[k+1]+upresenteFi[k-1]-2*upresenteFi[k])-upasadoFi[k]+2*upresenteFi[k]);
        }
        for (int m=1; m<n; m++)
        {
            upasadoFi[m]=upresenteFi[m];
            upresenteFi[m]=ufuturoFi[m];
            
        }
                                
} 
    for (int p=1; p<n-1; p++){
            outfile << upresenteFi[p] << endl;
    }outfile.close();
   
    
    ////////PARA FIJAS Y LIBREEEEEEEES
     /////TIEMPO 1 PARA CONDICIONES FIJAS -LIBRE//////////////////////////////
    
        outfile.open("datosfijaslibres1.dat");
    
    int tiempof1=20;
    for (int h=1; h<tiempof1 ; h++){
        
        for (int k=1; k<n; k++){
            
            
            if (x[k]<=(L/2)){
                ufuturoFiLi[k]= ((r*r)*(upresenteFiLi[k+1]+upresenteFiLi[k-1]-2*upresenteFiLi[k])-upasadoFiLi[k]+2*upresenteFiLi[k]);}
            
            else {
                ufuturoFiLi[k]=ufuturoFiLi[k-1];}
        }
        
        for (int m=1; m<n; m++)
        {
             
            upasadoFiLi[m]=upresenteFiLi[m];
            upresenteFiLi[m]=ufuturoFiLi[m];
        }
                               
} 
    for (int p=1; p<n; p++){
            outfile << upresenteFiLi[p] << endl;
    }outfile.close();
    
     /////TIEMPO 2 PARA CONDICIONES FIJAS -LIBRE//////////////////////////////
    
    outfile.open("datosfijaslibres2.dat");
    
    int tiempof2=40;
    for (int h=0; h<tiempof2 ; h++){
        
        for (int k=1; k<n; k++){
            
            
            if (x[k]<=(L/2)){
                ufuturoFiLi[k]= ((r*r)*(upresenteFiLi[k+1]+upresenteFiLi[k-1]-2*upresenteFiLi[k])-upasadoFiLi[k]+2*upresenteFiLi[k]);}
            
            else {
                ufuturoFiLi[k]=ufuturoFiLi[k-1];}
        }
        
        for (int m=1; m<n; m++)
        {
             
            upasadoFiLi[m]=upresenteFiLi[m];
            upresenteFiLi[m]=ufuturoFiLi[m];
        }
                               
} 
    for (int p=1; p<n; p++){
            outfile << upresenteFiLi[p] << endl;
    }outfile.close();
    
    /////TIEMPO 3 PARA CONDICIONES FIJAS -LIBRE//////////////////////////////
     outfile.open("datosfijaslibres3.dat");
    
    int tiempof3=100;
    for (int h=0; h<tiempof3 ; h++){
        
        for (int k=1; k<n; k++){
            
            
            if (x[k]<=(L/2)){
                ufuturoFiLi[k]= ((r*r)*(upresenteFiLi[k+1]+upresenteFiLi[k-1]-2*upresenteFiLi[k])-upasadoFiLi[k]+2*upresenteFiLi[k]);}
            
            else {
                ufuturoFiLi[k]=ufuturoFiLi[k-1];}
        }
        
        for (int m=1; m<n; m++)
        {
             
            upasadoFiLi[m]=upresenteFiLi[m];
            upresenteFiLi[m]=ufuturoFiLi[m];
        }
                               
} 
    for (int p=1; p<n; p++){
            outfile << upresenteFiLi[p] << endl;
    }outfile.close();
    
    
    double tiempop1=10;
    /////TIEMPO 1 PARA CONDICIONES Periodicas//////////////////////////////
    outfile.open("datosperiodicas1.dat");
    for (int ti=0; ti<tiempop1; ti++){

    for (int h=0; h<n ; h++){
        double xgr=3.0*c*h*PI/L;
        double x2 = xgr*PI/180;
        upasadoLi[0]= A0*sin(x2);
        upresenteLi[0]= A0*sin(x2);
        ufuturoLi[0]= A0*sin(x2);
        
            
        for (int k=1; k<n; k++){
            if (x[k]>(L/2)){
            ufuturoLi[k]=((r*r)*(upresenteLi[k+1]+upresenteLi[k-1]-2*upresenteLi[k])-upasadoLi[k]+2*upresenteLi[k]);}
            else {
                ufuturoLi[k]=-ufuturoLi[k-1];}
        }
    }
        }
  for (int m=1; m<n; m++){
      upasadoLi[m]=upresenteLi[m];
      upresenteLi[m]=ufuturoLi[m];}
                            
    
    for (int p=1; p<n; p++){
            outfile << upresenteLi[p] << endl;
    }outfile.close();
    
    
    /////TIEMPO 1 PARA CONDICIONES Periodicas//////////////////////////////
    
   
    
    return 0;}
