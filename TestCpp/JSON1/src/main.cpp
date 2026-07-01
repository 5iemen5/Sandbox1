#include "main.hpp"

class messages{
private:

    struct content{

        uint8_t * name          = NULL;
        uint8_t * comment       = NULL;
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
        
    } content;

    void vNullifyFlags(void)    {
        content.flag1 = 0;
        content.flag2 = 0;
        content.flag3 = 0;
    }

    void vClear(void)           {
            free(content.name);
            free(content.comment);
        };

public:

    messages(/* args */) {
        content.name        = (const uint8_t) " ";
        content.comment     = (const uint8_t) " ";
        content.dirX        = 0.0;
        content.dirY        = 0.0;
        content.dirZ        = 0.0;
        content.posX        = 0.0;
        content.posY        = 0.0;
        content.posZ        = 0.0;
        content.weight      = 0;
        
        
    }
    ~messages() {}

    char * pcComposeGeneric(){  

        // std::string a;
        char * pcResult = malloc(strlen);
        return pcResult;
    }


} message;

int main() {

    return 0;

}
