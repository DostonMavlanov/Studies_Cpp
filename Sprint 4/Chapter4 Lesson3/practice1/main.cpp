#include "Builder.h"
#include <iostream>

using namespace std;

int main(){
    Builder Tom;
    Wall wall(3.5, 2.45);
    cout << Tom.CalcBricksNeeded(wall) << endl;

}