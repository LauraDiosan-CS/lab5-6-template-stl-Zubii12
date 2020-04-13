#include "TestRepositoryMap.h"
#include <assert.h>
#include "Aplicatie.h"
void TestRepositoryMap::testCRUDAndFind(){
	Aplicatie a1("zubii1", 1, "ram");
	Aplicatie a2("zubii2", 2, "swap");
	Aplicatie a3("zubii3", 3, "ram");

	RepositoryMap repo;

	repo.add(a1);
	repo.add(a2);
	repo.add(a3);
	assert(repo.find(a1));
	assert(repo.find(a2));
	assert(repo.find(a3));

	assert(repo.size() == 3);

	repo.remove(a3);
	assert(repo.find(a3) == false);

	assert(repo.size() == 2);
	
	assert(repo.update(a2, "zubii22", 22, "ram"));

	std::map<int, Aplicatie> all;
	all = repo.getAll();
	
	assert(strcmp(all[1].getNume(), "zubii22") == 0);
	assert(all[1].getConsumMemorieKb() == 22);
	assert(strcmp(all[1].getStatus(), "ram") == 0);

	
}

void TestRepositoryMap::runTests(){
	std::cout << " TESTE REPO . . . " << std::endl;
	testCRUDAndFind();
	std::cout << " OK !" << std::endl;
}
