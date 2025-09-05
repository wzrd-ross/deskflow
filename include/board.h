#pragma once
#include "task.h"
#include<vector>

class Board {
public:
    void addTask(const Task& t);
    void deleteTask(size_t index);
    Task& getTask(size_t index);
    const std::vector<Task>& getTasks() const;

private:
    std::vector<Task> tasks;
};