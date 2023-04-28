#include "save.h"
#include<iostream>
#include<fstream>
#include<sstream>

std::vector<std::string> CsvSave::Load(std::string _pass) {

	std::ifstream file(_pass);
	if (!file.is_open())
		return std::vector<std::string>();

	std::string oneS;
	std::vector<std::string> getS;
	while (std::getline(file, oneS)) {

		std::istringstream inS(oneS);
		std::string twoS;

		while (std::getline(inS, twoS, ',')) 
			getS.emplace_back(twoS);
		
	}
	return getS;
}

void CsvSave::Save(std::string _pass, std::vector<std::string>_str,int _num) {

	std::ofstream ofs(_pass);
	for (int i = 0; static_cast<unsigned int>(i) < _str.size(); i++) {
		if (i % _num == 0)
			ofs << std::endl;

		ofs << _str[i].c_str() << ',';
	}
	ofs.close();
}
