//
// Created by james on 29/12/2019.
//

#include "istring.h"

ItemType Istring::type(){
    return ItemType::STRING;
}

Istring::Istring(std::string val) : val(val){

}

std::string Istring::to_string_native(){
    return this->val;
}