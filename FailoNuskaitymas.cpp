#include "Stud.h"
#include "Mylib.h"

void nuskaitytiIsFailo(std::vector<Stud>& Vec1, const std::string& failoVardas) {
	std::ifstream inFile(failoVardas);
	if (!inFile) {
		std::cerr << "Nepavyko atidaryti failo:" << failoVardas << endl;
		return;
	}
	string header;
	getline(inFile, header);

	Stud temp;
	while (inFile >> temp.vardas >> temp.pavarde) {
		temp.ND.clear();

		for (int i = 0; i < 5; ++i) {
			int nd;
			inFile >> nd;
			temp.ND.push_back(nd);
		}

		inFile >> temp.egz;

		Vec1.push_back(temp);
	}
	inFile.close();
}