#include "main.hpp"

template <typename T> void ShiftRight(std::vector<T> & vectorIN){

    if (vectorIN.size() == 0) {
        printf("Array empty!\n");
    }

    else{
        
        T buf1 = 0;
        T buf2 = 0;

        if (vectorIN.size() <= 1) {
            return;
        }

        for(int i = 0; i < vectorIN.size(); i++){
                                                        //If we are at 1st [0] element
            if(i == 0){
                buf1 = vectorIN.at(i+1);
                vectorIN[i+1] = vectorIN[i];
            }
                                                        //If we're not on last element yet
            else if(i < (vectorIN.size() - 1)){                                        
                buf2 = vectorIN.at(i+1);
                vectorIN.at(i+1) = buf1;
                buf1 = buf2;
            }
                                                        //If we are    
            else if (i == (vectorIN.size() - 1)  ){                              
                vectorIN.at(0) = buf1;
            }
        }
    }
}

class paramterWork{
    
private:    
    std::vector<int> intVec;
    std::vector<double> floatVec;
    std::vector<std::string> stringVec;
    enum class DataType { Integer, Float, String, Error };

    DataType detectedType =         DataType::Integer;
    DataType prevDetectedType =     DataType::Integer;

public:
    void fillPrintInitArray(std::vector<int> & vector1, int argc, char * argv[]);
    void checkElement   (int argc, char * argv[]);
    void fillVector     (int argc, char * argv[]);
}mainParam;

void paramterWork::checkElement   (int argc, char * argv[]){
        for (int i = 1; i < argc; i++) {
            char* endptr;

            std::strtol(argv[i], &endptr, 10);
            if (*endptr == '\0') { 
                if (i > 1){
                    if (detectedType != prevDetectedType){
                        detectedType = DataType::Error;
                        break;
                    }
                }
                prevDetectedType = DataType::Integer;
                continue; 
            } // Successfully parsed as purely integer

            std::strtod(argv[i], &endptr);
            if (*endptr == '\0') {

                detectedType = DataType::Float; // Found a float

                if (i > 1){
                    if (detectedType != prevDetectedType){
                        detectedType = DataType::Error;
                        break;
                    }
                }
                prevDetectedType = DataType::Float;
                continue; 
            }

            // If both failed, it's a string. We can stop checking; everything must be treated as strings.
            else {
                detectedType = DataType::String;

                if (i > 1){
                    if (detectedType != prevDetectedType){
                        detectedType = DataType::Error;
                        break;
                    }
                }
                prevDetectedType = DataType::String;
            }

            //Check if elements are same type
            if (i > 1){
                if (detectedType != prevDetectedType){
                    detectedType = DataType::Error;
                    
                    break;
                }
            }

            prevDetectedType = detectedType;
        }
    }
void paramterWork::fillVector     (int argc, char * argv[]){

    if(detectedType == DataType::Error){
        printf("Different types of data are forbidden. Aborting.\n");
        std::exit(5);
    }

    //INTEGER
    if (detectedType == DataType::Integer) {
    std::cout << "Detected type: Integers\n";
    // std::vector<int> vec;
    for (int i = 1; i < argc; i++) {
        intVec.push_back(std::stoi(argv[i])); // Convert string to int
    }
    } 
    else if (detectedType == DataType::Float) {
        std::cout << "Detected type: Floats\n";
        
        for (int i = 1; i < argc; i++) {
            floatVec.push_back(std::stod(argv[i])); // Convert string to double
        }
    } 
    else {
        std::cout << "Detected type: Strings\n";

        for (int i = 1; i < argc; i++) {
            stringVec.push_back(argv[i]); // Keep as string
        }
    }
}
void paramterWork::fillPrintInitArray(std::vector<int> & vector1, int argc, char * argv[]){

    printf("Initial array: \n");
    for(int i = 0; i < argc-1 ; i++){
        int a = atoi(argv[1+i]);
        printf("%d ", atoi(argv[1+i]));
        vector1.push_back(a);
    }
    printf("\n");
}

int main(int argc, char * argv[]) {
    T_START(0);

    std::vector<int> vector1;

    mainParam.fillPrintInitArray    (vector1, argc,  argv);
    mainParam.checkElement          (argc, argv);      //Checks if elements are int, float or string and if they are of same type 
    mainParam.fillVector            (argc, argv);      //Fills the vector if the check passed

    ShiftRight<int>(vector1);                   

    printf("\nShifted array: \n");
    for(int i = 0; i < (vector1.size()) ; i++){
        printf("%d ", vector1[i]);
    }
    printf("\n");

    T_STOP(0); 
    T_PRINT(0);


    return 0;
}
