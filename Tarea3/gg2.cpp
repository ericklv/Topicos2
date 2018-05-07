#include<iostream>
#include<math.h>

using namespace std;

int main (void)
{
 float alfa, beta, gama, delta, omega;
 

 float u0=-1,u,v0=1,v, t=0,x;
 float K1, K2, K3, K4;
 float l1, l2, l3, l4;
 float h=0.05;
 u=u0;
 v=v0;
 cout<<"t\t"<<"x(t)\t"<<"v\t"<<endl;
 do
 {
// if (t>0)
// v=v0;

//Tenemos x"(t)+r*x'(t)+b*x(t)^3 -c*x(t)=a.cos(wt)
//x"(t)= a.cos(wt) - r*x'(t) - b*x(t)^3 +c* x(t)
// gamma*cos(omega*t) -delta*v - beta*pow(u,3)- alfa*u 
 alfa=1;beta=1;gama=0.8;delta=0.25;omega=1;

//gama (a) es la amplitud de la fuerza impulsadora periodica 
//omega (w) es la frecuencia angular de la fuerza impulsadora peridica
//delta (r) controla la cantidad de amortiguacion
//beta (b)controla la no linealidad en la fuerza de restauracion
//beta =0 entonces duffing es un oscilador simple amortiguado
//alfa (c)controla la rigidez lineal
 K1=v*h;
 l1=h*(gama*cos(omega*t)-(delta*v)+(alfa*u)-(beta*pow(u,3)) );
 K2=h*(v+1/2*l1);
 l2=h*(gama*cos(omega*(t+(1/2)*h))-(delta*(v+(1/2)*l1))+(alfa*(u+1/2*K1))-(beta*pow(u+1/2*K1,3)) );
 K3=h*(v+1/2*l2);
 l3=h*(gama*cos(omega*(t+(1/2)*h))-(delta*(v+(1/2)*l2))+(alfa*(u+1/2*K2))-(beta*pow(u+1/2*K2,3)) );
 K4=h*(v+l3);
 l4=h*(gama*cos(omega*(t+h))-(delta*(v+l3))-(alfa*(u+K3))+(beta*pow(u+K3,3)) );
 
 v=v+((l1+2*l2+2*l3+l4)/6);
 u=u+((K1+2*K2+2*K3+K4)/6);

 x=u;
 t=t+h;
 cout<<t<<"\t"<<x<<"\t"<<v<<"\t"<<endl;
 }while(t<=100);
 return 0;
}