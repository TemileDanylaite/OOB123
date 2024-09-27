#include "Stud.h"
#include "Mylib.h"

void nuskaitytiIsFailo(std::vector<Stud>& Vec1, const std::string& failoVardas) {
	try {
		std::ifstream inFile(failoVardas);
		if (!inFile) {
<<<<<<< HEAD
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


=======
			throw runtime_error("Nepavylo atdiaryti failo:" + failoVardas);
		}
		string header;
		getline(inFile, header);

		Stud temp;
		while (inFile >> temp.vardas >> temp.pavarde) {
			temp.ND.clear();

			for (int i = 0; i < 5; ++i) {
				int nd;
				if (!(inFile >> nd)) {
					throw runtime_error("Nepavykko nuskaityti ND balo:" + temp.vardas + " " + temp.pavarde);
				}
				temp.ND.push_back(nd);
			}

			if (!(inFile >> temp.egz)) {
				throw runtime_error("Nepavykko nuskaityti egzamino balo:" + temp.vardas + " " + temp.pavarde);
			}
>>>>>>> origin/v0.1
			Vec1.push_back(temp);
		}
		inFile.close();

	}catch (const std::exception& e) {
		std::cerr << "Klaida: " << e.what() << endl;
	}

	
}