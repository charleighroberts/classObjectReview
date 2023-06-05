/*Classes and Objects Review
 Write a class that will hold the following information: 
 name (first and last name should each be stored in string variables), 
 ID Number (you will generate these (1-25 is fine) and they should be sequential), 
 pay rate (a percentage in the form of a decimal), and base pay (an integer).
 
 Create a file of names to read in both the first and last name of each of your fictional employees, 
 assigning each one an id number at the same time.  The names and id numbers should be stored in arrays or vectors (your choice).  
 Assign each employee a pay rate and use 15,000 as the base pay.  There should be a minimum of 25 employees.

Create get and set functions for each part of the class and create both default and overloaded constructors.  
Remember that constructors will have the exact same name as the class they are part of! (Yes, capitalization matters!)

Create objects for each employee, using either the default or the overloaded constructor.  
Print out the details (nicely spaced and with proper labels) for employees number 9 through 19 with their calculated pay instead of the base pay.  
Calculated pay is one plus their pay rate multiplied by the base pay.  ( 1+PR ) * BP*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> 
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

bool openFileIn(fstream&, string);

class Review
{
private:
    //varibles
    string name;
    int idnumber;
    double payrate;
    int basepay;
    int calculatedpay;
public:
    //default constructor
    Review()
    {

    }
    //overloaded
    Review(string name, int idnumber, int basepay)
    {
        this->name = name;
        this->idnumber = idnumber;
        this-> basepay = basepay;
    }
    //get functions
    string getname(string name)
    {
        this->name = name;
        return name;
    }
    int getbasepay(int basepay)
    {
        this->basepay = basepay;
        return basepay;
    }
    int getidnumber(int idnumber)
    {
        this->idnumber = idnumber;
        return idnumber;
    }
    double getpayrate(double payrate)
    {
        this->payrate = payrate;
        return payrate;
    }
    //setter
    int setcalculatedpay()
    {
        //int calculatedpay = 0;
        calculatedpay = (1 + payrate)* basepay;
        //cout << calculatedpay << endl;
        //this->calculatedpay = calculatedpay;
        return calculatedpay;
    }

    void display() //for testing output
    {
        cout.precision(2);
        cout << this->name << " " << this->idnumber << " " << this->basepay << " " << fixed << this->payrate;
        cout << " " << this->calculatedpay << endl;
    }
    void requesteddisplay()
    {
        //cout.precision(2);
        if (idnumber < 10)
        {
          cout << "0" << this->idnumber << setw(10) << "$" << this->calculatedpay << setw(20) << this->name << endl;
        }
        else 
        {
            cout << this->idnumber << setw(10) << "$" << this->calculatedpay << setw(20) << this->name << endl;
        }
    }
};


int main()
{
    cout << "Hello World!\n";

    //random number start
    srand(time(0));
    int random = 0;
    double randompr = 0;

    //array to hold employee names
    string employeenames[25];

    //array to hold employee id's
    int idnumberarray[25];

    //array to hold pay rate
    double payratearray[25];
    
    //import employee name file data to array
    fstream employeenamefile;

    if (openFileIn (employeenamefile, "List of Made-up Employee Names.txt"))
    {
        //cout << "employee file opened succesfully\n";

        if (employeenamefile)
        {
            
            //for loop to read data
            for (int i = 0; i < 25; i++)
            {
                getline(employeenamefile, employeenames[i]);
               // assign employees a random number & put in array
                random = 1 + (rand() % 25);
              
                for (int ran = 0; ran < 25; ran++)
                {
                    if (ran != idnumberarray[ran])
                    {
                        idnumberarray[i] = random;

                    }
                }

                //assign employee a random payrate & put in array
                randompr = 1 + (rand() % 100);
               // for (int ran = 0; ran < 25; ran++)
                //{
                   // if (ran != payratearray[ran])
                   // {
                        payratearray[i] = randompr/100;
                       // cout.precision(2);
                      //  cout << "PayRate: " << fixed << payratearray[i] << endl;
                        

                       

                   // }
//}

            }
        }
    }
    else
    {
        cout << "file opened in error\n";
    }

    /*test run
    //state employee names 
    cout << "employees currently working for Review.\n";
    for (int en= 0; en < 25; en++)
    {
        cout << en + 1 << ". " << employeenames[en] << " \nID number: " << idnumberarray[en] << endl;
        cout.precision(2);
        cout << "PayRate: " << fixed << payratearray[en] << endl;
    }*/
    //set up a object for each employee
    

    /*Review employee1(employeenames[0], idnumberarray[0], 15000);
    Review employee2(employeenames[1], idnumberarray[1], 15000);
    Review employee3(employeenames[2], idnumberarray[2], 15000);
    Review employee4(employeenames[3], idnumberarray[3], 15000);
    Review employee5(employeenames[4], idnumberarray[4], 15000);
    Review employee6(employeenames[5], idnumberarray[5], 15000);
    Review employee7(employeenames[6], idnumberarray[6], 15000);
    Review employee8(employeenames[7], idnumberarray[7], 15000);
    Review employee9(employeenames[8], idnumberarray[8], 15000);
    Review employee10(employeenames[9], idnumberarray[9], 15000);
    Review employee11(employeenames[10], idnumberarray[10], 15000);
    Review employee12(employeenames[11], idnumberarray[11], 15000);
    Review employee13(employeenames[12], idnumberarray[12], 15000);
    Review employee14(employeenames[13], idnumberarray[13], 15000);
    Review employee15(employeenames[14], idnumberarray[14], 15000);
    Review employee16(employeenames[15], idnumberarray[15], 15000);
    Review employee17(employeenames[16], idnumberarray[16], 15000);
    Review employee18(employeenames[17], idnumberarray[17], 15000);
    Review employee19(employeenames[18], idnumberarray[18], 15000);
    Review employee20(employeenames[19], idnumberarray[19], 15000);
    Review employee21(employeenames[20], idnumberarray[20], 15000);
    Review employee22(employeenames[21], idnumberarray[21], 15000);
    Review employee23(employeenames[22], idnumberarray[22], 15000);
    Review employee24(employeenames[23], idnumberarray[23], 15000);
    Review employee25(employeenames[24], idnumberarray[24], 15000);*/
    

     //string employeenumber[25] = {"employee2", "employee3", "employee4", "employee5", "employee6", "employee7", "employee8", "employee9", "employee10"};
     Review employeenumber[25];

     for (int classy = 0; classy < 25; classy++)
     {
      
         employeenumber[classy].getname(employeenames[classy]);
         employeenumber[classy].getidnumber(idnumberarray[classy]);
         employeenumber[classy].getpayrate(payratearray[classy]);
         employeenumber[classy].getbasepay(15000);
         employeenumber[classy].setcalculatedpay();

     }
     //for testing
    // employeenumber[3].display();
   //  employeenumber[12].display();

     //Print out the details(nicely spacedand with proper labels) for employees number 9 through 19 with their calculated pay instead of the base pay.

     cout << "Printing out details, by request, for employees 9 through 19.\nPlease see administrator for details about other employees or to request a new report.";
         cout << endl << endl;
            //cout << "Employee name" << right << setw(30) << "ID number" << right << setw(30) << "Calculated Pay\n";
         cout << "ID" << setw(15) << "Pay"  << setw(20) << "Employee name\n";
         cout << "-----------------------------------------------------------------------\n";
       //  employeenumber[12].requesteddisplay();
        for (int x = 8; x < 19; x++)
        {
            employeenumber[x].requesteddisplay();
        }

}

bool openFileIn(fstream& file, string name)
{
    file.open(name, ios::in);
    if (file.fail())
        return false;
    else
        return true;
}
