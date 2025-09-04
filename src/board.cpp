#include"board.h"
#include "task.h"
#include<vector>
#include<string>

void board::addTask(const Task& newTask) {
    tasks.push_back(newTask);
}

void board::deleteTask(size_t index) {
    if (index < tasks.size()) { 
        tasks.erase(tasks.begin() + index);
    }
}

Task& board::getTask(size_t index) {
    return tasks.at(index);
}

const std::vector<Task>& board::getTasks() const {
    return tasks;
}