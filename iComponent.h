#include <iostream>
#include <string>
#include <vector>

class iComponent{
public:
    virtual void command() const = 0;
    virtual void addElement(iComponent* icmp){};
    virtual void writeAllCommands(std::string suffix) = 0;

    virtual ~iComponent(){};
};

class Leaf : public iComponent{
    std::string cmd;
public:
    Leaf(std::string cmd) : cmd(cmd){};

    virtual ~Leaf(){
        std::cout<<"Delete leaf: "<<cmd<<std::endl;
    }

    virtual void command() const {
        std::cout<<cmd<<std::endl<<std::endl;
    }

    virtual void writeAllCommands(std::string suffix){
        std::cout<<suffix<<cmd<<std::endl;
    }

};

class Composite : public iComponent{
    std::string cmd;
    std::vector<iComponent*> components;
public:
    Composite(std::string cmd) : cmd(cmd){};

    virtual ~Composite(){
        std::cout<<"==============================="<<std::endl;
        std::cout<<"Delete "<<cmd<<std::endl;
        std::cout<<"==============================="<<std::endl;
        while(!components.empty()){
            delete components.back();
            components.pop_back();
        }
        std::cout<<"==============================="<<std::endl;
        std::cout<<"End of delete "<<cmd<<std::endl;
        std::cout<<"==============================="<<std::endl;
    }

    virtual void command() const {
        std::cout<<cmd<<std::endl<<std::endl;
    }

    virtual void addElement(iComponent* icmp){
        if(icmp){
            components.push_back(icmp);
        }
    }

    virtual void writeAllCommands(std::string suffix){
        std::cout<<suffix<<"==============================="<<std::endl;
        std::cout<<suffix<<cmd<<std::endl;
        std::cout<<suffix<<"==============================="<<std::endl;
        suffix += "t";
        for(std::vector<iComponent*>::iterator icomponent = components.begin(); icomponent < components.end(); icomponent++){
            (*icomponent)->writeAllCommands(suffix);
        }
    }
};

int main(){

    iComponent* menu = new Composite("Menu");

    iComponent* file = new Composite("File");
    file->addElement(new Leaf("Open"));
    file->addElement(new Leaf("Save"));

    menu->addElement(file);

    iComponent* edit = new Composite("Edit");
    
    edit->addElement(new Leaf("Copy"));
    edit->addElement(new Leaf("Paste"));
    edit->addElement(new Leaf("Duplicate"));

    menu->addElement(edit);

    menu->writeAllCommands("");

    if(menu){
        delete menu;
        menu = NULL;
    }

    std::cin.get();
    return 0;
}