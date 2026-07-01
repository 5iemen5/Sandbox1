#include <iostream>
#include <iomanip>

int main() 
{
    // Inputs
    int ModelChoice;
    int RPM;
    float Tc;
    float Te;

    std::cout << "--- Compressor COP Testbench ---\n";
    std::cout << "Choose Compressor Model (3 = 9kW, 7 = 18kW): ";
    std::cin >> ModelChoice;
    
    if (ModelChoice != 3 && ModelChoice != 7) {
        std::cout << "Invalid model selected. Exiting...\n";
        return 1;
    }

    std::cout << "Enter RPM (e.g., 4300): ";
    std::cin >> RPM;
    std::cout << "Enter Tc [Condenser Temp in C] (e.g., 32.2): ";
    std::cin >> Tc;
    std::cout << "Enter Te [Evaporator Temp in C] (e.g., -4.2): ";
    std::cin >> Te;
    std::cout << "\n";

    // --- PLC MATHEMATICS BLOCK START ---
    
    // Intermediate variables (Strict PLC Rules: 1 per line, no pointers)
    float f_RPM;
    float T0_E0;
    float T0_E1;
    float T0_E2;
    float T0;
    float T1_E0;
    float T1_E1;
    float T1;
    float T2;
    float T3;
    float COP_f;
    int COP;

    // Coefficients (9 kW)
    float C0_3;
    float C1_3;
    float C2_3;
    float C3_3;
    float C4_3;
    float C5_3;
    float C6_3;
    float C7_3;
    float C8_3;
    float C9_3;
    float C10_3;
    float C11_3;
    float C12_3;
    float C13_3;
    float C14_3;
    float C15_3;
    float C16_3;
    float C17_3;
    float C18_3;
    float C19_3;

    // Coefficients (18 kW)
    float C0_7;
    float C1_7;
    float C2_7;
    float C3_7;
    float C4_7;
    float C5_7;
    float C6_7;
    float C7_7;
    float C8_7;
    float C9_7;
    float C10_7;
    float C11_7;
    float C12_7;
    float C13_7;
    float C14_7;
    float C15_7;
    float C16_7;
    float C17_7;
    float C18_7;
    float C19_7;

    // Default Assignments
    T0_E0 = 0.0;
    T0_E1 = 0.0;
    T0_E2 = 0.0;
    T0 = 0.0;
    T1_E0 = 0.0;
    T1_E1 = 0.0;
    T1 = 0.0;
    T2 = 0.0;
    T3 = 0.0;
    COP_f = 0.0;
    
    // Model 3 SCALED kRPM Coefficients (9 kW)
    C0_3  =  14.63297;
    C1_3  =  1.378598;
    C2_3  = -0.5036953;
    C3_3  =  0.6704763;
    C4_3  = -0.4935517;
    C5_3  =  0.01993833;
    C6_3  = -0.03939734;
    C7_3  =  0.005887984;
    C8_3  = -0.01620042;
    C9_3  =  0.00877153;
    C10_3 =  0.0314532;
    C11_3 =  0.001934559;
    C12_3 = -0.001549407;
    C13_3 = -0.0002824757;
    C14_3 =  0.0009582089;
    C15_3 = -0.0005522731;
    C16_3 = -0.00002297607;
    C17_3 =  0.00008699736;
    C18_3 = -0.0001009639;
    C19_3 =  0.00003169034;

    // Model 7 SCALED kRPM Coefficients (18 kW)
    C0_7  =  14.38912;
    C1_7  =  1.225226;
    C2_7  = -0.4783942;
    C3_7  =  0.6590664;
    C4_7  = -0.4483610;
    C5_7  =  0.02067425;
    C6_7  = -0.04292651;
    C7_7  =  0.005487856;
    C8_7  = -0.01586112;
    C9_7  =  0.008081693;
    C10_7 =  0.02911125;
    C11_7 =  0.001343667;
    C12_7 = -0.0006933652;
    C13_7 = -0.0002485661;
    C14_7 =  0.0009026697;
    C15_7 = -0.0004464368;
    C16_7 = -0.00002223244;
    C17_7 =  0.00008935405;
    C18_7 = -0.0001004611;
    C19_7 =  0.00003094984;

    // Execution
    f_RPM = (float)(RPM) / 1000.0; 

    // Horner's Method execution block
    if (ModelChoice == 3) 
    {
        T3 = C10_3;
        T2 = C4_3 + (C11_3 * Tc) + (C12_3 * Te);
        
        T1_E0 = C1_3 + (Tc * (C5_3 + (Tc * C13_3)));
        T1_E1 = C6_3 + (Tc * C14_3) + (Te * C15_3);
        T1 = T1_E0 + (Te * T1_E1);
        
        T0_E0 = C0_3 + (Tc * (C2_3 + (Tc * (C7_3 + (Tc * C16_3)))));
        T0_E1 = C3_3 + (Tc * (C8_3 + (Tc * C17_3)));
        T0_E2 = C9_3 + (Tc * C18_3) + (Te * C19_3);
        T0 = T0_E0 + (Te * (T0_E1 + (Te * T0_E2)));

        COP_f = T0 + (f_RPM * (T1 + (f_RPM * (T2 + (f_RPM * T3)))));
    }
    else if (ModelChoice == 7) 
    {
        T3 = C10_7;
        T2 = C4_7 + (C11_7 * Tc) + (C12_7 * Te);
        
        T1_E0 = C1_7 + (Tc * (C5_7 + (Tc * C13_7)));
        T1_E1 = C6_7 + (Tc * C14_7) + (Te * C15_7);
        T1 = T1_E0 + (Te * T1_E1);
        
        T0_E0 = C0_7 + (Tc * (C2_7 + (Tc * (C7_7 + (Tc * C16_7)))));
        T0_E1 = C3_7 + (Tc * (C8_7 + (Tc * C17_7)));
        T0_E2 = C9_7 + (Tc * C18_7) + (Te * C19_7);
        T0 = T0_E0 + (Te * (T0_E1 + (Te * T0_E2)));

        COP_f = T0 + (f_RPM * (T1 + (f_RPM * (T2 + (f_RPM * T3)))));
    }

    // Safety clamps
    if (COP_f > 15.0)
    {
        COP_f = 15.0;
    }
    else if (COP_f < 0.0)
    {
        COP_f = 0.0;
    }

    // Convert to scaled integer for PLC
    COP = (int)((COP_f * 100.0) + 0.5); // +0.5 mimics standard FloatToIntegerRound

    // --- PLC MATHEMATICS BLOCK END ---


    // Print Results
    std::cout << "====================================\n";
    std::cout << "Model Selected                : " << (ModelChoice == 3 ? "9 kW" : "18 kW") << "\n";
    std::cout << "Calculated Floating Point COP : " << std::fixed << std::setprecision(5) << COP_f << "\n";
    std::cout << "Final Integer (PLC Format)    : " << COP << "\n";
    std::cout << "====================================\n";

    return 0;
}