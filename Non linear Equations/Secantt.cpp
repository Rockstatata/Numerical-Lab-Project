#include<bits/stdc++.h>
using namespace std;

#define err_s 1e-6

double degree_s{0};
vector <double> equ_s;
double interval_s{0};
set<double>roots_s;

void input_s()
{
    cout << "degree: ";
    cin >> degree_s;
    cout << "Co-efficients: ";

    for(int i{0} ; i < degree_s+1 ; i++){
        double value;
        cin >> value;
        equ_s.push_back(value);
    }
}

double f_s(double x)
{
    double sum{0};
    double temp = degree_s;
    for(int i{0} ; i < degree_s+1 ; i++){
        sum += pow(x, temp) * equ_s[i];
        temp--;
    }

    return sum;
}

bool is_valid_s(double x)
{
    for(auto a : roots_s){
        if(fabs(x-a) < err_s)
            return false;
    }

    return true;
}

double secant_s(double p)
{
    double b{p};
    double a{p-1};
    double x{0};
    x = b - (f_s(b)*(b-a))/(f_s(b)-f_s(a));
    
    while(fabs(x - b) > err_s)
    {
        a = b;
        b = x;
        x = b - (f_s(b)*(b-a))/(f_s(b)-f_s(a));
    }

    return x;
}

void secant()
{
    cout << setprecision(6) << fixed;

    input_s();
    interval_s = ceil(sqrt(pow((equ_s[1]/equ_s[0]), 2)-2*(equ_s[2]-equ_s[0])));
    interval_s = -interval_s;

    for(double i{interval_s} ; i < interval_s*(-1) ; i+=0.1){
        double p{secant_s(i)};
        if(is_valid_s(p))
            roots_s.insert(p);
    }

    int no{1};
    for(auto a : roots_s){
        cout << "Root " << no++ << ": " << a << endl;
    }
}
