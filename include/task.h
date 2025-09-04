#include<string>
#pragma once

enum class Status {ToDo, InProgress, Done};

std::string statusToString();

struct Task
{
    std::string title;
    std::string description;
    Status status;
};

