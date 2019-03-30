#pragma once
#include "Carti.h"
#include <vector>
#include <string>

using namespace std;

class Repo {
public:
	Repo() = default;

	Repo(const Repo& ot) = delete;

	void add(const Carti& c);

	void rem(const Carti& c);

	void upd(const Carti& c, const char cmd, const string& a, const int b);

	const vector<Carti>& get_all() const noexcept;

	int find(const string& titlu, const string& autor) const;

	void addC(const Carti& c);

	void remC();

	void random(int n);

	const vector < Carti>& get_cos()const noexcept;

	int size_get_Cos() { return cos.size(); }

private:
	vector<Carti> all;
	vector<Carti> cos;
	bool exist(const Carti& c);
};

class RepoException {
public:
	RepoException(string m) : mes{ m } {}
	friend ostream& operator << (ostream& out, const RepoException& ex);

private:
	string mes;
};

ostream& operator << (ostream& out, const RepoException& ex);

void test_repo();