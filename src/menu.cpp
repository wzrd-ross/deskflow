#include<iostream>
#include<vector>
#include<string>
#include "menu.h"
#include "board.h"
#include "task_operations.h"

void printTaskPreview(std::vector<Task>& tasks)
{
    std::cout << "\nAll Tasks:\n";
    for (size_t i=0; i < tasks.size(); i++){
        std::cout << i << ". " << tasks[i].title
                  << " (" << statusToString(tasks[i].status) << ")\n";
    }
}

void printAllTasks(std::vector<Task>& tasks)
{
    std::cout << "\nAll Tasks(details):\n";
    for (size_t i=0; i < tasks.size(); i++){
        std::cout << i << ". " << tasks[i].title
                  << " (" << statusToString(tasks[i].status) << ")\n";
    };
}

void editTaskSubMenu(std::vector<Task>& tasks) 
{
    printAllTasks(tasks);
    int selection {};

    std::cout << "Select task:\n";
    std::cin >> selection;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    
    if (selection >= 0 && selection < tasks.size()) {
            editTask(tasks, selection);
    }

}

void specificTaskSubMenu(std::vector<Task>& tasks)
{
    int selection {};

    std::cout << "\nActions:\n";
    std::cout << "1. Change Status\n";
    std::cout << "2. Edit task\n";
    std::cout << "3. Delete Task\n";
    std::cin >> selection;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 


        switch (selection) {
            case 1: changeStatus(tasks); break;
            case 2: editTask(tasks, selection); break;
            case 3: deleteTask(tasks, selection); break;
        }

}

void printSpecificTask(std::vector<Task>& tasks)
{

    int selection {};

    std::cout << "Select Task To View:\n";
    std::cin >> selection;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (selection >= 0 && selection < tasks.size()) {
    std::cout << tasks[selection].title << " - "
              << tasks[selection].description;
    } else {
        std::cout << "Invalid Input \n";
    }

    specificTaskSubMenu(tasks);

}

void menuMain(std::vector<Task>& tasks)
{
 bool mainMenu = true;

 while (mainMenu) {
    printAllTasks(tasks);
    
    int selection {};
    
    std::cout << "----------\n";
   
    std::cout << "1. View Task\n";
    std::cout << "2. Create new task\n";
    std::cout << "3. Edit task\n";
    std::cout << "0. Exit\n";
    std::cin >> selection;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    switch (selection) {
        case 1: printSpecificTask(tasks); break;
        case 2: addTask(tasks); break;
        case 3: editTaskSubMenu(tasks); break;
        case 0: return;
    }

 };

}