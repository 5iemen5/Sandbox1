#include "main.hpp"

void Body::Init(void){

}
void Body::printBodyParams(void){
        printf("%s's parameters:\n", name.c_str());
        printf("Width: %d\nHeight: %d\nLength: %d\nWeight: %d\n",
            width, 
            height, 
            length, 
            weight
        );
    }

Body::Body(void) {
        width = 0;
        height = 0;
        length = 0;
        weight = 0;
        name = "UNNAMED";
        addr = new uint32_t;
}
Body::Body(uint32_t x, uint32_t y, uint32_t z)  {
        width = x;
        height = y;
        length = z;
        weight = 0;
        name = "UNNAMED";\
        addr = (volatile uint32_t *)& weight;
}
Body::Body(std::string _name, uint32_t x, uint32_t y, uint32_t z){
        width = x;
        height = y;
        length = z;
        weight = 0;
        name = _name;
        addr = (volatile uint32_t *)& weight;
}

Body::~Body() {
    delete (addr);
}
Body::Body (const Body & other){
        width       = other.width;
        height      = other.height;
        length      = other.length;
        weight      = other.weight;
        name        = other.name;
        addr        = other.addr;
}
Body & Body::operator=(const Body & other){
    if(this == &other){
        return *this;
    }
    //Delete dyn. allocated memory of this original object
    delete this->addr;

    //Allocate new memory for the object
    this->addr = new uint32_t;
    
    //Deep copy
    this->addr = *(other.addr);

    //Return 
}

int main() {
    Body body_1{};
    // Body body_2(1, 1, 1);
    // Body body_3("K1SKA", 1, 1, 1);

    Body body_2{};
    Body body_3{};

    body_1.printBodyParams();
    body_2.printBodyParams();
    body_3.printBodyParams();
    return 0;
}
