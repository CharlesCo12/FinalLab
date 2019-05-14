#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cmath>

using namespace std;

void angulos(double F, double angulo0, double angulo1, string filename);
double g(double theta0, double omega0);
double f(double theta0, float omega0, double t, double F);

const float F2=3;
const float F1=0.4;
const float w0=1.0;
const float gama=0.2;
const float delta=1.0;
const double h=0.1;
const double w=0.2;
const int N=1000;
const float pi=4*atan(1);
int main(){
    angulos(F1,0.0,0.1,"datos1.dat");
    angulos(F2,0.0,0.1,"datos2.dat");
    return 0;
}

double g(double theta0, double omega0){
    return omega0;
}
double f(double theta0, float omega0, double t, double F){
    return -(w0*w0*sin(theta0)) - (gama*omega0) + (F*sin(w*t + delta));
}

void angulos(double F, double angulo0, double angulo1, string filename){  
    ofstream outfile;
    outfile.open(filename);
    double omega1=1.0;
    double omega2=1.0;
    double theta1=angulo0;
    double theta2=angulo1;
    
    for(int i=0;i<N;i++){
        outfile << theta1 << " "<< theta2<<endl;
        omega1=omega1+h*f(theta1,omega1,i*h,F);
        theta1=theta1+h*g(theta1,omega1);
        omega2=omega2+h*f(theta2,omega2,i*h,F);
        theta2=theta2+h*g(theta2,omega2);
    }
    outfile.close();
}