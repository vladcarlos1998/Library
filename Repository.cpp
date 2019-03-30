#include "Repository.h"
#include "Repository_file.h"
#include <assert.h>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>

void Repo::add(const Carti& c) {
	if (exist(c)) {
		throw RepoException("Exista deja cartea " + c.get_titlu() + " de " + c.get_autor() + "\n");
	}
	all.push_back(c);
}

void Repo::rem(const Carti& c) {
	if (exist(c)) {
		int poz = find(c.get_titlu(), c.get_autor());
		all.erase(all.begin() + poz);
	}
	else
	{
		throw RepoException("Cartea " + c.get_titlu() + " de " + c.get_autor() + " nu exista\n");
	}
}

void Repo::upd(const Carti& c, const char cmd, const string& a, const int b) {
	if (exist(c)) {
		int poz = find(c.get_titlu(), c.get_autor());
		if (cmd == '1') {
			all[poz].set_titlu(a);
		}
		else if (cmd == '2') {
			all[poz].set_autor(a);
		}
		else if (cmd == '3') {
			all[poz].set_gen(a);
		}
		else if (cmd == '4') {
			all[poz].set_an(b);
		}
	}
	else
	{
		throw RepoException("Cartea " + c.get_titlu() + " de " + c.get_autor() + " nu exista\n");
	}
}

/*bool find2(Carti& c) {
return(c.get_titlu() == titlu && c.get_autor() == autor);
}*/

bool Repo::exist(const Carti& c) {
	string titlu = c.get_titlu();
	string autor = c.get_autor();
	//find(c.get_titlu(), c.get_autor());
	auto i = std::find_if(this->all.begin(), this->all.end(), [&titlu, &autor](const Carti& c) {
		return(c.get_titlu() == titlu && c.get_autor() == autor);
	});
	if (i == this->all.end()) {
		return false;
	}
	else {
		return true;
	}

}

int Repo::find(const string& titlu, const string& autor) const {
	int i = 0;
	for (const Carti& c : all) {
		if (c.get_titlu() == titlu && c.get_autor() == autor) {
			return i;
		}
		i++;
	}
	throw RepoException("Cartea " + titlu + " de " + autor + " nu exista\n");
}

const vector<Carti>& Repo::get_all() const noexcept {
	return all;
}

ostream& operator << (ostream& out, const RepoException& ex) {
	out << ex.mes;
	return out;
}

const vector<Carti>& Repo::get_cos() const noexcept {
	return this->cos;
}

void Repo::addC(const Carti& c) {
	if (exist(c)) {
		this->cos.push_back(c);
	}
	else {
		throw RepoException("Exista deja cartea " + c.get_titlu() + " de " + c.get_autor() + "\n");
	}
}

void Repo::remC() {
	for (const Carti& c : cos) {
		cos.erase(cos.begin());
		c.get_titlu();
	}
}

void Repo::random(int n) {
	auto seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(this->all.begin(), this->all.end(), std::default_random_engine(seed));
	for (const auto& c : this->all) {
		if (n == 0) {
			break;
		}
		this->addC(c);
		n--;
	}
}

void test_add() {
	Repo rep;
	rep.add(Carti{ "a", "a", "F", 111 });
	assert(rep.get_all().size() == 1);
	assert(rep.find("a", "a") == 0);

	rep.add(Carti{ "b", "b", "SF", 222 });
	assert(rep.get_all().size() == 2);

	try {
		rep.add(Carti{ "a", "a", "F", 111 });
	}
	catch (RepoException&) {
		assert(true);
	}
}

void test_addC() {
	Repo rep;
	rep.add(Carti{ "a", "a", "F", 111 });

	rep.add(Carti{ "b", "b", "SF", 222 });

	rep.addC(Carti{ "a", "a", "F", 111 });
	assert(rep.get_cos().size() == 1);
	rep.addC(Carti{ "b", "b", "SF", 222 });
	assert(rep.get_cos().size() == 2);

	try {
		rep.addC(Carti{ "c", "c", "F", 111 });
	}
	catch (RepoException&) {
		assert(true);
	}
}

void test_rem() {
	Repo rep;
	rep.add(Carti{ "a", "a", "F", 111 });
	rep.add(Carti{ "b", "b", "SF", 222 });
	assert(rep.get_all().size() == 2);
	rep.rem(Carti{ "a", "a", "F", 111 });
	assert(rep.get_all().size() == 1);

	/*try {
	rep.rem(Carti{ "a", "a", "F", 111 });
	assert(true);
	}
	catch (RepoException&) {
	assert(false);
	}*/
}

void test_random() {
	Repo rep;
	rep.add(Carti{ "a", "a", "F", 111 });
	rep.add(Carti{ "b", "b", "SF", 222 });
	rep.add(Carti{ "c", "c", "AC", 333 });
	rep.add(Carti{ "d", "d", "H", 444 });
	rep.random(2);
	assert(rep.get_cos().size() == 2);
}

void test_remC() {
	Repo rep;
	rep.add(Carti{ "a", "a", "F", 111 });
	rep.add(Carti{ "b", "b", "SF", 222 });
	rep.addC(Carti{ "a", "a", "F", 111 });
	rep.addC(Carti{ "b", "b", "SF", 222 });
	assert(rep.get_cos().size() == 2);
	rep.remC();
	assert(rep.get_cos().size() == 0);
}

void test_upd() {
	Repo rep;
	rep.add(Carti{ "a", "a", "F", 111 });
	assert(rep.get_all().size() == 1);
	rep.upd(Carti{ "a", "a", "F", 111 }, '1', "b", 0);
	assert(rep.get_all()[0].get_titlu() == "b");
	rep.upd(Carti{ "b", "a", "F", 111 }, '2', "b", 0);
	assert(rep.get_all()[0].get_autor() == "b");
	rep.upd(Carti{ "b", "b", "F", 111 }, '3', "SF", 0);
	assert(rep.get_all()[0].get_gen() == "SF");
	rep.upd(Carti{ "b", "b", "SF", 111 }, '4', "", 222);
	assert(rep.get_all()[0].get_an() == 222);
}

void test_find() {
	Repo rep;
	rep.add(Carti{ "a", "a", "F", 111 });
	rep.add(Carti{ "b", "b", "SF", 222 });

	int p = rep.find("a", "a");
	assert(p == 0);

	try {
		rep.find("a", "b");
	}
	catch (RepoException&) {
		assert(true);
	}
}

void test_repo() {
	test_add();
	test_rem();
	test_upd();
	test_find();
	test_addC();
	test_remC();
	test_random();
}