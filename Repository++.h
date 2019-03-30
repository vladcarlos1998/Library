#pragma once
#include "Carti.h"
#include "Repository.h"

class ADD {
public:
	virtual void add() = 0;
	virtual ~ADD() {};
};

class ADD_A :public ADD {
private:
	Carti c;
	Repo& repo;
public:
	ADD_A(Repo& repo, Carti& c) :repo{ repo }, c{ c } {}
	void add() override {
		repo.add(c);
	}
};

class ADD_C :public ADD {
private:
	Carti c;
	Repo& repo;
public:
	ADD_C(Repo& repo, Carti& c) :repo{ repo }, c{ c } {}
	void add() override {
		repo.addC(c);
	}
};

class REM {
public:
	virtual void rem() = 0;
	virtual ~REM() {};
};

class REM_A :public REM {
private:
	Carti c;
	Repo& repo;
public:
	REM_A(Repo& repo, Carti& c) :repo{ repo }, c{ c } {}
	void rem() override {
		repo.rem(c);
	}
};

class REM_C :public REM {
private:
	Repo & repo;
public:
	REM_C(Repo& repo) :repo{ repo } {}
	void rem() override {
		repo.remC();
	}
};