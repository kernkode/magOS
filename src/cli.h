#pragma once

class Cli {
    public:
        static std::map<std::string, std::function<void()>> commands;
        static bool find(std::string name);
        static bool addCommand(std::string name, std::function<void()> func);
};