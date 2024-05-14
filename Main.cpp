#include <iostream>
#include "Sistema.hpp"

int main() {
	Sistema sistema;
	sistema.loadStoreFromFile("ProductList.txt");
	sistema.showProductList(TICKETS);
	return 0;
}
