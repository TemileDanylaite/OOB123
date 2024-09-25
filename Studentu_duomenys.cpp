#include "Mylib.h"
#include "Stud.h"


void apskaiciuotiGalutini(Stud& Lok) {
	double vidutinis = 0.0;
	for (double nd : Lok.ND) {
		vidutinis += nd;
	}
	vidutinis /= Lok.ND.size();
	Lok.GalutinisVid = 0.4 * vidutinis + 0.6 * Lok.egz;


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
		apskaiciuotiGalutini(Temp);
		Vec1.push_back(Temp);
		val(Temp);
	}
	cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(5) << right << " Galutinis(Vid.)" << endl;
	for (int i = 0; i < n; i++)
		output(Vec1.at(i));

	system("pause");
}