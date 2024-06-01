#include<bits/stdc++.h>
using namespace std;
//x3-x-1
double func(float x)
{
    return((x*x*x)-x-1);

}
int main()
{
    float a,b,f0,f1,f2;
    float root;
    a=1;
    b=2;
    int i=1;
    f1=func(a);
    f2=func(b);
    if(f1*f2>0)
        cout<<"Wrong guess\n";
    else
    {
       root=1;
       cout<<"Iteration    a        b       c       relative error\n";

        while(fabs(func(root))>0.001)
        {
            f1=func(a);
            f2=func(b);
            root=a-((func(a)*(b-a))/(func(b)-func(a)));
            f0=func(root);
            if(f1*f0>0)
            {
                a=root;
            }
            else
            {
                b=root;
            }
            //cout<<root<<endl;
           // float error=(a-b)/a;
           float error=(a-b)/a;



            cout<<"   "<<i<<"           "<<a<<"     "<<b<<"  "<<root<<"     "<<error<<endl;
            cout<<endl;
            i++;
        }
        //cout<<root<<endl;
    }

}
