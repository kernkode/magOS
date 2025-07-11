#include "pch.h"

Wizard* ThreeWizards::searchNode(Wizard* node, int id){
    if(!node) return nullptr;
    if(node->getId() == id) return node;

    if(node->getId() < id){
        Wizard *find = searchNode(node->node->prev, id);

        if(find) {
            #ifdef DEBUG_MODE
                std::cout << "prev: " << node->getId() << " id: " << id << std::endl;
            #endif
            return find;
        }
    }
    #ifdef DEBUG_MODE
        std::cout << "next: " << node->getId() << " id: " << id << std::endl;
    #endif
    return searchNode(node->node->next, id);
}

void ThreeWizards::showAllInfo(Wizard* mago){
    if(mago == this->root){
        std::cout << "HECTOR EL FATHER\n";
        this->root->showInfo();
    }
    
    if(mago->node->prev){
        mago->node->prev->showInfo();
    }
    if(mago->node->next){
        mago->node->next->showInfo();
    }

    if(mago->node->prev) this->showAllInfo(mago->node->prev);
    if(mago->node->next) this->showAllInfo(mago->node->next);
}

//Recursividad de mierda, la odio...
void ThreeWizards::addNode(Wizard* wizard, Wizard* child){
    if(wizard->getId() < child->getId()){
        if(!wizard->node->prev) 
            wizard->node->prev = child;
        else addNode(wizard->node->prev, child);
    } else {
        if(!wizard->node->next) 
            wizard->node->next = child;
        else addNode(wizard->node->next, child);
    }
}

bool ThreeWizards::loadCsv(const std::string path){
    std::ifstream file(path);
    if(!file.is_open()) return false;

    std::string line;
    std::getline(file, line); //omite la primera linea del csv nigga

    std::map<uint16_t, Wizard*> Mapgos;
    while(std::getline(file, line)){
        std::stringstream   parse(line);
        std::string         param;

        std::getline(parse, param, ',');
        Wizard* mago = new Wizard(std::stoi(param));

        std::getline(parse, mago->name,         ','); //name
        std::getline(parse, mago->last_name,    ','); //last_name
        std::getline(parse, mago->gender,       ','); //gender

        std::getline(parse, param,              ','); //age
        mago->age = std::stoi(param);

        std::getline(parse, param,              ','); //id_father
        mago->id_father = std::stoi(param);

        std::getline(parse, param,              ','); //is_dead?
        mago->is_dead = std::stoi(param);

        std::getline(parse, mago->type_magic,   ','); //type_magic

        std::getline(parse, param,              ','); //is_owner
        mago->is_owner = std::stoi(param);
        
        //Map para poder ordenar los magos
        Mapgos.insert({ mago->getId(), mago });
    }
    
    //Busca al owner
    auto it = std::find_if(Mapgos.begin(), Mapgos.end(), 
        [](const std::pair<uint16_t, Wizard*>& pair) { 
            return pair.second->is_owner; 
        }
    );
    
    if(it != Mapgos.end()) {
        root = std::move(it->second);
    }else std::printf("No se encontro el al owner\n");

    //Crea el arbol de magos
    for(auto const& [id, wizard] : Mapgos) {
        if(wizard->is_owner) continue;
        std::cout << wizard->getId() << std::endl;
        addNode(root, wizard);
    }

    /*for(auto const [id, wizard] : Mapgos) {
        for(auto const [id_node, child] : Mapgos) {
            if(wizard->getId() == child->id_father) {
                
                if(!wizard->node->prev && wizard->getId() < child->getId()) {
                    wizard->node->prev = child;
                    #ifdef DEBUG_MODE
                        std::printf("(%d) ID Padre: %d | %s %s (PREV)\n", 
                            child->getId(), child->id_father, child->name.c_str(),
                            child->last_name.c_str()
                        );
                    #endif
                }
                else if(!wizard->node->next) {
                    wizard->node->next = child;
                    #ifdef DEBUG_MODE
                        std::printf("(%d) ID Padre: %d | %s %s (NEXT)\n", 
                            child->getId(), child->id_father, child->name.c_str(),
                            child->last_name.c_str()
                        );
                    #endif
                }
            }
        }

        //Ordenar

        /*if(wizard->node->next && wizard->node->prev && wizard->node->prev->getId() > wizard->node->next->getId()) {

            /*
                Si el id del prev es mayor al id del next entonces se intercambian.
                Los ids menores van al lado izquierdo.

                         50
                        /  \
                      30   70
                     / \   / \
                   20  40 60 80
                  /    \      \
                 10    35     90
            
            std::swap(wizard->node->prev, wizard->node->next);
        }
    }*/
    return true;
}