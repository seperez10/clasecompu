#include <math.h>
#include<iostream>
#include <fstream>
using namespace std;
ofstream outfile;




int main(){
    int n= 80;
    double upre[n];
    double ufut[n];
    double dx=(2.0/(n-1.0));
    double miu=1.0;
    double dt= (dx/miu)*0.25;
    int contador =0;
    outfile.open("datos.dat");
    for (int i = 0; i <= n; i++){
        if((i*dx)>1.25 || (i*dx)<0.75){
            upre[i]=1.0;}
        else {
            upre[i]=2.0;}
    //cout << upre[i]<<endl;
    }
     for (int j=1; j<n; j++){
         ufut[j]= (miu*dt/dx)*(upre[j]-upre[j-1]) + upre[j];
         upre[j]=ufut[j];
     
         contador++;
     for (int k=1; k<n; k++){
         
         if (contador==15){
            outfile << upre[k] << endl;
            contador==0;
         }
         
         }
     
     }

        
        
    
    
    return 0;
}