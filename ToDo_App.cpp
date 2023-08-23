#include<iostream>
#include<string>
#include<list>
#include<ctime>
#include<cstdlib>

class ToDo {
    private:
    int id;
    std::string description;
    bool completed;
    public:
    ToDo() : id(0), description(""), completed(false) {}
    ~ToDo() = default;
    bool create(std::string new_description) {
        id = rand() % 100 +1;
        description = new_description;
        return true;
    }

    int getId() {return id;}
    std::string getDescription() {return description;}
    bool isCompleted() {return completed;}
    void setCompleted(bool val ) {completed = val; }
};

int main() {

    char input_option;
    int input_id;
    std::string input_description;
    std::string version ="v0.2.0";
    std::list<ToDo> todoitem;
    std::list<ToDo>::iterator it;

    srand(time(NULL));

    todoitem.clear();

    /*ToDo test;
    test.create("this is a test");
    todoitem.push_back(test);*/
    
    while(1) {
        system("cls");
         std::cout<<"Todo list Maker - "<<version<< std::endl; 
        std::cout<<std::endl << std::endl;  
        for (it = todoitem.begin(); it != todoitem.end(); it++) {

            std:: string completed = it->isCompleted() ? "done" : " not done";

            std::cout<<it->getId()<<" | "<<it->getDescription()<<" | "
            <<completed<<std::endl;
        }

        if(todoitem.empty()) {
            std::cout<< "add something to do!! " <<std::endl;
        }
        std::cout<< std::endl << std::endl;

        std::cout<< "[a]dd a new Todo" <<std::endl;
        std::cout<< "[c]omplete a Todo" <<std::endl;
        std::cout<< "[q]uit" <<std::endl;

        std::cout<<"choice : ";

        std::cin>>input_option;
    if(input_option == 'q') {
        std::cout<< "have a goood day!! " <<std::endl;
        break;
        }
    else if(input_option == 'a') {
        std::cout<<"Add a New Description : ";
        std::cin.clear();
        std::cin.ignore();
        std::getline(std::cin, input_description);

        ToDo newItem;
        newItem.create(input_description);
        todoitem.push_back(newItem);
    }

    else if(input_option == 'c') {
        std::cout<<"Enter Id to Mark Completed : ";
        std::cin>>input_id;
        for (it = todoitem.begin(); it != todoitem.end(); it++) {

            if(input_id == it->getId()) {
                it->setCompleted(true);
                break;
            }
        }
    }
    

    }
 return 0;
}
