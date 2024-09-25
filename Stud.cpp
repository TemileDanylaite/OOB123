#include "Stud.h"
#include "Mylib.h"


void ived(Stud& Lok) {
	cout << "Ivesti varda ir pavarde: ";
	cin >> Lok.vardas >> Lok.pavarde;

	string pasirinkimas;
	cout << "Ar zinai, koks yra namu darbu skaicius?(taip/ne): ";
	cin >> pasirinkimas;

	if (pasirinkimas == "taip") {
		int ndCount;
		cout << "Ivesti namu darbu skaiciu: ";
		cin >> ndCount;
		Lok.ND.resize(ndCount);

		cout << "Ivesti namu darbu rezultatus(10-baleje sistemoje): ";
		for (int i = 0; i < ndCount; ++i) {
			cin >> Lok.ND[i];
		}
	}
	else if (pasirinkimas == "ne") {
		double nd;
		cout << "Ivesti namu darbu rezultatus(ivesti '-1',kad baigti):" << endl;
		while (true) {
			cin >> nd;
			if (nd == -1) {
				break;
			}
			Lok.ND.push_back(nd);
		}
	}

	cout << "Ivesti egzamino rezultata: ";
	cin >> Lok.egz;
}


	void output(const Stud& Lok, bool useMedian)
{
		cout << setw(15) << left << Lok.vardas << setw(15) << left << Lok.pavarde;
		if (useMedian) {
			cout <<setw(4) << right<< fixed << setprecision(2) << Lok.GalutinisMed << endl;
		}
		else {
			cout<< setw(5) << right << fixed << setprecision(2) << Lok.GalutinisVid << endl;

		}

}

void val(Stud& Lok) {
	Lok.vardas.clear();
	Lok.pavarde.clear();
	Lok.ND.clear();
}