#pragma once
#include "pch.h"

class Wizard{
    private: 
        uint16_t id; // Limite de 0-255
        
    public:
        std::string name;
        std::string last_name;
        std::string gender;
        uint32_t    age;
        uint16_t    id_father;
        uint16_t    is_dead : 1;
        std::string type_magic;
        uint16_t    is_owner : 1;

        inline auto getId();
        void showInfo();

        Wizard(uint8_t id);
        ~Wizard();
};