#include<iostream>
#include<vector>
#include "task_operations.h"

void deleteTask(std::vector<Task>& tasks, int selection)
{
    if (selection >= 0 && selection < tasks.size()) { 
        tasks.erase(tasks.begin() + selection);
        std::cout << "Task Deleted.\n";
    } else {
        std::cout << "Invalid Task Index.\n";
    }

}

void editTask(std::vector<Task>& tasks, int selection)
{
    bool editing = true;

    while (editing) {
        std::string newTitle {};
        std::string newDescription {};
        
        std::cout << "--Edit Task-- \n";
        std::cout << "Title: ";
        std::getline(std::cin, newTitle);
        std::cout << "\nDescription: ";
        std::getline(std::cin, newDescription);


        tasks[selection].title = newTitle;
        tasks[selection].description = newDescription;

        editing = false;

    };
}

void changeStatus(std::vector<Task>& tasks)
{
    printAllTasks(tasks);
    int selection {};
    int statusChoice {};

    std::cout << "Select Task:";
    std::cin >> statusChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    if (selection >= 0 && selection < tasks.size()) { 
        std::cout << tasks[selection].title << " - "
                  << statusToString(tasks[selection].status) << '\n'
                  << tasks[selection].description << '\n';


        std::cout << "Select New Status:\n";
        std::cout << "1. To Do\n";
        std::cout << "2. In Progress\n";
        std::cout << "3. Done\n";
        std::cout << "4. Delete\n";
        std::cin >> selection;


        switch (selection) {
            case 1: tasks[statusChoice].status = Status::ToDo; break;
            case 2: tasks[statusChoice].status = Status::InProgress; break;
            case 3: tasks[statusChoice].status = Status::Done; break;
            case 4: deleteTask(tasks, statusChoice); break;
        }
    } else {
        std::cout << "Invalid Task Index";  
    }
}

void addTask(std::vector<Task>& tasks) 
{
    std::string title, desc;
    std::cout << "Enter a title for your task.\n";
    std::getline(std::cin, title);
    std::cout << "Enter a description for your task.\n";
    std::getline(std::cin, desc);
    std::cout << "Task added!\n";

    tasks.push_back({title, desc, Status::ToDo});
}