#include<bits/stdc++.h>
using namespace std;

double fx(double x){
    return 2*x*x*x-2*x-5;
}
double dfx(double x){
    return 6*x*x-2;
}

void newton_raphsons(double x0){
    int i=0;
    double x1;
    cout<<"Iterations:"<<"      "<<"X1"<<"         "<<"F(x1)"<<"       "<<"F'(x1)"<<endl;
    do{
        x1 = x0 - (fx(x0)/dfx(x0));
        x0 = x1;
        i++;
        cout<<fixed<<setprecision(4)<<i<<"              "<<x1<<"      "<<fx(x1)<<"      "<<dfx(x1)<<endl;
    }while(fx(x1)>0.001);

}

void secant_method(double x1,double x2){
    double x3;
    int i=0;
    cout<<"Iterations:"<<"      "<<"X1"<<"          "<<"X2"<<"           "<<"X3"<<endl;
    do{
        x3 = x1 - (fx(x1)*(x2-x1))/(fx(x2)-fx(x1));
        cout<<fixed<<setprecision(4)<<i<<"              "<<x1<<"      "<<x2<<"      "<<x3<<endl;
        x1 = x2;
        x2 = x3;
        i++;
        
    }while(fabs(x2-x1)>0.001);
}

double gfx(double x){
    return cbrt((2*x+5)/2);
}
void fixed_point(double x0){
    double x1;
    do{
        x1 = gfx(x0);
        cout<<x1<<endl;
        x0 = x1;
    }while(fabs(fx(x1))>0.001);
}

double horners(double a[],double x,int n){
    int p = a[0];
    for(int i=1;i<n;i++){
        p = p*x + a[i];
    }
    return p;
}

int main(){
    newton_raphsons(2);
    secant_method(1,2);
    fixed_point(1.5);
    double coeff[]={2,0,-2,-5};///7
    cout<<horners(coeff,2,4)<<endl;
}