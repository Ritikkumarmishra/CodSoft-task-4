#include <iostream>
#include <vector>

// Function to display the To-Do List
void displayTodoList(const std::vector<std::string>& todoList) {
    if (todoList.empty()) {
        std::cout << "The To-Do List is empty." << std::endl;
    } else {
        std::cout << "To-Do List:" << std::endl;
        for (size_t i = 0; i < todoList.size(); ++i) {
            std::cout << i + 1 << ". " << todoList[i] << std::endl;
        }
    }
}

int main() {
    std::vector<std::string> todoList;
    int choice;
    std::string task;

    do {
        std::cout << "To-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Delete Task" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cin.ignore(); // Ignore the newline character from previous input
                std::cout << "Enter the task to add: ";
                std::getline(std::cin, task);
                todoList.push_back(task);
                std::cout << "Task added to the list." << std::endl;
                break;
            case 2:
                displayTodoList(todoList);
                break;
            case 3:
                displayTodoList(todoList);
                if (!todoList.empty()) {
                    std::cout << "Enter the number of the task to delete: ";
                    int index;
                    std::cin >> index;
                    if (index > 0 && index <= static_cast<int>(todoList.size())) {
                        todoList.erase(todoList.begin() + index - 1);
                        std::cout << "Task deleted from the list." << std::endl;
                    } else {
                        std::cout << "Invalid task number." << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << "Exiting the program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    } while (choice != 4);

    return 0;
}