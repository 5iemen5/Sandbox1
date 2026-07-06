#include "main.hpp"

/*
    The goals:
    1. [x] Class that holds data
    2. [ ] Constructor of it composes a JSON
    3. [ ] Call libMosquitto to publish a message
*/

class messages{
private:

    struct data{

        char const * name       = "";
        char const * comment    = "";
        double dirX             = 0;
        double dirY             = 0;
        double dirZ             = 0;
        double posX             = 0;
        double posY             = 0;
        double posZ             = 0;
        uint32_t weight         = 0;

        bool flag1              = 0;
        bool flag2              = 0;
        bool flag3              = 0;
        
    } data;

    bool publish(){
        
    }

    // void vNullifyFlags(void)    {
    //     data.flag1 = 0;
    //     data.flag2 = 0;
    //     data.flag3 = 0;
    // }

    // void vClear(void)           {
    //         free(data.name);
    //         free(data.comment);
    //     };

public:

/*=================Constructor==========================*/

        /*
            1. Not to copy whole config, we just reference it.
            2. "= {}" means that the paramter has default value, so that
            `struct data data` is initialised as `struct data data{};`,
            that is defined above, with empty (not NULL) strings
            3. Don't mix "{}" and "= {}".

            Use by:
            messsages({
                "",     //name
                "",     //comment

                0.0,    //dirX
                0.1,    //dirY
                0.2,    //dirZ
                0.3,    //posX
                0.4,    //posY
                0.5,    //posZ

                10,     //weight

                true,   //flag1
                true,   //flag2
                true    //flag3
            })

            Note: C++20 allows to initialization by name
            messages({
                .name = "Test"
                .comment = "No comment here"
                .flag1 = true;
            })

            Where other fields of the config are defaulted to `struct data`'s
            default values
        */

    messages( struct data const & _data ) {
        data = _data;
    }

    messages(){
        /* data struct is defaulted to all zeroes*/

        publish();
    }

/*=======================================================*/

    ~messages() {}

    // char * pcComposeGeneric(){  

    //     // std::string a;
    //     char * pcResult = malloc(strlen);
    //     return pcResult;
    // }


};

int main() {

    return 0;

}
