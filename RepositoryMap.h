#pragma once
#include "Aplicatie.h"
#include <map>

class RepositoryMap{
private:
	std::map<int, Aplicatie> storage;
	int ID;
public:
	RepositoryMap();
	RepositoryMap(const RepositoryMap& repo);
	~RepositoryMap();
	void add(const Aplicatie& a);
	bool remove(const Aplicatie& a);
	bool find(const Aplicatie& a);
	int size();
	bool update(const Aplicatie& a, const char* n, int c, const char* s);
	std::map<int, Aplicatie> getAll();

};

