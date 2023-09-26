#include<bits/stdc++.h>
using namespace std;

struct task {
    string name;
    bool done;
    task(string name, bool done= false){
        this->name=name ;
        this->done=done;
    }
};

class TODO_LIST {
private:
    vector<task>tasks;
public:
    TODO_LIST(){}

    void AddTask (string taskname){
        tasks.push_back(taskname);
    }

    void ViewTasks(){
        if (tasks.empty()){
            cout <<"there is no tasks in your to do list :)\n";
        }
        else{
            for (int i = 0; i < tasks.size(); ++i) {
                cout<< i+1<<" - ";
                if (tasks[i].done== true){
                    cout << "[X] " ;
                }
                if (tasks[i].done== false){
                    cout <<"[ ] ";
                }
                cout << tasks[i].name<<"\n";
            }
        }
    }
    void RemoveTask(int taskNumber){
        if (tasks.empty()){
            cout << "your To do list is already EMPTY :) \n";
        }
        else if (taskNumber<1 && taskNumber>tasks.size() ) {
            cout << "INVALID INDEX\n";
        }
        else {
            tasks.erase(tasks.begin()+taskNumber-1);
            cout <<"task "<< taskNumber <<" removed \n";
        }

    }

    void MarkTAskasCompleted(int taskNumber){
        if (tasks.empty()){
            cout << "your to do list is already EMPTY :) \n";
        }
        else if( (taskNumber<1 && taskNumber>tasks.size()) || tasks.empty() ){
            cout << "INVALID INDEX \n";
        }
        else{
            if (tasks[taskNumber-1].done== false){
                cout << "task "<< taskNumber<<" Marked as Completed.\n";
                tasks[taskNumber-1].done = true;
            }
            else {
                cout << "your task is already completed :) \n";
            }
        }
    }
};

int main() {
    TODO_LIST todoList;
    int choice ;
    while (true){
        cout << "\nenter your choice\n"
                "1. Add Task\n"
                "2. View Tasks\n"
                "3. Mark Task as Completed\n"
                "4. Remove Task\n"
                "5. Quit\n";
        cin >> choice;
        switch (choice) {
            case 1 :{
                string taskName ;
                cout <<"enter your new task name :\n";
                cin >> taskName;
                todoList.AddTask(taskName);
                break;
            }
            case 2:{
                todoList.ViewTasks();
                break;
            }
            case 3:{
                int taskIndex ;
                cout <<"enter task index to mark it :\n";
                cin >> taskIndex;
                todoList.MarkTAskasCompleted(taskIndex);
                break;
            }
            case 4:{
                int taskIndex ;
                cout <<"enter task index to remove it :\n";
                cin >> taskIndex;
                todoList.RemoveTask(taskIndex);
                break;
            }
            case 5:{
                cout <<"Goodbye!"<<"\n";
                return 0;
                break;
            }
            default:{
                cout <<"INVALID CHOICE , try again:) \n";
                break;
            }
        }

    }
    return 0;
}
