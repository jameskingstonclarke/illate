//
// Created by james on 29/12/2019.
//

#include "nill.h"

items::Inill::Inill(){

}

items::ItemType items::Inill::type(){
    return items::ItemType::NIL;
}

bool items::Inill::equal(std::shared_ptr<Item> rhs){
    return false;
}
std::string items::Inill::to_string_native(){
    return std::string("nill");
}