#pragma once
#include "Repository.h"

class Repo_F :public Repo {
public:
	/*Repo_F(std::string f_name) : Repo(), f_name{ f_name } {
	load();
	}

	~Repo_F();*/

	Repo_F() = default;
	Repo_F(const Repo_F& ot) = delete;

	void add_f(const Carti& c) {
		Repo::add(c);
		write();
	}

	void rem_f(const Carti& c) {
		Repo::rem(c);
		write();
	}

	/*void upd_f(const Carti& c, const char cmd, const string& a, const int b) {
	Repo::upd(c, cmd, a, b);
	write();
	}*/

	const vector<Carti>& get_all_f() const noexcept { return this->get_all(); }

	void CSV() const;

	void load();

private:
	std::string f_name = "Fisier.txt";
	//void load();
	void write();
};