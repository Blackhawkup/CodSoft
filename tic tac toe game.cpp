#include <iostream>
#include <vector>
using namespace std;

struct Task {
    string description;
    bool is_completed;
};

vector<Task> tasks;

void add_task() {
    Task new_task;
    cout << "Enter task description: ";
    cin.ignore();  // To clear the input buffer
    getline(cin, new_task.description);
    new_task.is_completed = false;
    tasks.push_back(new_task);
    cout << "Task added successfully.\n";
}

void view_tasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].is_completed ? "Completed" : "Pending") << "]\n";
    }
}

void mark_task_completed() {
    int task_number;
    cout << "Enter task number to mark as completed: ";
    cin >> task_number;

    if (task_number <= 0 || task_number > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks[task_number - 1].is_completed = true;
        cout << "Task marked as completed.\n";
    }
}

void remove_task() {
    int task_number;
    cout << "Enter task number to remove: ";
    cin >> task_number;

    if (task_number <= 0 || task_number > tasks.size()) {
        cout << "Invalid task number.\n";
    } else {
        tasks.erase(tasks.begin() + task_number - 1);
        cout << "Task removed.\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                add_task();
                break;
            case 2:
                view_tasks();
                break;
            case 3:
                mark_task_completed();
                break;
            case 4:
                remove_task();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid option, try again.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
