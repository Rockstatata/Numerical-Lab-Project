#include<bits/stdc++.h>
using namespace std;

double degree_nr{0};
vector<double>equ_nr;
int interval_nr{0};
set<double>roots_nr;
const double tolerance_nr = 1e-6;

void input_nr()
{
    cout << "degree: ";
    cin >> degree_nr;

    cout << "Co-efficients: ";
    for(int i{0} ; i<degree_nr+1 ; i++){
        double value;
        cin >> value;
        equ_nr.push_back(value);
    }
}

double f_nr(double a)
{
    double temp = degree_nr+1;
    double sum{0};
    
    for(int i{0} ; i<degree_nr+1 ; i++){
        sum += equ_nr[i]*pow(a, --temp);
    }

    return sum;
}

double f_dash_nr(double a)
{
    double temp{degree_nr};
    double sum{0};

    for(int i{0} ; i<degree_nr ; i++){
        sum += (temp*equ_nr[i]*pow(a, temp-1));
        temp--;
    }

    return sum;
}

bool is_valid_nr(double x)
{
    for (const auto& root : roots_nr) {
        if (fabs(x - root) < tolerance_nr) {
            return false; 
        }
    }
    return true; 
}

void d_root_nr(double a)
{
    double x_next{0}, x_prev{a};

    if(f_dash_nr(x_prev) == 0){
        if(f_nr(x_prev) == 0){
            roots_nr.insert(x_prev);
            return;
        }

        else
            return;
    }

    x_next = x_prev - (f_nr(x_prev)/f_dash_nr(x_prev));
    
    while(fabs(x_next - x_prev) > tolerance_nr)
    {
        x_prev = x_next;
        if(f_dash_nr(x_prev) == 0){
            if(f_nr(x_prev) == 0){
                roots_nr.insert(x_prev);
                return;
            }

        else
            return;
        }

        x_next = x_prev - (f_nr(x_prev)/f_dash_nr(x_prev));
    }

    if(is_valid_nr(x_next))
        roots_nr.insert(x_next);
}

void newton_raphson()
{
    cout << setprecision(6) << fixed;
    input_nr();

    interval_nr = ceil(sqrt(pow((equ_nr[1]/equ_nr[0]), 2)-2*(equ_nr[2]-equ_nr[0])));

    for(int i{interval_nr*(-1)} ; i <= interval_nr ; i++){
        d_root_nr(i);
    }

    int no{1};
    cout << endl;
    for(auto a : roots_nr){
        cout << "Root " << no++ << ": " << a << " " << endl;
    }
}

int main()
{
    cout << setprecision(6) << fixed;
    input_nr();

    interval_nr = ceil(sqrt(pow((equ_nr[1]/equ_nr[0]), 2)-2*(equ_nr[2]-equ_nr[0])));

    for(int i{interval_nr*(-1)} ; i <= interval_nr ; i++){
        d_root_nr(i);
    }

    int no{1};
    cout << endl;
    for(auto a : roots_nr){
        cout << "Root " << no++ << ": " << a << " " << endl;
    }
}


