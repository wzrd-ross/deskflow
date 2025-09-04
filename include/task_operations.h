#include<string>
#include<iostream>
#include<vector>
#include "task.h"

#pragma once

void addTask(std::vector<task>& tasks);
void editTask(std::vector<task>& tasks, int selection);
void deleteTask(std::vector<task>& tasks, int selection);
void changeStatus(std::vector<task>& tasks);

