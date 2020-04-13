#include "TesteService.h"
#include <assert.h>

void TesteService::teste(){
	Aplicatie a1("zubii1", 1, "ram");
	Aplicatie a2("zubii2", 2, "swap");
	Aplicatie a3("zubii3", 3, "ram");

	RepositoryMap repo;

	Service service;
	service.setRepo(repo);

	service.add(a1);
	service.add(a2);
	service.add(a3);

	assert(service.size() == 3);

	service.del(a3);
	assert(service.find(a3) == false);

	assert(service.size() == 2);

	service.update(a2, "zubii22", 22, "ram");

	std::map<int, Aplicatie> all = service.getAll();
	assert(all[1] == Aplicatie("zubii22", 22, "ram"));


}

void TesteService::runTests(){
	std::cout << " TESTE SERVICE . . . " << std::endl;
	teste();
	std::cout << " OK !" << std::endl;
}
