#include "FiguresHistory.h"
#include "Controller.h"


FiguresHistory::FiguresHistory() {
    memento = Memento();
}

void FiguresHistory::save_state( Controller& controller) {
    controller.set_memento();
    cout << "Saved" << endl;
}
void FiguresHistory::load_state(Controller& controller) {
    controller.get_memento();
    cout << "Loaded" << endl;
}