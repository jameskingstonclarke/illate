//
// Created by james on 27/12/2019.
//

#ifndef ILLATE_CORE_H
#define ILLATE_CORE_H

#include <vector>
#include <stack>

#include "clr.h"
#include "item.h"
#include "script.h"

#define GET_OP() this->script->code->at(this->ip)
#define NEXT() this->ip++;

class Runtime;

namespace items{

    // To store local variables in a scope, and any locals above the scope
    typedef struct ScopedLocals{
        std::shared_ptr<ScopedLocals> upper;
        std::shared_ptr<items::Icontainer> locals;
    }ScopedLocals;

    /**
     * NOTE: In cores, variables marked as not local will be assigned to the global namespace
     * */
    class Core : public items::Item{
    public:
        // The script that this accesses for code
        std::shared_ptr<Script> script;

        Core(){}
        Core(std::shared_ptr<Script> script) : script(script){}

        items::ItemType type();
        std::string to_string_native();

        std::shared_ptr<items::Item> call();
        // Here arg1 can be a single item or an item chain
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1);
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2);
        std::shared_ptr<items::Item> call(std::shared_ptr<items::Item> arg1, std::shared_ptr<items::Item> arg2, std::shared_ptr<items::Item> arg3);

        void bind_enviroment(std::shared_ptr<items::Icontainer> enviroment);
        void bind_scoped_locals(std::shared_ptr<ScopedLocals> upper);

        void push(std::shared_ptr<items::Item> item);
        std::shared_ptr<items::Item> pop();

    private:
        std::shared_ptr<items::Icontainer> enviroment;
        // Our instruction pointer
        uint32_t ip = 0;
        // The execution stack
        std::stack<std::shared_ptr<items::Item>> exec_stack;
        // Our locals along with upper locals
        std::shared_ptr<ScopedLocals> locals;
        // Run the 'fetch-decode-execute' cycle
        void run_fde();
    };
};

#endif //ILLATE_CORE_H
