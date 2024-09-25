#ifndef STUD_H_INCLUDED
#define STUD_H_INCLUDED
#include "Mylib.h"

struct Stud {
	std::string vardas, pavarde;
	std::vector<int> ND;
	double egz;
	double GalutinisVid;
	double GalutinisMed;

};

void ived(Stud& Lok);
void output(const Stud& Lok, bool useMedian);
void val(Stud& Lok);

#endif //STUD_H_INCLUDED