#include<iostream>
#include<string>
#include<vector>
#include<limits>


struct task
{
    std::string title;
    std::string description;
    int status;
};


int main()
{

bool hasExecuted = false;

    int selection {};
    std::vector<task> tasks;

    while (true) {


            std::cout << "\nAll Tasks:\n";
        for (size_t i=0; i < tasks.size(); i++) {
            std::cout << i << ". " << tasks[i].title
                    << " (" << tasks[i].status << ")\n";
        }

        if (tasks.empty() && hasExecuted == false) {
            std::cout << "No Tasks.\n";
            hasExecuted = true;
        };

        std::cout << "----------\n";

    

    
        std::cout << "1. Select Task Details\n";
        std::cout << "2. Create new task\n";
        std::cout << "0. Exit\n";
        std::cin >> selection;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        switch (selection) {
            case 1:
            {
                if (tasks.empty() && hasExecuted == false) {
                std::cout << "No Tasks.\n";
                hasExecuted = true;
                } else {
                    std::cout << "\nAll Tasks:\n";
                    for (size_t i=0; i < tasks.size(); i++) {
                        std::cout << i << ". " << tasks[i].title << " - "
                                  << tasks[i].description
                                  << " (" << tasks[i].status << ")\n"; 
                    }
                }
                break;
            }
            case 2:
            {
                std::string title, desc;
                std::cout << "Enter a title for your task.\n";
                std::getline(std::cin, title);
                std::cout << "Enter a description for your task.\n";
                std::getline(std::cin, desc);
                std::cout << "Task added!\n";

                tasks.push_back({title, desc, 0});
            }
            case 0:
            {
                std::cout << "Exiting...";
            }
            
        }

    }


    tasks[0].status =1; 

    
    return 0;
}