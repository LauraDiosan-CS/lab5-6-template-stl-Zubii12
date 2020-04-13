#include "Aplicatie.h"

Aplicatie::Aplicatie(){
	this->nume = NULL;
	this->consumMemorieKb = 0;
	this->status = NULL;
}

Aplicatie::Aplicatie(const char* nume, int consumMemorieKb, const char* status){
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->consumMemorieKb = consumMemorieKb;
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}

Aplicatie::Aplicatie(const Aplicatie& a){
	if (this->nume) {
		delete[] this->nume;
		this->nume = NULL;
	}
	this->nume = new char[strlen(a.nume) + 1];
	strcpy_s(this->nume, strlen(a.nume) + 1, a.nume);
	this->consumMemorieKb = a.consumMemorieKb;
	if (this->status) {
		delete[] this->status;
		this->status = NULL;
	}
	this->status = new char[strlen(a.status) + 1];
	strcpy_s(this->status, strlen(a.status) + 1, a.status);
}

Aplicatie::~Aplicatie(){
	if (this->nume) {
		delete[] this->nume;
		this->nume = NULL;
	}
	this->consumMemorieKb = 0;
	if (this->status) {
		delete[] this->status;
		this->status = NULL;
	}
}

char* Aplicatie::getNume()
{
	return this->nume;
}

int Aplicatie::getConsumMemorieKb()
{
	return this->consumMemorieKb;
}

char* Aplicatie::getStatus()
{
	return this->status;
}

void Aplicatie::setNume(const char* n){
	if (this->nume) {
		delete[] this->nume;
		this->nume = NULL;
	}
	this->nume = new char[strlen(n) + 1];
	strcpy_s(this->nume, strlen(n) + 1, n);
}

void Aplicatie::setConsumMemorieKb(int c){
	this->consumMemorieKb = c;
}

void Aplicatie::setStatus(const char* s){
	if (this->status) {
		delete[] this->status;
		this->status = NULL;
	}
	this->status = new char[strlen(s) + 1];
	strcpy_s(this->status, strlen(s) + 1, s);
}

Aplicatie& Aplicatie::operator=(const Aplicatie& a){
	if (this == &a) {
		return *this;
	}
	if (this->nume) {
		delete[] this->nume;
		this->nume = NULL;
	}
	this->nume = new char[strlen(a.nume) + 1];
	strcpy_s(this->nume, strlen(a.nume) + 1, a.nume);
	this->consumMemorieKb = a.consumMemorieKb;
	if (this->status) {
		delete[] this->status;
		this->status = NULL;
	}
	this->status = new char[strlen(a.status) + 1];
	strcpy_s(this->status, strlen(a.status) + 1, a.status);
	return *this;
}

bool Aplicatie::operator==(const Aplicatie& a)
{
	return ((strcmp(this->nume, a.nume) == 0) and
		this->consumMemorieKb == a.consumMemorieKb and
		strcmp(this->status, a.status) == 0);
}

std::ostream& operator<<(std::ostream& os, const Aplicatie& a){
	os << a.nume << " " << a.consumMemorieKb << " " << a.status << std::endl;
	return os;
}
