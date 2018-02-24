#include <iostream>

class gravity(){
	static double G = 6.67384 * pow(10, -11);
public:
	double pull(kin one, kin two);
}
