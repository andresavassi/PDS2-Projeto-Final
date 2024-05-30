#include "Hotel.hpp"

Hotel::Hotel() { 
	this->id = 0;
	this->price = 0.f;
	Location nowhere;
	nowhere.city = " ";
	nowhere.state = " ";
	nowhere.country = " ";
	this->location = nowhere;
	this->qntd = 1;
}

Hotel::Hotel(int id, float price, Location location, int qntd) {
	this->id = id;
	this->price = price;
	this->location = location;
	this->qntd = qntd;
}

Location Hotel::getLocation() {
	return this->location;
}

int Hotel::getQntd() {
	return this->qntd;
}

void Hotel::setQntd(int qntd) {
	this->qntd = qntd;
}

