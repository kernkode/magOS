#include "pch.h"

int main(int argc, char** argv) {
    std::string input;
    std::printf("magOS started\n");

    ThreeWizards school;
    const bool success = school.loadCsv("list.csv");
    std::printf(success ? "\nCSV cargado\n" : "Error al cargar el csv\n");

    Cli::addCommand("--help", [](){ 
        std::printf("- [Commands Menu] -\n");
        std::printf("--kill - Kill the OS\n");
        std::printf("--reboot - Reboot the OS\n");
    });

    Cli::addCommand("--showall", [&](){ 
        school.showInfo(school.root);
    });

    std::printf(">> ");
    do{
        std::getline(std::cin, input);
        std::cout << std::string(1, '\n');

        if(Cli::find(input)) Cli::commands[input]();
        else std::printf("Command not found\n");

        std::printf(">> ");
    }while(true);
    return 0;
}
