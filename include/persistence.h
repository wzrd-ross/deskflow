#pragma once
#include<string>
#include<vector>
#include "task.h"

void saveTasks(const std::vector<Task>& tasks, const std::string& filename);
std::vector<Task> loadTasks(const std::string& filename);