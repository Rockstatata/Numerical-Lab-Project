#include <bits/stdc++.h>
using namespace std;

#define error 0.000001

int degree;
vector<double> coE;
vector<double> range;
vector<double> root;

void set_eqn(double x) {
    double value;
    cout << "Co-efficients: ";
    for (double i = 0; i <= x; i++) {
        cin >> value;
        coE.push_back(value);
    }
}

double f(double x) {
    double d = coE.size();
    double sum{0};
    while (--d) {
        sum += pow(x, d) * coE[degree - d];
    }
    sum += coE[coE.size() - 1];
    return sum;
}

void find_range(double a) {
    double start = -a;
    double f1 = f(start);
    if (f1 == 0)
        root.push_back(start);
    
    for (double i{start + 1}; i <= a; i += 0.1) {
        if (f(i) * f1 < 0)
            range.push_back(i);

        if (f(i) == 0)
            root.push_back(i);

        f1 = f(i);
    }
}

// Bisection method to find roots in a given interval [a, b]
void find_root(double p) {
    double a = p - 1, b = p;
    double x = (a + b) / 2.0;
    
    while (abs(f(x)) >= error) {
        // Check if we found the exact root
        if (f(x) == 0) {
            cout << "root: " << x << endl;
            return;
        }

        // Narrow down the interval [a, b] where the root lies
        if (f(a) * f(x) < 0) {
            b = x;
        } else {
            a = x;
        }
        
        // Update the midpoint
        x = (a + b) / 2.0;
    }
    
    // Avoid duplicates
    if (find(root.begin(), root.end(), x) == root.end())
        root.push_back(x);
}

void print_roots() {
    for (int i{0}; i < root.size(); i++) {
        cout << "root " << i + 1 << ": " << root[i] << endl;
    }
}

void bisection_method() {
    cout << setprecision(6) << fixed;

    cout << "Degree: ";
    cin >> degree;

    set_eqn(degree);
    double interval = ceil(sqrt(abs(pow((coE[1] / coE[0]), 2) - 2 * (coE[2] / coE[0]))));
    
    find_range(interval);
    for (double i{0}; i < range.size(); i++) {
        find_root(range[i]);
    }
    print_roots();
}
