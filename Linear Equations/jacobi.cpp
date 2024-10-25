#include <bits/stdc++.h>
using namespace std;

void Jacobi() {
    cout << "INPUT FIVE EQUATIONS" << endl;
    int x1, x2, x3, x4, x5;
    int y1, y2, y3, y4, y5;
    int z1, z2, z3, z4, z5;
    int w1, w2, w3, w4, w5;
    int v1, v2, v3, v4, v5;
    int d1, d2, d3, d4, d5;

    // Take input for the five equations
    cout << "INPUT x1 y1 z1 w1 v1 d1" << endl;
    cin >> x1 >> y1 >> z1 >> w1 >> v1 >> d1;

    cout << "INPUT x2 y2 z2 w2 v2 d2" << endl;
    cin >> x2 >> y2 >> z2 >> w2 >> v2 >> d2;

    cout << "INPUT x3 y3 z3 w3 v3 d3" << endl;
    cin >> x3 >> y3 >> z3 >> w3 >> v3 >> d3;

    cout << "INPUT x4 y4 z4 w4 v4 d4" << endl;
    cin >> x4 >> y4 >> z4 >> w4 >> v4 >> d4;

    cout << "INPUT x5 y5 z5 w5 v5 d5" << endl;
    cin >> x5 >> y5 >> z5 >> w5 >> v5 >> d5;

    // Initial guesses for x, y, z, w, v
    float e1 = 0, e2 = 0, e3 = 0, e4 = 0, e5 = 0;
    float tolerance = 0.00001;
    int i = 1;

    cout << "ITERATION   x        y        z        w        v" << endl;
    while (true) {
        float ans1, ans2, ans3, ans4, ans5;

        // Apply Jacobi iteration formulas
        ans1 = (d1 - ((y1 * e2) + (z1 * e3) + (w1 * e4) + (v1 * e5))) / x1;
        ans2 = (d2 - ((x2 * e1) + (z2 * e3) + (w2 * e4) + (v2 * e5))) / y2;
        ans3 = (d3 - ((x3 * e1) + (y3 * e2) + (w3 * e4) + (v3 * e5))) / z3;
        ans4 = (d4 - ((x4 * e1) + (y4 * e2) + (z4 * e3) + (v4 * e5))) / w4;
        ans5 = (d5 - ((x5 * e1) + (y5 * e2) + (z5 * e3) + (w5 * e4))) / v5;

        // Print the current iteration values
        //cout << i << " :      " << ans1 << "   " << ans2 << "  " << ans3 << "  " << ans4 << "  " << ans5 << endl;

        // Check for convergence
        if (fabs(e1 - ans1) < tolerance && fabs(e2 - ans2) < tolerance && fabs(e3 - ans3) < tolerance && fabs(e4 - ans4) < tolerance && fabs(e5 - ans5) < tolerance) {
            break;
        }

        // Update for the next iteration
        e1 = ans1;
        e2 = ans2;
        e3 = ans3;
        e4 = ans4;
        e5 = ans5;
        i++;
    }

    cout << "Solution:\n";
    cout << "x = " << e1 << "\ny = " << e2 << "\nz = " << e3 << "\nw = " << e4 << "\nv = " << e5 << endl;

    
}
