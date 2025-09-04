#pragma once
#include "task.h"
#include<vector>

class board {
public:
    void addTask(const Task& task);
    void deleteTask(size_t index);
    task& getTask(size_t index);
    const std::vector<task>& getTasks() const;

private:
    std::vector<Task> tasks;
};