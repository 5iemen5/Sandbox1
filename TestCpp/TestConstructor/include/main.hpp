#pragma once

#include <cstdint>
#include <string>

class Body
{
private:
    uint32_t            width;
    uint32_t            height;
    uint32_t            length;
    uint32_t            weight;
    std::string         name;
    volatile uint32_t * addr;
    

public:
    virtual void printBodyParams(void);
    virtual void Init(void);

    //Constructor
    //==========================
    Body(void);
    Body(uint32_t x, uint32_t y, uint32_t z);
    Body(std::string _name, uint32_t x, uint32_t y, uint32_t z);
    //==========================

    //Destructor
    ~Body();

    //Copy constructor. Call by `Body myBody(origBody)`
    Body (const Body & other);

    //Copy assignment oprerator. Call by `myBody = origBody`
    Body & operator = (const Body & other);

    //==========================

    //Move constructor

    //Move assignment constructor
};


// Add declarations here
