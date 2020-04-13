#pragma once
#include "RepositoryMap.h"
#include "Aplicatie.h"

class Service{
private:
	RepositoryMap repo;
public:
	Service();
	Service(const RepositoryMap& repo);
	~Service();
	
	void setRepo(const RepositoryMap& repo);

	void add(const Aplicatie& a);
	bool del(const Aplicatie& a);
	bool update(const Aplicatie& a, const char*n, int c, const char* s);
	int size();
	std::map<int, Aplicatie> getAll();
	bool find(const Aplicatie& a);
};

