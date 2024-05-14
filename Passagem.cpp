#include "Passagem.hpp"

Passagem::Passagem(int id, float price, Location takeOffLocation, Location landingLocation) {
	this->id = id;
	this->price = price;
	this->takeOffLocation = takeOffLocation;
	this->landingLocation = landingLocation;
}

Location Passagem::getTakeOffLocation() {
	return this->takeOffLocation;
}

Location Passagem::getLandingLocation() {
	return this->landingLocation;
}
