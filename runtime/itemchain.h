//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_ITEMCHAIN_H
#define ILLATE_ITEMCHAIN_H

#include "item.h"

class ItemChain : public Items::Item{
public:
    ItemChain();
    Items::ItemType type();
    std::string to_string_native();
private:
};

#endif //ILLATE_ITEMCHAIN_H
