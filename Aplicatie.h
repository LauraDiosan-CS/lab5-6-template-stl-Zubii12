#pragma once
#include <iostream>

class Aplicatie{
private:
	char* nume;
	int consumMemorieKb;
	char* status;
public:
	Aplicatie();
	Aplicatie(const char* nume, int consumMemorieKb, const char* status);
	Aplicatie(const Aplicatie& a);
	~Aplicatie();

	char* getNume();
	int getConsumMemorieKb();
	char* getStatus();

	void setNume(const char* n);
	void setConsumMemorieKb(int c);
	void setStatus(const char* s);

	Aplicatie& operator=(const Aplicatie& a);
	bool operator==(const Aplicatie& a);

	friend std::ostream& operator<<(std::ostream& os, const Aplicatie& a);
};

