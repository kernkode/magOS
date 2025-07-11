#pragma once
#include "pch.h"

class Wizard;
struct Node{
    Wizard* prev; //Izquierda
    Wizard* next; //Derecha
    
    Node();
    ~Node();
};