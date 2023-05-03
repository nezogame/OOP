#include "Memento.h"

Memento::Memento() {

}

Memento::~Memento() {
	for (int i = 0; i < figures.size(); i++) {
		figures.pop_back();
	}
	for (int i = 0; i < composites.size(); i++) {
		composites.pop_back();
	}


}
void Memento::clean_figures() {
	for (int i = 0; i < figures.size(); i++) {
		figures.pop_back();
	}
}
void  Memento::clean_composites() {
	for (int i = 0; i < composites.size(); i++) {
		composites.pop_back();
	}
}