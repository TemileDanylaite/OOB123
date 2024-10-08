#include "Mylib.h"
#include "Stud.h"


double apskaiciuotiMediana(std::vector<int>& nd) {
	std::sort(nd.begin(), nd.end());
	int n = nd.size();
	if (n % 2 == 0) {
		return(static_cast<double>(nd[n / 2 - 1]) + static_cast<double>(nd[n / 2])) / 2.0;
	}
	else {
		return static_cast<double>(nd[n / 2]);
	}
}


void apskaiciuotiGalutinius(Stud& Lok) {
	if (Lok.ND.empty()) {
		cout << "Nd yra tuscias, negalima suskaiciuoti galutinio balo" << endl;
		Lok.GalutinisVid = 0.0;
		Lok.GalutinisMed = 0.0;
		return;
	}
	double vidutinis = 0.0;
	for (double nd : Lok.ND) {
		vidutinis += nd;
	}
	vidutinis /= Lok.ND.size();
    Lok.GalutinisVid = 0.4 * vidutinis + 0.6 * Lok.egz;

	double mediana = apskaiciuotiMediana(Lok.ND);
	Lok.GalutinisMed = 0.4 * mediana + 0.6 * Lok.egz;
}

void output(const Stud& Lok, bool isFromFile = false) {
	cout << setw(15) << left << Lok.vardas << setw(15) << left << Lok.pavarde
		<< setw(5) << right << fixed << setprecision(2) << Lok.GalutinisVid;

	if (!isFromFile) {
		cout << setw(15) << right << fixed << setprecision(2) << Lok.GalutinisMed;
	}
	cout << endl;
}

int main()
{
	cout << "Ar norite sugeneruoti studentu failus?(taip/ne): ";
	string generuotiFailoPasirinkima;
	cin >> generuotiFailoPasirinkima;

	if (generuotiFailoPasirinkima == "taip") {
		sugeneruotiStudentoFaila("studentai1000.txt", 1000, 5);
		sugeneruotiStudentoFaila("studentai10000.txt", 10000, 7);
		sugeneruotiStudentoFaila("studentai100000.txt", 100000, 6);
		sugeneruotiStudentoFaila("studentai1000000.txt", 1000000, 8);
		sugeneruotiStudentoFaila("studentai10000000.txt", 10000000, 4);
		cout << "Failai sugeneruoti!" << endl;
	}

	vector<Stud> Vec1;
	Stud Temp;

	cout << "Ar norite ivesti studentu duomenis ar nuskaityti is failo?(ivesti/nuskaityti): ";
	string pasirinkimas;
	cin >> pasirinkimas;

	
	if (pasirinkimas == "nuskaityti") {
		nuskaitytiIsFailo(Vec1,"studentai1000.txt");


		for (auto& studentas : Vec1) {
			apskaiciuotiGalutinius(studentas);
		}

		vector<Stud> vargsiukai, kietiakiai;
		for (const auto& studentas : Vec1) {
			if (studentas.GalutinisVid < 5.0) {
				vargsiukai.push_back(studentas);
			}
			else {
				kietiakiai.push_back(studentas);
			}
		}

		sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
			return a.vardas < b.vardas;
			});

		cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
			<< setw(5) << right << "Galutinis(Vid.)" << endl;

		cout << string(60, '-') << endl;

		cout << "Vargsiukai (galutinis balas < 5.0): " << endl;
		for (const auto& studentas : vargsiukai) {
			output(studentas, true);
		}
		cout << string(60, '-') << endl;

		cout << "Kietiakiai (galutinis balas >= 5.0): " << endl;
		for (const auto& studentas : kietiakiai) {
			output(studentas, true);
		}
	}
	else {
		cout << "Kiek yra studentu ?";
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cout << "Please input user data: " << endl;
			ived(Temp);

			apskaiciuotiGalutinius(Temp);
			Vec1.push_back(Temp);
			val(Temp);
		}


	    sort(Vec1.begin(), Vec1.end(), [](const Stud& a, const Stud& b) {
		return a.vardas < b.vardas;
		});

		cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde"
		<< setw(5) << right << "Galutinis(Vid.)"
		<< setw(5) << right << " Galutinis(Med.)" << endl;

	    cout << string(60, '-') << endl;

		for (const auto& studentas : Vec1) {
			output(studentas, false);
		}

	}

	system("pause");
	return 0;
}
