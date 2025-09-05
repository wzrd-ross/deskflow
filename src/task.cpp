#include<string>
#include<vector>
#include<iostream>
#include "task.h"




std::string statusToString(Status status) {
    switch (status) {
        case Status::ToDo: return "To Do";
        case Status::InProgress: return "In Progress";
        case Status::Done: return "Done";
        default: return "Unknown";
    }
}

