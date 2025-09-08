#include<iostream>
#include<vector>
#include "menu.h"
#include "task.h"
#include "persistence.h"



int main()
{  
    auto tasks = loadTasks("tasks.csv");


    menuMain(tasks);
    
    saveTasks(tasks, "tasks.csv");
    
    return 0;
}