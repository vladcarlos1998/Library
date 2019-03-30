#include "Repository_file.h"
#include <fstream>
#include <Windows.h>

/*Repo_F::~Repo_F() {
for (auto& c : this->get_all_f()) {
this->rem_f(c);
}
}*/

void Repo_F::load() {
	std::ifstream f(f_name);
	if (!f.is_open()) {
		throw RepoException("Nu se poate deschide fisierul: " + f_name);
	}
	while (!f.eof()) {
		std::string titlu;
		f >> titlu;
		if (f.eof()) {
			break;
		}
		std::string autor;
		f >> autor;
		std::string gen;
		f >> gen;
		int an_aparitie;
		f >> an_aparitie;

		Carti c{ titlu, autor, gen, an_aparitie };
		Repo::add(c);
	}
	f.close();
}

void Repo_F::write() {
	std::ofstream g(f_name);
	if (!g.is_open()) {
		throw RepoException("Nu se poate deschide fisierul: " + f_name);
	}
	for (auto& c : get_all()) {
		g << c.get_titlu() << " \t " << c.get_autor() << " \t " << c.get_gen() << " \t " << c.get_an() << "\n";
	}
	g.close();
}

void Repo_F::CSV() const {
	string aux = "\"" + this->f_name + "\"";
	ShellExecuteA(NULL, NULL, "C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\EXCEL.EXE", aux.c_str(), NULL, SW_SHOWMAXIMIZED);
}