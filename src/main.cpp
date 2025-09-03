#include<iostream>
#include<string>
#include<vector>
#include<limits>

//Sudo Code for refactor
//func addTask
//func edit task
//func menu
//func print all
//func print specific
//main loop



enum Status {ToDo, InProgress, Done};
struct task
{
    std::string title;
    std::string description;
    Status status;
};

std::string statusToString(Status status) {
    switch (status) {
        case Status::ToDo: return "To Do";
        case Status::InProgress: return "In Progress";
        case Status::Done: return "Done";
        default: return "Unknown";
    }
}

void deleteTask(std::vector<task>& tasks, int selection)
{
    if (selection >= 0 && selection < tasks.size()) { 
        tasks.erase(tasks.begin() + selection);
        std::cout << "Task Deleted.\n";
    } else {
        std::cout << "Invalid Task Index.\n";
    }

}


void printTaskPreview(std::vector<task>& tasks)
{
    std::cout << "\nAll Tasks:\n";
    for (size_t i=0; i < tasks.size(); i++){
        std::cout << i << ". " << tasks[i].title
                  << " (" << statusToString(tasks[i].status) << ")\n";
    }
}

void printAllTasks(std::vector<task>& tasks)
{
    std::cout << "\nAll Tasks(details):\n";
    for (size_t i=0; i < tasks.size(); i++){
        std::cout << i << ". " << tasks[i].title
                  << " (" << statusToString(tasks[i].status) << ")\n";
    };
}

void editTask(std::vector<task>& tasks, int selection)
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

void editTaskSubMenu(std::vector<task>& tasks) 
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

void changeStatus(std::vector<task>& tasks)
{
    printAllTasks(tasks);
    int selection {};
    int statusChoice {};

    std::cout << "Select Task:";
    std::cin >> statusChoice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

    if (selection >= 0 && selection < tasks.size()) { 
        std::cout << tasks[selection].title << " - "
                  << tasks[selection].status << '\n'
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

void addTask(std::vector<task>& tasks) 
{
    std::string title, desc;
    std::cout << "Enter a title for your task.\n";
    std::getline(std::cin, title);
    std::cout << "Enter a description for your task.\n";
    std::getline(std::cin, desc);
    std::cout << "Task added!\n";

    tasks.push_back({title, desc, Status::ToDo});
}

void specificTaskSubMenu(std::vector<task>& tasks)
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

void printSpecificTask(std::vector<task>& tasks)
{

    int selection {};

    std::cout << "Select Task To View:\n";
    std::cin >> selection;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (selection >= 0 && selection < tasks.size()) {
    std::cout << tasks[selection].title << " - "
              << tasks[selection].status << '\n' 
              << tasks[selection].description;
    } else {
        std::cout << "Invalid Input \n";
    }

    specificTaskSubMenu(tasks);

}

void menuMain(std::vector<task>& tasks)
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

int main()
{
    bool running = true;
    std::vector<task> tasks;

    menuMain(tasks);


    std::cout << "Press enter to exit:";
    std::cin.get();
    
    return 0;
}