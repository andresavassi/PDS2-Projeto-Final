#include "Passagem.hpp"

Passagem::Passagem() { 
	this->id = 0;
	this->price = 0.f;
	Location nowhere;
	nowhere.city = " ";
	nowhere.state = " ";
	nowhere.country = " ";
	this->landingLocation = nowhere;
	this->takeOffLocation = nowhere;
}

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
