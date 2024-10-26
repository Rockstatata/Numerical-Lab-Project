#include <bits/stdc++.h>
using namespace std;
#define error 0.000001

int degree_false_p;
vector<double>coE_false_p;
vector<double>range_false_p;
vector<double>root_false_p;

void set_eqn_fp(double x)
{
    double value;
    cout<<"Co-efficients: ";
    for(double i{0} ; i<=x ; i++){
        cin>>value;
        coE_false_p.push_back(value);
    }
}

double f_fp(double x)
{
    double d=coE_false_p.size();
    double sum{0};
    while(--d)
    {
        sum+=pow(x,d)*coE_false_p[degree_false_p-d];
    }

    sum+=coE_false_p[coE_false_p.size()-1];

    return sum;
}

void find_range_fp(double a)
{
    double start=-a;
    double f1=f_fp(start);
    if(f1==0)
        root_false_p.push_back(start);
    
    for(double i{start+1} ; i<=a ; i+=0.1)
    {
        if(f_fp(i)*f1<0)
            range_false_p.push_back(i);

        if(f_fp(i)==0)
            root_false_p.push_back(i);

        f1=f_fp(i);
    }
}

void find_root_fp(double p)
{
    double count{0};
    double a,b,x{0},x1{0};
    a=p-1;  b=p;
    
    x=(a*f_fp(b)-b*f_fp(a))/(f_fp(b)-f_fp(a));;
    
    while(abs(x1-x)>=error)
    {
        count++;
        x1=x;
        if(f_fp(x)==0){
            cout<<"root: "<<x<<count<<endl;
            return;
        }

        if(f_fp(x)*f_fp(a)<0)
            b=x;

        else
            a=x;
        
        x=(a*f_fp(b)-b*f_fp(a))/(f_fp(b)-f_fp(a));
    }
    
    if(find(root_false_p.begin(), root_false_p.end(), x) == root_false_p.end())
        root_false_p.push_back(x);
}

void print_roots_fp()
{
    for(int i{0} ; i<root_false_p.size() ; i++){
        cout << "root " << i+1 << ": " << root_false_p[i] << endl;
    }
}

void false_position()
{
    cout<<setprecision(6)<<fixed;
    cout<<"Degree: ";
    cin>>degree_false_p;

    set_eqn_fp(degree_false_p);
    double a,b;
    double interval=ceil(sqrt(abs(pow((coE_false_p[1]/coE_false_p[0]),2)-2*(coE_false_p[2]/coE_false_p[0]))));
    
    find_range_fp(interval);
    for(double i{0} ; i<range_false_p.size() ; i++){
        find_root_fp(range_false_p[i]);
    }
    print_roots_fp();
}

