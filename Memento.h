    #include <iostream>
    #include <string>
    #include <vector>

    class Memento{
        int state;
    public:
        inline Memento(int value) : state(value){}

        inline int getState() const { return state; }
    };

    class Mementos{
        std::vector<Memento*> mementos;
        int pos;
    public:
        inline Mementos() : pos(-1) {};

        void addMemento(Memento* memento){
            std::cout << "Memento was added!" << std::endl << std::endl;
            if(pos > -1){
                for(std::vector<Memento*>::iterator mem = mementos.begin() + pos + 1; mem < mementos.end(); mem++){
                    delete (*mem);
                }
                mementos.erase(mementos.begin() + pos + 1, mementos.end());
            }
            mementos.push_back(memento);

            pos = mementos.size() - 1;
        }

        Memento* redo(){
            if(pos < (int)(mementos.size() - 1)){
                std::cout << std::endl << "Redo action!" << std::endl;

                pos ++;
                return mementos[pos];
            }
            std::cout << std::endl << "You can not redo my old Yedi friend!" << std::endl << std::endl;
            return NULL;
        }

        Memento* undo(){
            if(pos > 0){
                std::cout << std::endl << "Undo action!" << std::endl;
                pos --;
                if(pos > -1)
                    return mementos[pos];
            }
            std::cout << std::endl << "You can not undo my old Yedi friend!" << std::endl << std::endl;
            return NULL;
        }
    };

    class Value{
        int value;
        Mementos mementos;
        Memento* getMemento() const { return new Memento(value); }
    public:
        Value(int value) : value(value){
            mementos.addMemento(getMemento());
        }

        void add(){
            int v = 0;
            std::cout<<"Write some value to add: ";
            std::cin>>v;

            std::cout << "Value before add " << value << std::endl;

            value += v;

            std::cout << "Value after add " << value << std::endl << std::endl;

            mementos.addMemento(getMemento());
        }

        void subtract(){
            int v = 0;
            std::cout<<"Write some value to subtract: ";
            std::cin>>v;

            std::cout << "Value before subtract " << value << std::endl;

            value -= v;

            std::cout << "Value after subtract " << value << std::endl << std::endl;

            mementos.addMemento(getMemento());
        }

        void redo(){
            Memento* mem = mementos.redo();

            if(mem){
                std::cout << "Value before redo " << value << std::endl;
                value = mem->getState();
                std::cout << "Value after redo " << value << std::endl << std::endl;
            }
        }

        void undo(){
            Memento* mem = mementos.undo();

            if(mem){
                std::cout << "Value before undo " << value << std::endl;
                value = mem->getState();
                std::cout << "Value after undo " << value << std::endl << std::endl;
            }
        }
    };

    int main(){
        Value value(0);
        int decision = 0;
        std::string strDecision;
        do{
            std::cout << "What you want to do?" << std::endl << std::endl;
            std::cout << "Add [0]" << std::endl;
            std::cout << "Subtract [1]" << std::endl;
            std::cout << "Undo [2]" << std::endl;
            std::cout << "Redo [3]" << std::endl;
            std::cout << "Exit [4]" << std::endl;

            std::cin >> strDecision;

            decision = atol(strDecision.c_str());

            switch(decision){
                case 0:
                    value.add();
                    break;
                case 1:
                    value.subtract();
                    break;
                case 2:
                    value.undo();
                    break;
                case 3:
                    value.redo();
                    break;
            }
        }while(decision != 4);

        std::cin.get();
        return 0;
    }
