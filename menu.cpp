#pragma once
#include<bits/stdc++.h>
#include "Linear Equations\Gauss_Elimination.cpp"
#include "Linear Equations\gasuss_jordan.cpp"
#include "Linear Equations\gauss_seidal.cpp"
#include "Linear Equations\jacobi.cpp"
#include "Linear Equations\LUFactorization.cpp"
#include "Non linear Equations\bisection.cpp"
#include "Non linear Equations\newton_raphsonn.cpp"
#include "Non linear Equations\false_position.cpp"
#include "Non linear Equations\Secantt.cpp"
#include "Matrix Inversion/matrix_inversion.cpp"
#include "Differential Equations/rk.cpp"
 
using namespace std;

void printHeader() {
    cout << "==========================================" << endl;
    cout << "     Welcome to Numerical Methods Tool    " << endl;
    cout << "==========================================" << endl;
}
 
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout<<"Welcome to the Console Application of Numerical Methods"<<endl;
    int choice = 0,quit=0;
    printHeader();
    while(true){
        cout<<"Choose an option"<<endl;
        cout<<"1. Solution of Linear Equations "<<endl;
        cout<<"2. Solution of Non-linear Equations "<<endl; 
        cout<<"3. Solution of Differential Equations"<<endl;
        cout<<"4. Matrix Inversion"<<endl;
        cout<<"5. Exit"<<endl;
        cin>>choice;
        int choicein = 0;
        switch (choice)
        {
        case 1:
            cout<<"Choose an option"<<endl;
            cout<<"1. Jacobi iterative method"<<endl;
            cout<<"2. Gauss-Seidel iterative method"<<endl;
            cout<<"3. Gauss elimination"<<endl;
            cout<<"4. Gausss-Jordan elimination"<<endl;
            cout<<"5. LU factorization"<<endl;
            cout<<"6. Back to main menu"<<endl;
            cin>>choicein;
            switch (choicein)
            {
            case 1:
                Jacobi();
                break;
            
            case 2:
                gauss_seidal();
                break;

            case 3:
                gauss_elimination();
                break;

            case 4:
                Gauss_jordan();
                break;

            case 5:
                LU();
                break;
            
            case 6:
                break;
            }
            break;
        case 2:
            cout<<"Choose an option"<<endl;
            cout<<"1. Bisection method"<<endl;
            cout<<"2. False position method"<<endl;
            cout<<"3. Secant method"<<endl;
            cout<<"4. Newton Raphson method"<<endl;
            cout<<"5. Back to main menu"<<endl;
            cin>>choicein;
            switch (choicein)
            {
            case 1:
                bisection_method();
                break;
            
            case 2:
                false_position();
                break;

            case 3:
                secant();
                break;

            case 4:
                newton_raphson();
                break;

            case 5:
                break;
            }
            break;
        case 3:
            cout<<"Choose an option"<<endl;
            cout<<"1. Runge-Kutta method"<<endl;
            cout<<"2. Back"<<endl;
            cin>>choicein;
            switch (choicein)
            {
            case 1:
                runge_kutta();
                break;
            
            case 2:
                break;
            }
            break;
        case 4:
            cout<<"Choose an option"<<endl;
            cout<<"1. Augmented Matrix method"<<endl;
            cout<<"2. Back"<<endl;
            cin>>choicein;
            switch (choicein)
            {
            case 1:
                Inverse();
                break;
            
            case 2:
                break;
            }
            break;
        case 5:
            quit = 1;
            break;
        }
        if(quit){
            break;
        }
    }
}