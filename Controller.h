#pragma once
#include "Carti.h"
#include "Validator.h"
#include "Repository.h"
#include "Repository_file.h"
#include <vector>
#include <string>
#include <functional>
#include "Undo.h"

using namespace std;

typedef bool(*Conditie)(const Carti& c1, const Carti& c2);

class serv {
public:

	serv(Repo& repo, valid& val, Repo_F& repo_f) noexcept : repo{ repo }, val{ val }, repo_f{ repo_f } {}
	serv(const serv& ot) = delete;

	const vector<Carti>& get_all() const noexcept {
		return repo.get_all();
	}

	void adauga(const string& titlu, const string& autor, const string& gen, int an);

	void sterge(const string& titlu, const string& autor);

	void modificare(const string& titlu, const string& autor, const char cmd, const string& a, const int b);

	Carti cauta(const string& titlu, const string& autor, const vector<Carti>& carti);

	vector<Carti> filtru_titlu(const string& titlu)const;

	vector<Carti> filtru_anul_aparitiei(const int an)const noexcept;

	vector<Carti> sort_titlu()const;

	vector<Carti> sort_autor()const;

	vector<Carti> sort_an_gen()const;

	const vector<Carti>& get_cos() const noexcept {
		return repo.get_cos();
	}

	int  size_get_cos() {
		return repo.size_get_Cos();
	}

	void adauga_cos(const string& titlu, const string& autor);

	void sterge_cos();

	void pop_cos(int n);

	//void pop_off();

	void afis_fis() { this->repo_f.CSV(); }

	void Undo();

	void rem_Undo();

private:
	Repo& repo;
	valid& val;
	Repo_F& repo_f;
	vector<Action_Undo*> undo;
	vector<Carti> filtru(function<bool(const Carti&)> fct)const;
	vector<Carti> sortu(Conditie conditie)const;
};

void test_ctrl();
