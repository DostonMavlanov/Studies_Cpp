#include <iostream>
#include <utility>
#include <stdexcept>
#include <cmath>

using namespace std;

pair<double, double> SolveQuadraticEquation(double a, double b, double c){
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0){
        throw domain_error("The quadratic equation has no solution");
    }

    double x1 = (-b + sqrt(discriminant)) / (2 * a);
    double x2 = (-b - sqrt(discriminant)) / (2 * a);
    return {x1, x2};
}

int main(){
    try{
        double a, b, c;
        cin >> a >> b >> c;
        pair<double, double> roots = SolveQuadraticEquation(a, b, c);
        cout << roots.first << " " << roots.second << '\n';
    }catch(const domain_error& error) {
        cout << "Fail: "s << error.what() << '\n';
    }
    return 0;
}