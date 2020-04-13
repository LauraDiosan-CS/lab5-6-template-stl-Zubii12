#include <iostream>
#include "Aplicatie.h"
#include "TestAplicatie.h"
#include "TestRepositoryMap.h"
#include "TesteService.h"
#include "UserInterface.h"

int main()
{
    TestAplicatie testAplicatie;
    testAplicatie.runTests();
    
    TestRepositoryMap testRepositoryMap;
    testRepositoryMap.runTests();

    TesteService testeService;
    testeService.runTests();

    UserInterface ui;
    ui.showUI();
}