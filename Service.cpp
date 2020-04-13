#include "Service.h"

Service::Service(){
}

Service::Service(const RepositoryMap& repo){
	this->repo = repo;
}

Service::~Service()
{
}

void Service::setRepo(const RepositoryMap& repo) {
	this->repo = repo;
}

void Service::add(const Aplicatie& a){
	repo.add(a);
}

bool Service::del(const Aplicatie& a){
	if (repo.remove(a)) {
		return true;
	}
	return false;
}

bool Service::update(const Aplicatie& a, const char* n, int c, const char* s){
	if (repo.update(a, n, c, s)) {
		return true;
	}
	return false;
}

int Service::size(){
	return repo.size();
}

std::map<int, Aplicatie> Service::getAll(){
	return repo.getAll();
}

bool Service::find(const Aplicatie& a){
	if (repo.find(a)) {
		return true;
	}
	return false;
}
