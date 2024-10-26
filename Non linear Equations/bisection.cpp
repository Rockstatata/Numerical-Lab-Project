#include <bits/stdc++.h>
using namespace std;
#define error 0.000001

int degree_b;
vector<double>coE_b;
vector<double>range_b;
vector<double>root_b;

void set_eqn_b(double x)
{
    double value;
    cout<<"Co-efficients: ";
    cout<<"enter co-efficients: ";
    for(int i{0} ; i<=x ; i++){
        cin>>value;
        coE_b.push_back(value);
    }
}

double f_b(double x)
{
    int d=coE_b.size();

    double sum{0};
    while(--d)
    {
        sum+=pow(x,d)*coE_b[degree_b-d];
    }

    sum+=coE_b[coE_b.size()-1];

    return sum;
}

void find_range_b(double a)
{
    int start=(-1)*(int)a;
    double f1=f_b(start);
    if(f1==0)
        root_b.push_back(start);
    
    for(int i{start+1} ; i<=a ; i++)
    {
        if(f_b(i)*f1<0)
            range_b.push_back(i);

        if(f_b(i)==0)
            root_b.push_back(i);

        f1=f_b(i);
    }
}

void find_root_b(double p)
{
    int count{0};
    double a,b,x{0},x1{0};
    a=p-1;  b=p;
    
    x=(a+b)/2;
    
    while(abs(x1-x)>=error)
    {
        count++;
        x1=x;
        if(f_b(x)==0){
            cout<<"root_b: "<<x<<count<<endl;
            return;
        }

        if(f_b(x)*f_b(a)<0)
            b=x;

        else
            a=x;
        
        x=(a+b)/2;
    }
    if(find(root_b.begin(), root_b.end(), x) == root_b.end())
        root_b.push_back(x);
}

void print_root_b()
{
    for(int i{0} ; i<root_b.size() ; i++){
        cout << "root_b " << i+1 << ": " << root_b[i] << endl;
    }
}

void bisection()
{
    cout<<setprecision(6)<<fixed;

    cout<<"degree: ";
    cin>>degree_b;

    set_eqn_b(degree_b);
    double a,b;
    double interval=ceil(sqrt(abs(pow((coE_b[1]/coE_b[0]),2)-2*(coE_b[2]/coE_b[0]))));
    
    find_range_b(interval);
    for(int i{0} ; i<range_b.size() ; i++){
        find_root_b(range_b[i]);
    }
    print_root_b();
}
