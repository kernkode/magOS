#pragma once

class Command {
    public:
        static std::map<std::string, std::function<void()>> commands;
        static bool find(std::string name);
        static bool add(std::string name, std::function<void()> func);
};