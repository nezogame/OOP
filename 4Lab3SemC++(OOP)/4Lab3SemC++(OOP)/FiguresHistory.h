#pragma once
#include "Memento.h"
class FiguresHistory //Caretaker 
{
private:
    Memento memento;
public:
    FiguresHistory();
    void save_state( Controller&);
    void load_state(Controller&);
};