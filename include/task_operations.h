#include<string>
#include<iostream>
#include<vector>
#include "task.h"
#include "menu.h"

#pragma once

void addTask(std::vector<Task>& tasks);
void editTask(std::vector<Task>& tasks, int selection);
void deleteTask(std::vector<Task>& tasks, int selection);
void changeStatus(std::vector<Task>& tasks);

