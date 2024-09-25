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
	double vidutinis = 0.0;
	for (double nd : Lok.ND) {
		vidutinis += nd;
	}
	vidutinis /= Lok.ND.size();
	Lok.GalutinisVid = 0.4 * vidutinis + 0.6 * Lok.egz;

	double mediana = apskaiciuotiMediana(Lok.ND);
	Lok.GalutinisMed = 0.4 * mediana + 0.6 * Lok.egz;

}

int main()
{
	vector<Stud> Vec1;
	Stud Temp;
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
	cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(5) << right << " Galutinis(Vid.)" << setw(18) << right << " / Galutinis(Med.)" << endl;
	for (int i = 0; i < n; i++)
		output(Vec1.at(i));

	system("pause");
}