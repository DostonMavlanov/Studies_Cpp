#include <iostream>
#include <cmath>
#include <vector>
#include <optional>
#include <utility>
using namespace std;

optional<pair<double, double>> SolveQuadraticEquation(double a, double b, double c){
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0){
        return nullopt;
    }
    double x1 = (-b + sqrt(discriminant)) / (2 * a);
    double x2 = (-b - sqrt(discriminant)) / (2 * a);

    return pair{x1, x2};
}

int main(){
    double a, b, c;
    cin >> a >> b >> c;

    if (const auto roots = SolveQuadraticEquation(a, b, c);
        roots.has_value())
    {
        cout << roots.value().first <<' '<<  roots->second << '\n';
    }else{
        cout << " The equation has no solution " << '\n'; 
    }
    return 0;
}