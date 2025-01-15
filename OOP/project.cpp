#include <iostream>
using namespace std;

// Display the main menu
void menu()
{
    cout << ">>>>    UNIVERSITY AGGREGATE CALCULATIONS    <<<<" << endl;
    cout << endl;
    cout << "Choose one of the following options:" << endl;
    cout << "Press 1: FAST NU" << endl;
    cout << "Press 2: NUST" << endl;
    cout << "Press 3: GIKI" << endl;
    cout << "Press 4: ETEA Medical" << endl;
    cout << "Press 5: ETEA Engineering" << endl;
    cout << "Enter your choice: ";
}

// Class for inputting marks
class inputMarks
{
protected:
    int obtainedMatricMarks, totalMatricMarks, obtainedFscMarks, totalFscMarks;
    double matricPercentage, fscPercentage;

public:
    // Function to input Matric marks and calculate percentage
    void matricPercentageInput()
    {
        while (1)
        {
            cout << "Enter Total marks of Matric: ";
            cin >> totalMatricMarks;
            cout << "Enter obtained marks of Matric: ";
            cin >> obtainedMatricMarks;
            if (obtainedMatricMarks > totalMatricMarks || obtainedMatricMarks<0 )
            {
                cout << "Please Enter Correct Marks. " << endl;
            }
            else
                break;
        }
    }

    // Function to input Fsc marks and calculate percentage
    void fscPercentageInput()
    {
        while (1)
        {
            cout << "Enter Total marks of Fsc: ";
            cin >> totalFscMarks;
            cout << "Enter obtained marks of Fsc: ";
            cin >> obtainedFscMarks;
            if (obtainedFscMarks <= totalFscMarks || obtainedFscMarks<0 || totalFscMarks <0) 
                break;
            else
                cout << "Please Enter Correct Marks: ";
        }
    }
        void calpercentage(){
        matricPercentage = (float)(obtainedMatricMarks / (float)totalMatricMarks );
        fscPercentage = (obtainedFscMarks /(float)totalFscMarks) ;
        }
};

// Class for calculating FAST NU aggregate
class FAST : public inputMarks
{
protected:
    int attemptedAdvancedMath, correctAdvancedMath;
    int attemptedBasicMath, correctBasicMath;
    int attemptedEnglish, correctEnglish;
    int attemptedIQ, correctIQ;
    double fastTestScore, fastAggregate;

    // Function to calculate test score for FAST NU
    void calculateTestScore()
    {
        int wrongAdvanced = attemptedAdvancedMath - correctAdvancedMath;
        int wrongBasicMath = attemptedBasicMath - correctBasicMath;
        int wrongEnglish = attemptedEnglish - correctEnglish;
        int wrongIQ = attemptedIQ - correctIQ;

        double scoreAdvancedMath = correctAdvancedMath - (wrongAdvanced / 3.0);
        double scoreEnglish = correctEnglish / 3.0;
        double scoreIQ = correctIQ / 3.0;
        double scoreBasicMath = correctBasicMath - (wrongBasicMath / 3.0);

        fastTestScore = scoreAdvancedMath + scoreEnglish + scoreIQ + scoreBasicMath;
    }

public:
    // Function to calculate FAST NU aggregate
    void calculateAggregate()
    {
        cout << "--- FAST NU Aggregate Calculation ---" << endl;

        // Input for Advanced Math
        do
        {
            cout << "Enter number of MCQs attempted from Advanced Math (max 50): ";
            cin >> attemptedAdvancedMath;
        } while (attemptedAdvancedMath < 0 || attemptedAdvancedMath > 50);

        do
        {
            cout << "Enter number of correct MCQs from Advanced Math: ";
            cin >> correctAdvancedMath;
        } while (correctAdvancedMath < 0 || correctAdvancedMath > attemptedAdvancedMath);

        // Input for Basic Math
        do
        {
            cout << "Enter number of MCQs attempted from Basic Math (max 20): ";
            cin >> attemptedBasicMath;
        } while (attemptedBasicMath < 0 || attemptedBasicMath > 20);

        do
        {
            cout << "Enter number of correct MCQs from Basic Math: ";
            cin >> correctBasicMath;
        } while (correctBasicMath < 0 || correctBasicMath > attemptedBasicMath);

        // Input for English
        do
        {
            cout << "Enter number of MCQs attempted from English (max 20): ";
            cin >> attemptedEnglish;

            if (attemptedEnglish < 0 || attemptedEnglish > 20)
            {
                cout << "Invalid input! Attempted MCQs should be between 0 and 20.\n";
                continue;
            }

            cout << "Enter number of correct MCQs from English: ";
            cin >> correctEnglish;

            if (correctEnglish < 0 || correctEnglish > attemptedEnglish)
            {
                cout << "Invalid input! Correct MCQs cannot exceed attempted MCQs.\n";
                continue;
            }

            break; // Exit loop if all inputs are valid
        } while (true);

        // Input for IQ
        do
        {
            cout << "Enter number of MCQs attempted from IQ (max 20): ";
            cin >> attemptedIQ;
        } while (attemptedIQ < 0 || attemptedIQ > 20);

        do
        {
            cout << "Enter number of correct MCQs from IQ: ";
            cin >> correctIQ;
        } while (correctIQ < 0 || correctIQ > attemptedIQ);

        // Calculate aggregate
       calpercentage();
        calculateTestScore();

        fastAggregate = ((matricPercentage * 0.1) + (fscPercentage * 0.40) + (fastTestScore * 0.5));
        cout << "Your FAST NU Aggregate: " << fastAggregate << endl;
    }
};

class NUST : public inputMarks {
protected:
    int netMarks;                  // NET marks obtained
    double nustAggregate;          // Final aggregate score
    double netPercentage;          // NET percentage

public:
    void calculateAggregate() {
        cout << "--- NUST Aggregate Calculation ---" << endl;

        // Input NET marks
        do {
            cout << "Enter your NET marks (out of 200): ";
            cin >> netMarks;
            if (netMarks < 0 || netMarks > 200) {
                cout << "Please enter valid NET marks (0-200).\n";
            } else {
                break;
            }
        } while (true);

        // Calculate percentages
        calpercentage(); // Matric and FSc percentages are already calculated here
        netPercentage = (netMarks / 200.0); // Fix division and multiply by 100

        // Calculate aggregate
        nustAggregate = (matricPercentage * 10) + (fscPercentage * 15) + (netPercentage * 75);
    }

    void showAggregrate() {
        // Display aggregate
        cout << "Your NUST Aggregate: " << nustAggregate << "%" << endl;
    }
};


// Class for calculating GIKI aggregate
class GIKI : public inputMarks
{
protected:
    int gikiTestMarks;
    double gikiAggregate, gikiTestPercentage;

public:
    void calculateAggregate()
    { // Function Overriding
        cout << "Enter your GIKI Test marks: ";
        cin >> gikiTestMarks;
        gikiTestPercentage = ((gikiTestMarks * 100) / 200);
        gikiAggregate = ((matricPercentage * 5) / 100) + ((fscPercentage * 10) / 100) + ((gikiTestPercentage * 85) / 100);
    }
    void showAggregate()
    {
        cout << ">>>>  Your GIKI Aggregate: " << gikiAggregate << endl;
    }
};

// Class for calculating ETEA Medical aggregate
class EMedical : public inputMarks
{
protected:
    int eteaTestMarks;
    double eMedicalAggregate, eTestPercentage;

public:
    void calculateAggregate()
    { // Function Overriding
        cout << "Enter your ETEA Medical Test marks: ";
        cin >> eteaTestMarks;
        eTestPercentage = ((eteaTestMarks * 100) / 200);
        eMedicalAggregate = ((fscPercentage * 50) / 100) + ((eTestPercentage * 50) / 100);
    }
    void show()
    {
        cout << ">>>>  Your ETEA Medical Aggregate: " << eMedicalAggregate << endl;
    }
};

// Class for calculating ETEA Engineering aggregate
class EEngineering : public inputMarks
{
protected:
    int engineeringTestMarks;
    double engineeringAggregate, engineeringTestPercentage;

public:
    void calculateAggregate()
    { // Function Overriding
        cout << "Enter your ETEA Engineering Test marks: ";
        cin >> engineeringTestMarks;
        engineeringTestPercentage = ((engineeringTestMarks * 100) / 800);
        engineeringAggregate = ((matricPercentage * 10) / 100) + ((fscPercentage * 40) / 100) + ((engineeringTestPercentage * 50) / 100);
    }
    void show()
    {
        cout << ">>>>  Your ETEA Engineering Aggregate: " << engineeringAggregate << endl;
    }
};

// Main function to handle user input and display results
int main()
{
    int option;
    FAST fast;
    NUST nust;
    GIKI giki;
    EMedical medical;
    EEngineering engineering;
    char continueChoice;

    while (1)
    {
        menu();
        cin >> option;

        // FAST NU Aggregate Calculation
        if (option == 1)
        {
            cout << "----    FAST NU Aggregate Calculation -----" << endl;
            cout << endl;
            fast.matricPercentageInput();
            fast.fscPercentageInput();
            fast.calculateAggregate();
        }
        // NUST Aggregate Calculation
        else if (option == 2)
        {
            cout << "----    NUST Aggregate Calculation    -----" << endl;
            cout << endl;
            nust.matricPercentageInput();
            nust.fscPercentageInput();
            nust.calculateAggregate();
            nust.showAggregrate();
        }
        // GIKI Aggregate Calculation
        else if (option == 3)
        {
            cout << "----    GIKI Aggregate Calculation    -----" << endl;
            cout << endl;
            giki.matricPercentageInput();
            giki.fscPercentageInput();
            giki.calculateAggregate();
            giki.showAggregate();
        }
        // ETEA Medical Aggregate Calculation
        else if (option == 4)
        {
            cout << "----   ETEA MEDICAL Aggregate Calculation    -----" << endl;
            cout << endl;
            medical.fscPercentageInput();
            medical.calculateAggregate();
            medical.show();
        }
        // ETEA Engineering Aggregate Calculation
        else if (option == 5)
        {
            cout << "----   ETEA ENGINEERING Aggregate Calculation    -----" << endl;
            cout << endl;
            engineering.matricPercentageInput();
            engineering.fscPercentageInput();
            engineering.calculateAggregate();
            engineering.show();
        }
        else
        {
            cout << "****  Invalid input. Please select a correct option  ****" << endl;
        }

        // Option to continue or exit
        cout << "----------------------------" << endl;
        cout << "To continue, press 'Y'. To exit, press 'E'." << endl;
        cout << endl;
        cin >> continueChoice;
        if (continueChoice == 'E' || continueChoice == 'e')
        {
            cout << "Thank you for using the program." << endl;
            cout << "--------- Exiting ---------" << endl;
            break;
        }
    }
}