#include "RepositoryMap.h"
#include "Aplicatie.h"
RepositoryMap::RepositoryMap(){
	this->storage = {};
	this-> ID = 1;
}

RepositoryMap::RepositoryMap(const RepositoryMap& repo) {
	this->storage = repo.storage;
	this->ID = repo.ID;
}

RepositoryMap::~RepositoryMap(){
}

void RepositoryMap::add(const Aplicatie& a){
	//storage.insert(std::pair<int,  Aplicatie>(ID++, Aplicatie("zubii", 1, "aa")));
	storage[ID++] = a;
	//storage.insert(std::pair<int, Aplicatie>(ID, a));
}

bool RepositoryMap::remove(const Aplicatie& a){
	std::map<int, Aplicatie>::iterator itr;

	for (itr = storage.begin(); itr != storage.end(); itr++) {
		if(storage.find(itr->first)->second == a){
			storage.erase(itr->first);
			return true;
		}
	}
	return false;
}

bool RepositoryMap::find(const Aplicatie& a){
	std::map<int, Aplicatie>::iterator itr;
	for (itr = storage.begin(); itr != storage.end(); itr++) {
		if (storage.find(itr->first)->second == a) {
			return true;
		}
	}
	return false;
}

int RepositoryMap::size(){
	return storage.size();
}

bool RepositoryMap::update(const Aplicatie& a, const char* n, int c, const char* s){
	std::map<int, Aplicatie>::iterator itr;
	for (itr = storage.begin(); itr != storage.end(); itr++) {
		if (storage.find(itr->first)->second == a) {
			itr->second.setNume(n);
			itr->second.setConsumMemorieKb(c);
			itr->second.setStatus(s);
			return true;
		}
	}
	return false;
}

//DE CE NU MERGE return storage;
std::map<int, Aplicatie> RepositoryMap::getAll(){
	std::map<int, Aplicatie> _storage;
	std::map<int, Aplicatie>::iterator itr;
	for (itr = storage.begin(); itr != storage.end(); itr++) {
		_storage[itr->first] =  itr->second;
	}
	return _storage;
}
