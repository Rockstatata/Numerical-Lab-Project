#include <bits/stdc++.h>
using namespace std;
#define error 0.000001

int degree;
vector<double>coE;
vector<double>range;
vector<double>root;

void set_eqn(double x)
{
    double value;
    cout<<"Co-efficients: ";
    for(double i{0} ; i<=x ; i++){
        cin>>value;
        coE.push_back(value);
    }
}

double f(double x)
{
    double d=coE.size();

    double sum{0};
    while(--d)
    {
        sum+=pow(x,d)*coE[degree-d];
    }

    sum+=coE[coE.size()-1];

    return sum;
}

void find_range(double a)
{
    double start=-a;
    double f1=f(start);
    if(f1==0)
        root.push_back(start);
    
    for(double i{start+1} ; i<=a ; i+=0.1)
    {
        if(f(i)*f1<0)
            range.push_back(i);

        if(f(i)==0)
            root.push_back(i);

        f1=f(i);
    }
}

void find_root(double p)
{
    double count{0};
    double a,b,x{0},x1{0};
    a=p-1;  b=p;
    
    x=(a*f(b)-b*f(a))/(f(b)-f(a));;
    
    while(abs(x1-x)>=error)
    {
        count++;
        x1=x;
        if(f(x)==0){
            cout<<"root: "<<x<<count<<endl;
            return;
        }

        if(f(x)*f(a)<0)
            b=x;

        else
            a=x;
        
        x=(a*f(b)-b*f(a))/(f(b)-f(a));
    }
    
    if(find(root.begin(), root.end(), x) == root.end())
        root.push_back(x);
}

void print_roots()
{
    for(int i{0} ; i<root.size() ; i++){
        cout << "root " << i+1 << ": " << root[i] << endl;
    }
}

void false_position()
{
    cout<<setprecision(6)<<fixed;

    cout<<"Degree: ";
    cin>>degree;

    set_eqn(degree);
    double a,b;
    double interval=ceil(sqrt(abs(pow((coE[1]/coE[0]),2)-2*(coE[2]/coE[0]))));
    
    find_range(interval);
    for(double i{0} ; i<range.size() ; i++){
        find_root(range[i]);
    }
    print_roots();
}
