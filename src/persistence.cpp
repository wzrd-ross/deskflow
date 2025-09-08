#include "task.h"
#include "persistence.h"
#include <fstream>
#include <sstream>
#include <iostream>

void saveTasks(const std::vector<Task>& tasks, const std::string& filename)
{
    std::ofstream out(filename);
    if (!out) {
        std::cerr << "Error could not open " << filename << "for writing\n";
        return;
    }
    for (const auto& task : tasks) {
        out << static_cast<int>(task.status) << "|"
            << task.title << "|"
            << task.description << "\n";
    }
}

std::vector<Task> loadTasks(const std::string& filename) {
    std::vector<Task> tasks;
    std::ifstream inFile(filename);

    std::string line;

    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        Task task;
        std::string statusStr;
        std::string title;
        std::string description;

        if (std::getline(iss, statusStr, '|') &&
            std::getline(iss, title, '|') &&
            std::getline(iss, description)) {

                task.status = static_cast<Status>(std::stoi(statusStr));
                task.title = title;
                task.description = description;
            
        
        tasks.push_back(task);
            }
    }
    return tasks;
}