#include <iostream>
#include <ostream>
#include <vector>
#include <numeric>


using namespace std;

class Rational{
public:
    Rational() = default;

    Rational (int numerator) : numerator_(numerator)
    {
    }

    Rational (int numerator, int denominator) : numerator_(numerator), denominator_(denominator)
    {
        Normalize();
    }

    int Numerator() const{
        return numerator_;
    }

    int Denominator() const{
        return denominator_;
    }

    Rational& operator+=(Rational right){
        numerator_ = numerator_ * right.denominator_ + denominator_ * right.numerator_;
        denominator_ = denominator_ * right.denominator_;
        Normalize();
        return *this;
    }

    Rational& operator-=(Rational right){
        numerator_ = numerator_ * right.denominator_ - denominator_ * right.numerator_;
        denominator_ = denominator_ * right.denominator_;
        Normalize();
        return *this;
    }

    Rational& operator*=(Rational right){
        numerator_ *= right.numerator_;
        denominator_ *= right.denominator_;
        Normalize();
        return *this;
    }

    Rational& operator/=(Rational right){
        numerator_ *= right.denominator_;
        denominator_ *= right.numerator_;
        
        if (denominator_ == 0){
            throw invalid_argument("value is zero"s);
        }

        Normalize();
        return *this;
    }
private:
    void Normalize(){
        if (denominator_ < 0){
            denominator_ *= -1;
            numerator_ *= -1;
        }
        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    } 
    int numerator_ = 0;
    int denominator_ = 1;
};


ostream& operator<<(ostream& out, Rational value){
    out << value.Numerator() << "/"s << value.Denominator();
    return out;
}

istream& operator>>(istream& in, Rational value){
    int numerator;
    int denominator;
    char slash;
    in >> numerator >> slash >> denominator;
    value = Rational{numerator, denominator};
    return in;
}

Rational operator+(Rational left, Rational right){
    return left += right;
}

Rational operator-(Rational left, Rational right){
    return left -= right;
}

Rational operator*(Rational left, Rational right){
    return left *= right;
}

Rational operator/(Rational left, Rational right){
    return left /= right;
}

Rational operator-(Rational value){
    return {-value.Numerator(), value.Denominator()};
}

Rational operator+(Rational value){
    return value;
}

bool operator==(Rational left, Rational right){
    return (left.Numerator() == right.Numerator()) && (left.Denominator() == right.Denominator());
}

bool operator!=(Rational left, Rational right){
    return !(left == right);
}

bool operator<(Rational left, Rational right){
    return (left.Numerator() * right.Denominator() < left.Denominator() * right.Numerator());
}

bool operator>(Rational left, Rational right){
    return (left.Numerator() * right.Denominator() > left.Denominator() * right.Numerator()); 
}

bool operator<=(Rational left, Rational right){
    return !(left > right);
}

bool operator>=(Rational left, Rational right){
    return !(left < right);
}

int main(){
    setlocale(LC_ALL, "Russian");
    try{
        const Rational three_fifth{ 3, 5 };
        const Rational zero;
        cout << three_fifth << " / "s << zero << " = "s << (three_fifth / zero) << endl;
    }catch (const invalid_argument& e){
        cout << "Fail: "s << e.what() << endl;
    }

    try{
        Rational value{3, 5};
        value /= Rational();
        //Следующая строка не должна выполниться 
        cout << value << endl;
    }catch(const invalid_argument& e){
        cout << "Fail: "s << e.what() << endl;
    }
}