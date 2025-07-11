#include "pch.h"

int main(int argc, char** argv) {
    std::string input;
    std::printf("magOS v1.0\n");
    std::printf("--help for help\n");

    ThreeWizards school;
    const bool success = school.loadCsv("list.csv");
    std::printf(success ? "\nCSV cargado\n" : "Error al cargar el csv\n");

    Cli::addCommand("--help", [](std::vector<std::string> args){ 
        std::printf("Menu de ayuda\n");
        std::printf("--search <id> - Busca un mago especifico\n");
        std::printf("--showall - Muestra todos\n");
        std::printf("--showallalive - Muestra todos los vivos\n");
        std::printf("--showalldead - Muestra todos los muertos\n");
        std::printf("--owner - Muestra al owner\n");
        return 0;
    });

    Cli::addCommand("--search", [&](std::vector<std::string> args){
        if(args.size() < 2 || args.size() > 2) {
            std::printf("--search <id>\n");
            return 0;
        }
        //school.showInfo(school.root);
        auto node = school.searchNode(school.root, std::stoi(args[1]));
        if(!node) return std::printf("Mago no encontrado.\n");
        node->showInfo();
        return 0;
    });

    Cli::addCommand("--showallalive", [&](std::vector<std::string> args){
        if(args.size() != 1) {
            std::printf("--showallalive\n");
            return 0;
        }
        
        school.showAllInfo(school.root, ThreeWizards::e_info_flags::SHOW_ALIVE);
        return 0;
    });

    Cli::addCommand("--showalldead", [&](std::vector<std::string> args){
        if(args.size() != 1) {
            std::printf("--showdead\n");
            return 0;
        }
        
        school.showAllInfo(school.root, ThreeWizards::e_info_flags::SHOW_DEAD);
        return 0;
    });

    Cli::addCommand("--owner", [&](std::vector<std::string> args){
        if(args.size() != 1) {
            std::printf("--owner\n");
            return 0;
        }
        
        school.showAllInfo(school.root, ThreeWizards::e_info_flags::SHOW_OWNER);
        return 0;
    });

    Cli::addCommand("--showall", [&](std::vector<std::string> args){
        if(args.size() != 1) {
            std::printf("--showall\n");
            return 0;
        }
        
        school.showAllInfo(school.root, 
            ThreeWizards::e_info_flags::SHOW_ALIVE | 
            ThreeWizards::e_info_flags::SHOW_DEAD | 
            ThreeWizards::e_info_flags::SHOW_OWNER
        );
        return 0;
    });

    std::printf(">> ");
    do{
        std::vector<std::string> args;
        std::getline(std::cin, input);

        std::stringstream   parse(input);
        std::string         param;
        
        while(std::getline(parse, param, ' '))
            args.push_back(param);

        std::cout << std::string(1, '\n');

        if(Cli::find(args[0])) Cli::commands[args[0]](args);
        else std::printf("Command not found\n");

        std::printf("\n>> ");
    }while(true);
    return 0;
}
