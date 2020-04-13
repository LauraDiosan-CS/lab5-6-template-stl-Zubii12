#include "TestAplicatie.h"
#include <assert.h>

TestAplicatie::TestAplicatie(){
}

TestAplicatie::~TestAplicatie(){
}

void TestAplicatie::testGetAndSet(){
	Aplicatie a1("zubii1", 1, "ram");
	assert(strcmp(a1.getNume(), "zubii1") == 0);
	assert(a1.getConsumMemorieKb() == 1);
	assert(strcmp(a1.getStatus(), "ram") == 0);
	a1.setNume("zubii11");
	a1.setConsumMemorieKb(11);
	a1.setStatus("swap");
	assert(strcmp(a1.getNume(), "zubii11") == 0);
	assert(a1.getConsumMemorieKb() == 11);
	assert(strcmp(a1.getStatus(), "swap") == 0);
}

void TestAplicatie::testOperator(){
	Aplicatie a1;
	Aplicatie a2("zubii2", 2, "swap");
	a1 = a2;
	assert(a1 == a2);
}

void TestAplicatie::runTests(){
	std::cout << " TESTE ENTITATE . . . " << std::endl;
	testGetAndSet();
	testOperator();
	std::cout << " OK !" << std::endl;
}
