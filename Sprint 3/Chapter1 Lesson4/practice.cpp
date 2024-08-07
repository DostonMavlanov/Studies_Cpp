#include <iostream>
#include <numeric>

using namespace std;

class Rational{
public:
    Rational() = default;

    Rational(int numerator) : numerator_(numerator)
    {}

    Rational(int numerator, int denominator) 
        : numerator_(numerator), denominator_(denominator)
    {
        Normalize();
    }

private:
    void Normalize(){
        if (denominator_ < 0){
            numerator_ *= -1;
            denominator_ *= -1;
        }

        const int divisor = gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }
    int numerator_ = 0;
    int denominator_ = 1;
};

int main(){
    return 0;
}