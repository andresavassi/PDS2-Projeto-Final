#include "Hotel.hpp"

Hotel::Hotel() { 
	this->id = 0;
	this->price = 0.f;
	Location nowhere;
	nowhere.city = " ";
	nowhere.state = " ";
	nowhere.country = " ";
	this->location = nowhere;
}

Hotel::Hotel(int id, float price, Location location) {
	this->id = id;
	this->price = price;
	this->location = location;
}

Location Hotel::getLocation() {
	return this->location;
}
