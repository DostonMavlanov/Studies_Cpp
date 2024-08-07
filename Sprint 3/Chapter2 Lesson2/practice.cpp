#include <iostream>
#include <numeric>
#include <ostream>
#include <istream>

using namespace std;

class Rational{
public:
    Rational() = default;

    Rational(int numerator) : numerator_(numerator), denominator_(1)
    {
    }
    
    Rational(int numerator, int denominator) : numerator_(numerator), denominator_(denominator)
    {
        Normalize();
    }
    
    int Numenator() const {
        return numerator_;
    }

    int Denomiator() const {
        return denominator_;
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

ostream& operator<<(ostream& out, Rational& value){
    out << value.Numenator() << "/"s << value.Denomiator();
    return out;
}

istream& operator>>(istream& in, Rational& value){
    int numerator, denominator;
    char slash;
    in >> numerator >> slash >> denominator;
    value = Rational{numerator, denominator};
    return in;
}

int main(){
    return 0;
}