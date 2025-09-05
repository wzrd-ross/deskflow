#include<string>
#include<vector>
#pragma once

enum class Status {ToDo, InProgress, Done};

std::string statusToString(Status status);

struct Task
{
    std::string title;
    std::string description;
    Status status;
};

