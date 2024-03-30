#include "handler.hpp"

namespace views::login{
    void Append(userver::components::ComponentList& componentList){
        componentList.Append<handler>();
    }
}