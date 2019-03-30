#pragma once
#include <iostream>
#include <string>

using namespace std;

class Carti
{
public:
	Carti(const string t, const string a, const string g, int an) :titlu{ t }, autor{ a }, gen{ g }, an_aparitie{ an } {}

	string get_titlu() const { return titlu; }
	string get_autor() const { return autor; }
	string get_gen() const { return gen; }
	int get_an() const noexcept { return an_aparitie; }
	void set_titlu(const string t) { titlu.replace(titlu.begin(), titlu.end(), t); }
	void set_autor(const string a) { autor.replace(autor.begin(), autor.end(), a); }
	void set_gen(const string g) { gen.replace(gen.begin(), gen.end(), g); }
	void set_an(int an) noexcept { an_aparitie = an; }

private:
	std::string titlu;
	std::string autor;
	std::string gen;
	int an_aparitie;
};

/*bool cmp_titlu(const Carti& c1, const Carti& c2);
bool cmp_autor(const Carti& c1, const Carti& c2);
bool cmp_gen(const Carti& c1, const Carti& c2);
bool cmp_an(const Carti& c1, const Carti& c2);*/