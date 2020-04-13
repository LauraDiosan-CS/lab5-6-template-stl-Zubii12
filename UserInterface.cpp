#include "UserInterface.h"

void UserInterface::add(){
	char* nume = new char[10];
	int c = 0;
	char* status = new char[4];
	std::cout << std::endl << "Introduceti numele: ";
	std::cin >> nume;
	
	std::cout << std::endl << "Introduceti consumul memoriei ( > 0 ) in KB: ";
	std::cin >> c;

	std::cout << std::endl << "Introduceti statsul: RAM sau SWAP: ";
	std::cin >> status;

	service.add(Aplicatie(nume, c, status));
}

void UserInterface::del() {
	char* nume = new char[10];
	int c = 0;
	char* status = new char[4];
	std::cout << std::endl << "Introduceti numele: ";
	std::cin >> nume;

	std::cout << std::endl << "Introduceti consumul memoriei ( > 0 ) in KB: ";
	std::cin >> c;

	std::cout << std::endl << "Introduceti statsul: RAM sau SWAP: ";
	std::cin >> status;
	bool rez = service.find(Aplicatie(nume, c, status));
	if (rez) {
		service.del(Aplicatie(nume, c, status));
		std::cout << " Aplicatia a fost stearsa ! " << std::endl;
	}
	else {
		std::cout << " Aplicatia nu a fost stearsa " << std::endl;
	}
}

void UserInterface::find(){
	char* nume = new char[10];
	int c = 0;
	char* status = new char[4];
	std::cout << std::endl << "Introduceti numele: ";
	std::cin >> nume;

	std::cout << std::endl << "Introduceti consumul memoriei ( > 0 ) in KB: ";
	std::cin >> c;

	std::cout << std::endl << "Introduceti statsul: RAM sau SWAP: ";
	std::cin >> status;
	bool rez = service.find(Aplicatie(nume, c, status));
	if (rez) {
		std::cout << " Aplicatia a fost gasita ! " << std::endl;
	}
	else {
		std::cout << " Aplicatia nu a fost gasita " << std::endl;
	}
	delete[] nume;
	delete[] status;

}

void UserInterface::update(){
	char* nume = new char[10];
	int c = 0;
	char* status = new char[5];
	std::cout << std::endl << "Introduceti numele: ";
	std::cin >> nume;

	std::cout << std::endl << "Introduceti consumul memoriei ( > 0 ) in KB: ";
	std::cin >> c;

	std::cout << std::endl << "Introduceti statsul: RAM sau SWAP: ";
	std::cin >> status;
	Aplicatie a(nume, c, status);
	bool rez = service.find(a);
	if (rez) {
		char* numeNou = new char[10];
		int cNou = 0;
		char* statusNou = new char[5];
		std::cout << std::endl << "Introduceti numele nou: ";
		std::cin >> numeNou;

		std::cout << std::endl << "Introduceti consumul memoriei nou ( > 0 ) in KB: ";
		std::cin >> cNou;

		std::cout << std::endl << "Introduceti statsul nou: RAM sau SWAP: ";
		std::cin >> statusNou;
		if (service.update(a, numeNou, cNou, statusNou)) {
			std::cout << " Update cu succes ! " << std::endl;
		}
		else {
			std::cout << " Update-ul nu s-a facut !" << std::endl;
		}
	}
	else {
		std::cout << " Aplicatia nu a fost gasita ! " << std::endl;
	}

}

void UserInterface::showAll(){
	std::map<int, Aplicatie>::iterator itr;
	std::map<int, Aplicatie> all = service.getAll();
	for (itr = all.begin(); itr != all.end(); itr++) {
		std::cout << itr->first << "\t" << itr->second << std::endl;
	}
}

UserInterface::UserInterface(){
}

UserInterface::UserInterface(const Service& s)
{
}

UserInterface::~UserInterface(){
}

void UserInterface::showUI(){
	bool gata = false;
	while (!gata) {
		std::cout << std::endl;
		std::cout << "OPTIUNI: " << std::endl;
		std::cout << "	1. Adauga " << std::endl;
		std::cout << "	2. Cauta " << std::endl;
		std::cout << "	3. Sterge " << std::endl;
		std::cout << "	4. Afiseaza " << std::endl;
		std::cout << "	5. Actualizare " << std::endl;
		std::cout << "	0. EXIT!" << std::endl;
		std::cout << "Introduceti optiunea (prin numarul ei): " << std::endl;
		int opt;
		std::cin >> opt;
		switch (opt) {
		case 1: {add(); break; }
		case 2: {find(); break; }
		case 3: {del(); break; }
		case 4: {showAll(); break; }
		case 5: {update(); break; }
		case 0: {gata = true; std::cout << "LA REVEDERE!" << std::endl; break; }
		default: {std::cout << "OPTIUNEA NU EXISTA! VA RUGAM SELECTATI UNA DIN OPTIUNILE EXISTENTE:" << std::endl; }
		}
	}

}
