//
// Created by james-laptop on 26/12/2019.
//

#ifndef ILLATE_ISTRING_H
#define ILLATE_ISTRING_H

#include "item.h"

namespace items{
    class Istring : public items::Item{
    public:
        Istring(std::string val);
        items::ItemType type();
        std::string to_string_native();

        static std::shared_ptr<Istring> to_item(std::string val){
            return std::make_shared<Istring>(val);
        }
    private:
        const std::string val;
    };
};

#endif //ILLATE_ISTRING_H
