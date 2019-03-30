#include "Controller.h"
#include <functional>
#include <algorithm>
#include <assert.h>
#include "Repository++.h"

using namespace std;

void serv::Undo() {
	if (undo.empty()) {
		throw RepoException("Nu mai exista operatii");
	}
	Action_Undo* act = undo.back();
	act->doUndo();
	undo.pop_back();
	delete act;
}

void serv::adauga(const string& titlu, const string& autor, const string& gen, int an) {
	Carti c{ titlu, autor, gen, an };
	val.validare(c);
	ADD_A(repo, c).add();
	undo.push_back(new Undo_add(repo, c));
}

void serv::sterge(const string& titlu, const string& autor) {
	Carti c = cauta(titlu, autor, this->get_all());
	val.validare(c);
	//repo.rem(c);
	REM_A(repo, c).rem();
	undo.push_back(new Undo_rem(repo, c));
}

void serv::modificare(const string& titlu, const string& autor, const char cmd, const string& a, const int b) {
	Carti c = cauta(titlu, autor, this->get_all());
	val.validare(c);
	repo.upd(c, cmd, a, b);
	switch (cmd)
	{
	case '1':
		c.set_titlu(a);
		undo.push_back(new Undo_upd(repo, c, cmd, titlu, b));
		break;
	case '2':
		c.set_autor(a);
		undo.push_back(new Undo_upd(repo, c, cmd, autor, b));
		break;
	case '3':
		undo.push_back(new Undo_upd(repo, c, cmd, c.get_gen(), b));
		break;
	case '4':
		undo.push_back(new Undo_upd(repo, c, cmd, a, c.get_an()));
		break;
	}
}

Carti serv::cauta(const string& titlu, const string& autor, const vector<Carti>& carti) {
	int i = repo.find(titlu, autor);
	return carti.at(i);
}

vector<Carti> serv::filtru(function<bool(const Carti&)> fct)const {
	vector<Carti> rez;
	for (const auto& c : repo.get_all()) {
		if (fct(c)) {
			rez.push_back(c);
		}
	}
	return rez;
}

vector<Carti> serv::filtru_titlu(const string& titlu)const {
	return filtru([titlu](const Carti& c) noexcept {
		return c.get_titlu() == titlu;
	});
}

vector<Carti> serv::filtru_anul_aparitiei(const int an)const noexcept {
	return filtru([an](const Carti& c) {
		return c.get_an() == an;
	});
}

vector<Carti> serv::sortu(Conditie conditie)const {
	vector<Carti> rez{ repo.get_all() };
	sort(rez.begin(), rez.end(), conditie);
	return rez;
}

vector<Carti> serv::sort_titlu()const {
	return sortu([](const Carti& c1, const Carti& c2) {
		return c1.get_titlu() < c2.get_titlu();
	});
}

vector<Carti> serv::sort_autor()const {
	return sortu([](const Carti& c1, const Carti& c2) {
		return c1.get_autor() < c2.get_autor();
	});
}

vector<Carti> serv::sort_an_gen()const {
	return sortu([](const Carti& c1, const Carti& c2) {
		if (c1.get_an() == c2.get_an()) {
			return c1.get_gen() < c2.get_gen();
		}
		return c1.get_an() < c2.get_an();
	});
}

void serv::adauga_cos(const string& titlu, const string& autor) {
	Carti c = cauta(titlu, autor, get_all());
	repo_f.add_f(c);
	//repo.addC(c);
	ADD_C(repo, c).add();
}

void serv::sterge_cos() {
	for (auto& c : this->get_cos()) {
		this->repo_f.rem_f(c);
	}
	//this->repo.remC();
	REM_C(this->repo).rem();
}

void serv::pop_cos(int n) {
	this->repo.random(n);
	for (auto& c : this->get_cos()) {
		this->repo_f.add_f(c);
	}
}

/*void serv::pop_off() {
	for (auto& c : this->repo_f.get_all_f()) {
		this->repo.add(c);
	}
}*/

void serv::rem_Undo() {
	for (auto& u : this->undo) {
		u->~Action_Undo();
		free(u);
	}
}

void test_adauga() {
	Repo rep;
	valid val;
	Repo_F fis;
	serv ctr{ rep,val,fis };
	ctr.adauga("a", "a", "F", 111);
	assert(ctr.get_all().size() == 1);

	try {
		ctr.adauga("", "", "", -1);
	}
	catch (validator&) {
		assert(true);
	}

	try {
		ctr.adauga("a", "a", "F", -1);
	}
	catch (validator&) {
		assert(true);
	}
	ctr.rem_Undo();
}

void test_adaugaC() {
	Repo rep;
	valid val;
	Repo_F fis;
	serv ctr{ rep,val,fis };
	ctr.adauga("a", "a", "F", 111);
	assert(ctr.get_cos().size() == 0);
	ctr.adauga_cos("a", "a");
	assert(ctr.get_cos().size() == 1);
	ctr.rem_Undo();
}

void test_sterge() {
	Repo rep;
	valid val;
	Repo_F fis;
	serv ctr{ rep,val,fis };
	ctr.adauga("a", "a", "F", 111);
	ctr.adauga("b", "b", "SF", 222);
	assert(ctr.get_all().size() == 2);

	ctr.sterge("a", "a");
	assert(ctr.get_all().size() == 1);

	try {
		ctr.sterge("", "");
	}
	catch (RepoException&) {
		assert(true);
	}

	/*try {
		ctr.sterge("a", "a");
		assert(false);
	}
	catch (validator&) {
		assert(true);
	}*/
	ctr.rem_Undo();
}

void test_stergeC() {
	Repo rep;
	valid val;
	Repo_F fis;
	serv ctr{ rep,val,fis };
	ctr.adauga("a", "a", "F", 111);
	ctr.adauga("b", "b", "SF", 222);
	ctr.adauga_cos("a", "a");
	ctr.adauga_cos("b", "b");
	assert(ctr.get_cos().size() == 2);
	ctr.sterge_cos();
	assert(ctr.get_cos().size() == 0);
	ctr.rem_Undo();
}

void test_modificare() {
	Repo rep;
	valid val;
	Repo_F fis;
	serv ctr{ rep,val,fis };
	ctr.adauga("a", "a", "F", 111);
	assert(ctr.get_all().size() == 1);

	ctr.modificare("a", "a", '1', "b", 0);
	ctr.modificare("b", "a", '2', "b", 0);
	ctr.modificare("b", "b", '3', "SF", 0);
	ctr.modificare("b", "b", '4', "", 222);
	assert(ctr.get_all()[0].get_titlu() == "b");
	assert(ctr.get_all()[0].get_autor() == "b");
	assert(ctr.get_all()[0].get_gen() == "SF");
	assert(ctr.get_all()[0].get_an() == 222);

	try {
		ctr.modificare("", "", '1', "", 0);
	}
	catch (RepoException&) {
		assert(true);
	}

	/*try {
		ctr.modificare("a", "a", '1', "", 0);
		assert(false);
	}
	catch (validator&) {
		assert(true);
	}*/
	ctr.rem_Undo();
}

void test_cauta() {
	Repo rep;
	valid val;
	Repo_F fis;
	serv ctr{ rep,val,fis };
	ctr.adauga("a", "a", "F", 111);
	assert(ctr.get_all().size() == 1);

	assert(ctr.cauta("a", "a", rep.get_all()).get_titlu() == "a");
	assert(ctr.cauta("a", "a", rep.get_all()).get_autor() == "a");
	assert(ctr.cauta("a", "a", rep.get_all()).get_gen() == "F");
	assert(ctr.cauta("a", "a", rep.get_all()).get_an() == 111);
	ctr.rem_Undo();
}

void test_filtru() {
	Repo rep;
	valid val;
	Repo_F fis;
	serv ctr{ rep,val,fis };
	ctr.adauga("a", "a", "F", 6);
	ctr.adauga("a", "b", "F", 7);
	ctr.adauga("c", "a", "F", 6);
	assert(ctr.filtru_titlu("a").size() == 2);
	assert(ctr.filtru_titlu("c").size() == 1);
	assert(ctr.filtru_titlu("b").size() == 0);
	assert(ctr.filtru_anul_aparitiei(6).size() == 2);
	assert(ctr.filtru_anul_aparitiei(7).size() == 1);
	assert(ctr.filtru_anul_aparitiei(8).size() == 0);
	ctr.rem_Undo();
}

void test_sort() {
	Repo rep;
	valid val;
	Repo_F fis;
	serv ctr{ rep,val,fis };
	ctr.adauga("z", "z", "SF", 6);
	ctr.adauga("b", "a", "F", 6);
	ctr.adauga("c", "a", "F", 7);

	assert(ctr.sort_titlu()[0].get_titlu() == "b");
	assert(ctr.sort_titlu()[1].get_titlu() == "c");

	assert(ctr.sort_autor()[0].get_titlu() == "b");
	assert(ctr.sort_autor()[1].get_titlu() == "c");

	assert(ctr.sort_an_gen()[0].get_titlu() == "b");
	assert(ctr.sort_an_gen()[1].get_titlu() == "z");
	ctr.rem_Undo();
}

void test_pop() {
	Repo rep;
	valid val;
	Repo_F fis;
	serv ctr{ rep,val,fis };
	ctr.adauga("z", "z", "SF", 6);
	ctr.adauga("b", "a", "F", 6);
	ctr.adauga("c", "a", "F", 7);
	assert(ctr.get_cos().size() == 0);
	ctr.pop_cos(2);
	assert(ctr.get_cos().size() == 2);
	ctr.rem_Undo();
}

void test_undo() {
	Repo rep;
	valid val;
	Repo_F fis;
	serv ctr{ rep,val,fis };
	ctr.adauga("z", "z", "SF", 6);
	ctr.adauga("b", "a", "F", 6);
	ctr.adauga("c", "a", "F", 7);
	assert(ctr.get_all().size() == 3);
	ctr.Undo();
	assert(ctr.get_all().size() == 2);
	ctr.sterge("b", "a");
	assert(ctr.get_all().size() == 1);
	ctr.Undo();
	assert(ctr.get_all().size() == 2);
	ctr.modificare("z", "z", '4', "", 7);
	assert(ctr.get_all().size() == 2);
	ctr.Undo();
	assert(ctr.get_all().size() == 2);
	ctr.afis_fis();
	ctr.rem_Undo();
}

void test_ctrl() {
	test_adauga();
	test_sterge();
	test_modificare();
	test_cauta();
	test_filtru();
	test_sort();
	test_adaugaC();
	test_stergeC();
	test_pop();
	test_undo();
}