#include "pch.h"
#include <fstream>

class Wizard{
    private: 
        uint_fast8_t id; // Limite de 0-255
    public:
        std::string name;
        std::string last_name;
        uint64_t age;
        uint64_t id_father;
        uint8_t is_dead : 1;
        uint8_t type_magic : 2;
        uint8_t is_owner : 1;

        inline uint_fast8_t getId(){
            return this->id;
        }
};

struct Node{
    Wizard* wizard = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    
    Node(Wizard* mago){
        this->wizard = mago;
    }
    ~Node(){

    }
};

class ThreeMagics {
    public:
        Node* root;

    public:
        ThreeMagics() : root(nullptr){}
        ~ThreeMagics(){
            delete this->root;
        }

    public:
        bool loadCsv(const std::string path){
            std::ifstream file(path);
            if(!file.is_open()) return false;
            return true;
        }
};

int main(int argc, char** argv) {
    ThreeMagics school;
    const bool success = school.loadCsv("bin/list.csv");
    if(!success) std::printf("Error al cargar el csv\n");
    
    std::string input;
    std::printf("magOS started\n>> ");

    Cli::addCommand("--help", [](){ 
        std::printf("- [Commands Menu] -\n");
        std::printf("--kill - Kill the OS\n");
        std::printf("--reboot - Reboot the OS\n");
    });

    Cli::addCommand("--alives", [](){ 
        std::printf("magOS is aliveee\n");
    });

    do{
        std::getline(std::cin, input);
        std::cout << std::string(1, '\n');

        if(Cli::find(input)) Cli::commands[input]();
        else std::printf("Command not found\n");

        std::printf(">> ");
    }while(true);
    return 0;
}
