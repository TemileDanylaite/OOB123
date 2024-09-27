#include "Stud.h"
#include "Mylib.h"

void nuskaitytiIsFailo(std::vector<Stud>& Vec1, const std::string& failoVardas) {
	try {
		std::ifstream inFile(failoVardas);
		if (!inFile) {
			throw runtime_error("Nepavyko atdiaryti failo:" + failoVardas);
		}
		string line;
		while(getline(inFile, line)) {

			std::stringstream ss(line);
			Stud temp;
			temp.ND.clear();

			if (!(ss >> temp.vardas >> temp.pavarde)) {
				std::cerr << "Nepavyko nuskaityti studento vardo ir pavardes" << endl;
				continue;
			}
			int nd;
			while (ss >> nd) {
				temp.ND.push_back(nd);
			}
			if (temp.ND.size() < 1) {
	
				continue;
			}
			temp.egz = temp.ND.back();
			temp.ND.pop_back();


			Vec1.push_back(temp);
		}
		inFile.close();

	}catch (const std::exception& e) {
		std::cerr << "Klaida: " << e.what() << endl;
	}

}