#include "Stud.h"
#include "Mylib.h"


void ived(Stud& Lok) {
	cout << "Ivesti varda ir pavarde: ";
	cin >> Lok.vardas >> Lok.pavarde;

	int ndCount;
	cout << "Ivesti namu darbu skaiciu: ";
	cin >> ndCount;
	Lok.ND.resize(ndCount);

	cout << "Ivesti namu darbu rezultatus(10-baleje sistemoje): ";
	for (int i = 0; i < ndCount; ++i) {
		cin >> Lok.ND[i];
	}

	cout << "Ivesti egzamino rezultata: ";
	cin >> Lok.egz;
}



	void output(const Stud Lok)
{

	cout << setw(15) << left << Lok.vardas << setw(15) << left << Lok.pavarde
		<< setw(5) << right << fixed << setprecision(2) << Lok.GalutinisVid
	    << endl;

}

void val(Stud& Lok) {
	Lok.vardas.clear();
	Lok.pavarde.clear();
	Lok.ND.clear();
}