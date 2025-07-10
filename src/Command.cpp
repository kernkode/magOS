#include "pch.h"

std::map<std::string, std::function<void()>> Command::commands;

/**
 * \brief Finds a command by name.
 *
 * \param name The name of the command to find.
 *
 * \return true if the command was found, false otherwise.
 */
bool Command::find(std::string name) {
    return Command::commands.find(name) != Command::commands.end();
}

/**
 * \brief Adds a command to the database.
 *
 * \param name The name of the command.
 * \param func The function to call when the command is invoked.
 *
 * \return true if the command was successfully added, false otherwise.
 */
bool Command::add(std::string name, std::function<void()> func) {
    Command::commands[name] = func;
    return true;
}