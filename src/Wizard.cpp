#include "pch.h"

Wizard::Wizard(uint8_t id) : id(id){
    this->node = new Node();
}
Wizard::~Wizard(){
    std::cout << "Mago de mrd borrado :)" << std::endl;
    delete this->node;
}

void Wizard::showInfo(){
    std::cout << std::string(1, '\n');
    std::cout << this->name << " " << this->last_name << std::endl;
    std::cout << "---------------------------------" << std::endl;
    std::cout << "ID: " << this->id << std::endl;
    std::cout << "Gender: " << this->gender << std::endl;
    std::cout << "Age: " << this->age << std::endl;
    std::cout << "ID Father: " << this->id_father << std::endl;
    std::cout << "Is dead: " << this->is_dead << std::endl;
    std::cout << "Type magic: " << this->type_magic << std::endl;
    std::cout << "Is owner: " << this->is_owner << std::endl;
}