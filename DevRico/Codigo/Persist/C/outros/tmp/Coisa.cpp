#include "Coisa.hpp"
#include <iomanip.h>
#include <iostream.h>

Coisa::Coisa(){ cout << "call Coisa::Coisa" << endl; };

Coisa::~Coisa() {cout << "call ~Coisa::Coisa" << endl;};

void Coisa::ExibaMsg() {cout << "call Coisa::ExibeMsg" << endl;};
