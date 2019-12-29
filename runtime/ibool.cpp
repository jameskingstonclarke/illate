//
// Created by james on 29/12/2019.
//

#include "ibool.h"

Ibool::Ibool(bool val) : val(val) {
}

ItemType Ibool::type(){
    return ItemType::BOOLEAN;
}

std::string Ibool::to_string_native(){
    return (this->val == true) ? std::string("true") : std::string("false");
}