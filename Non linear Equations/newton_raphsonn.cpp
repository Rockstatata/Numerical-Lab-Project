#include<bits/stdc++.h>
using namespace std;

double degree{0};
vector<double>equ;
int interval{0};
set<double>roots;
const double tolerance = 1e-6;

void input()
{
    cout << "degree: ";
    cin >> degree;

    cout << "Co-efficients: ";
    for(int i{0} ; i<degree+1 ; i++){
        double value;
        cin >> value;
        equ.push_back(value);
    }
}

double f(double a)
{
    double temp = degree+1;
    double sum{0};
    
    for(int i{0} ; i<degree+1 ; i++){
        sum += equ[i]*pow(a, --temp);
    }

    return sum;
}

double f_dash(double a)
{
    double temp{degree};
    double sum{0};

    for(int i{0} ; i<degree ; i++){
        sum += (temp*equ[i]*pow(a, temp-1));
        temp--;
    }

    return sum;
}

bool is_valid(double x)
{
    for (const auto& root : roots) {
        if (fabs(x - root) < tolerance) {
            return false; 
        }
    }
    return true; 
}

void d_root(double a)
{
    double x_next{0}, x_prev{a};

    if(f_dash(x_prev) == 0){
        if(f(x_prev) == 0){
            roots.insert(x_prev);
            return;
        }

        else
            return;
    }

    x_next = x_prev - (f(x_prev)/f_dash(x_prev));
    
    while(fabs(x_next - x_prev) > tolerance)
    {
        x_prev = x_next;
        if(f_dash(x_prev) == 0){
            if(f(x_prev) == 0){
                roots.insert(x_prev);
                return;
            }

        else
            return;
        }

        x_next = x_prev - (f(x_prev)/f_dash(x_prev));
    }

    if(is_valid(x_next))
        roots.insert(x_next);
}

void newton_raphson()
{
    cout << setprecision(6) << fixed;
    input();

    interval = ceil(sqrt(pow((equ[1]/equ[0]), 2)-2*(equ[2]-equ[0])));

    for(int i{interval*(-1)} ; i <= interval ; i++){
        d_root(i);
    }

    int no{1};
    cout << endl;
    for(auto a : roots){
        cout << "Root " << no++ << ": " << a << " " << endl;
    }
}
