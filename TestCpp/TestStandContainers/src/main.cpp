#include "main.h"


    std::vector<int32_t> a = {0, 1 ,2 ,3};

int main() {


    if(!(a.empty() )) {

        // int32_t size = a.size();    

        for(int32_t i = 0; i< (int32_t) a.size(); i++){
        
            printf("%d\n", a[i]);

        }
    }

    return 0;
}
