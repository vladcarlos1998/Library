#pragma once
#include "Carti.h"
#include "Repository.h"

class Action_Undo {
public:
	virtual void doUndo() = 0;
	virtual ~Action_Undo() {};
};

class Undo_add :public Action_Undo {
private:
	Carti add;
	Repo& repo;
public:
	Undo_add(Repo& repo, const Carti& c) :repo{ repo }, add{ c } {}
	void doUndo() override {
		repo.rem(add);
	}
};

class Undo_rem :public Action_Undo {
private:
	Carti rem;
	Repo& repo;
public:
	Undo_rem(Repo& repo, const Carti& c) :repo{ repo }, rem{ c } {}
	void doUndo() override {
		repo.add(rem);
	}
};

class Undo_upd :public Action_Undo {
private:
	Carti upd;
	char cmd;
	string a;
	int b;
	Repo& repo;
public:
	Undo_upd(Repo& repo, const Carti& c, const char cmd, const string& a, const int b) :repo{ repo }, upd{ c }, cmd{ cmd }, a{ a }, b{ b } {}
	void doUndo() override {
		repo.upd(upd, cmd, a, b);
	}
};