#include "Hotel.hpp"

Hotel::Hotel(int id, float price, Location location) {
	this->id = id;
	this->price = price;
	this->location = location;
}

Location Hotel::getLocation() {
	return this->location;
}
