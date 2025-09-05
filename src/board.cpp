#include"board.h"
#include "task.h"
#include<vector>
#include<string>

void Board::addTask(const Task& t) {
    tasks.push_back(t);
}

void Board::deleteTask(size_t index) {
    if (index < tasks.size()) { 
        tasks.erase(tasks.begin() + index);
    }
}

Task& Board::getTask(size_t index) {
    return tasks.at(index);
}

const std::vector<Task>& Board::getTasks() const {
    return tasks;
}