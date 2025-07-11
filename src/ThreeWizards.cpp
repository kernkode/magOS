#include "pch.h"

Wizard* ThreeWizards::searchNode(Wizard* node, int id){
    if(node == nullptr) return nullptr;
    if(node->getId() == id) return node;

    Wizard *find = searchNode(node->node->prev, id);
    if(find != nullptr) return find;

    return searchNode(node->node->next, id);
}

void ThreeWizards::showAllInfo(Wizard* mago){
    if(mago == this->root){
        std::cout << "HECTOR EL FATHER\n";
        this->root->showInfo();
    }
    
    
    if(mago->node->prev != nullptr){
        mago->node->prev->showInfo();
    }
    if(mago->node->next != nullptr){
        mago->node->next->showInfo();
    }

    if(mago->node->prev){
        this->showAllInfo(mago->node->prev);
    }

    if(mago->node->next){
        this->showAllInfo(mago->node->next);
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

        std::getline(parse, mago->name, ','); //Nombre
        std::getline(parse, mago->last_name, ','); //Apellido
        std::getline(parse, mago->gender, ','); //Genero

        std::getline(parse, param, ',');
        mago->age = std::stoi(param); //Edad

        std::getline(parse, param, ',');
        mago->id_father = std::stoi(param); //ID Padre

        std::getline(parse, param, ',');
        mago->is_dead = std::stoi(param); //Muerto?

        std::getline(parse, mago->type_magic, ','); //Magia

        std::getline(parse, param, ',');
        mago->is_owner = std::stoi(param); //Dueño?

        //mago->showInfo();

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
    for(auto const [id, wizard] : Mapgos) {
        for(auto const [id_node, child] : Mapgos) {
            if(wizard->getId() == child->id_father) {
                
                if(!wizard->node->prev) {
                    wizard->node->prev = child;
                    #if DEBUG_MODE
                        std::printf("(%d) ID Padre: %d | Name: %s (PREV)\n", child->getId(), child->id_father, child->name.c_str());
                    #endif
                }
                else if(!wizard->node->next) {
                    wizard->node->next = child;
                    #if DEBUG_MODE
                        std::printf("(%d) ID Padre: %d | Name: %s (NEXT)\n", child->getId(), child->id_father, child->name.c_str());
                    #endif
                }
            }
        }

        //Ordenar
        if(wizard->node->next && wizard->node->prev && wizard->node->prev->getId() > wizard->node->next->getId()) {

            //Si el id del prev es mayor al id del next entonces se intercambian
            std::swap(wizard->node->prev, wizard->node->next);
        }
    }
    return true;
}