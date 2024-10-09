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

void irasytiVargsiukus(const vector<Stud>& vargsiukai, const string& failoPavadinimas) {
	ofstream failas(failoPavadinimas);
	if (failas.is_open()) {
		failas << setw(15) << left << "Vardas"
			<< setw(15) << left << "Pavarde"
			<< setw(20) << left << "Galutinis(Vid.)" << endl;


		for (const auto& studentas : vargsiukai) {
			failas << setw(15) << left << studentas.vardas
				<< setw(15) << left << studentas.pavarde
				<< setw(20) << left << fixed << setprecision(2) << studentas.GalutinisVid << endl;
	
		}
		failas.close();
		cout << "Vargsiukai issaugoti i faila: " << failoPavadinimas << endl;
	}
	else {
		cout << "Nepavyk atidaryti failo: " << failoPavadinimas << endl;
	}
}
void irasytiKietiakiai(const vector<Stud>& kietiakiai, const string& failoPavadinimas) {
	ofstream failas(failoPavadinimas);
	if (failas.is_open()) {
		failas << setw(15) << left << "Vardas"
			<< setw(15) << left << "Pavarde"
			<< setw(20) << left << "Galutinis(Vid.)" << endl;

		for (const auto& studentas : kietiakiai) {
			failas << setw(15) << left << studentas.vardas
				<< setw(15) << left << studentas.pavarde
				<< setw(20) << left << fixed << setprecision(2) << studentas.GalutinisVid << endl;
		}
		failas.close();
		cout << "Kietiakiai issaugoti i faila: " << failoPavadinimas << endl;
	}
	else {
		cout << "Nepavyk atidaryti failo: " << failoPavadinimas << endl;
	}
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
	using namespace std::chrono;

	cout << "Ar norite sugeneruoti studentu failus?(taip/ne): ";
	string generuotiFailoPasirinkima;
	cin >> generuotiFailoPasirinkima;

	if (generuotiFailoPasirinkima == "taip") {

		auto pradziosLaikas = steady_clock::now();
		sugeneruotiStudentoFaila("studentai1000.txt", 1000, 5);
		auto pabaigosLaikas = steady_clock::now();
		auto trukme1000 = duration_cast<duration<double>>(pabaigosLaikas - pradziosLaikas).count();
		cout << "1000 studentu failo kurimo trukme: " << fixed << setprecision(5) << trukme1000 << " s" << endl;

		auto pradziosLaikas = steady_clock::now();
		sugeneruotiStudentoFaila("studentai10000.txt", 10000, 7); 
		auto pabaigosLaikas = steady_clock::now();
		auto trukme10000 = duration_cast<duration<double>>(pabaigosLaikas - pradziosLaikas).count();
		cout << "10000 studentu failo kurimo trukme: " << fixed << setprecision(5) << trukme10000 << " s" << endl;

		auto pradziosLaikas = steady_clock::now();
		sugeneruotiStudentoFaila("studentai100000.txt", 100000, 6);
		auto pabaigosLaikas = steady_clock::now();
		auto trukme100000 = duration_cast<duration<double>>(pabaigosLaikas - pradziosLaikas).count();
		cout << "100000 studentu failo kurimo trukme: " << fixed << setprecision(5) << trukme100000 << " s" << endl;

		auto pradziosLaikas = steady_clock::now();
		sugeneruotiStudentoFaila("studentai1000000.txt", 1000000, 8);
		auto pabaigosLaikas = steady_clock::now();
		auto trukme1000000 = duration_cast<duration<double>>(pabaigosLaikas - pradziosLaikas).count();
		cout << "1000000 studentu failo kurimo trukme: " << fixed << setprecision(5) << trukme1000000 << " s" << endl;


		auto pradziosLaikas = steady_clock::now();
		sugeneruotiStudentoFaila("studentai10000000.txt", 10000000, 4);
		auto pabaigosLaikas = steady_clock::now();
		auto trukme10000000 = duration_cast<duration<double>>(pabaigosLaikas - pradziosLaikas).count();
		cout << "10000000 studentu failo kurimo trukme: " << fixed << setprecision(5) << trukme10000000 << " s" << endl;

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

		irasytiVargsiukus(vargsiukai, "vargsiukai.txt");
		irasytiKietiakiai(kietiakiai, "kietiakiai.txt");

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
