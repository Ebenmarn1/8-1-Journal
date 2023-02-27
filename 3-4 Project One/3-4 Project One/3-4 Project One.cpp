// 3-4 Project One.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Eben Marneweck 1/22/2023 Project 1

#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;
class timeClock {
private:
    //Clock defaults set to zero for debugging purposes. E
    int hour = 0;
    int second = 0;
    int minute = 0;
    //Menu options
    const char* menuChoice[4]
        = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
public:

    //sets hour for clock
    void setHour(int h) {
        hour = h;
    }

    // gets hour for the clock
    int getHour() {
        return hour;
    }
    //sets second for the clock
    void setSecond(int s) {
        second = s;
    }

    //gets second for the clock
    int getSecond() {
        return second;
    }

    //sets minute for the clock
    void setMinute(int s) {
        minute = s;
    }

    //gets minutes for the clock
    int getMinute() {
        return minute;
    }

    //add one second to the clock
    void addOneSecond() {
        //if time is  below 59 add one second
    if (getSecond() <= 58) {
        setSecond(getSecond() + 1);
    }
    else {
        ////if time is at 59 add one minute
        setSecond(0);
        addOneMinute();
    }
    // nothing to return, just call setSecond() with the right value and addOneMinute() when needed
}

    //adds one minute to the clock
    void addOneMinute() {
    //if time is below 59 add one minute
    if (getMinute() <= 58) {
        setMinute(getMinute() + 1);
    }
    else {
        //if time at 59 add a hour
        setMinute(0);
        addOneHour();
    }
    // nothing to return, just setMinute to the appropriate value and use addOneHour if needed
}

    //adds one hour to the clock
    void addOneHour() {

    //if time below 23 add one hour
    if (getHour() < 23) {
        setHour(getHour() + 1);
    }
    else {
        //if time at 23 start a new day
        setHour(0);

    }
}

    //lets the user set the clock initialy
    void setClock() {
        //initialize varialbe to check
    int hr;
    int min;
    int sec;
    bool goodinput = false;
    while (goodinput == false)
    {
        cout << "Enter time in H M S" << endl;
        cin >> hr >> min >> sec;
        //makes sure all inputs are within legal bound. No 71 minutes or -5 seconds/hours
        if (hr >= 0 && hr <= 23 && min >= 0 && min < 60 && sec >= 0 && sec < 60) {
            setHour(hr);
            setMinute(min);
            setSecond(sec);
            //cout << hr << min << sec; debuging inputs
            goodinput = true;
        }
    }

    
}

    //formates the parts of the clock to a double digit format leading with a 0 if below 0
    string twoDigitString(unsigned int n) {
    int number = n;
    //initialized string to make this work
    string formatedInt;
    //if number is in the single digits add a zero to the front
    if (number < 10)
    {
        formatedInt = "0" + to_string(number);
    }
    //there should never be a number bigger then 24 so everything bigger then 9 is just made into a string
    else {
        formatedInt = to_string(number);
    }
    //returns the string
    return formatedInt;
}

    //prints a string of chars #n long
    string nCharString(size_t n, char c) {
    //makes a variable to change
    string charString;
    //we add a charcter onto a string n times with a for loop
    for (int i = 0; i < n; i++)
        charString = charString + c;
    return charString;
}

    //formats the hours, minutes, and seconds into the 12 hour clock format
    string formatTime12(unsigned int h, unsigned int m, unsigned int s) {


    string hourFormat;
    if (h <= 12) {
        //if hour is not zero then string is formated normally
        if (h != 0) {
            hourFormat = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);

        }
        else {
            //else for a 12 hour day 0 is made into 12
            hourFormat = twoDigitString(12) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
        }
        // checks if its before noon or at noon and assigns the appriopiat AM or PM
        if (h == 12) {
            hourFormat = hourFormat + " P M";
        }
        else {
            
            hourFormat = hourFormat + " A M";
        }
    }
    //every number here will be after noon
    else {
        hourFormat = twoDigitString(h - 12) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " P M";
    }
    return hourFormat;
}

    //formats time into the 24 hour clock format using twoDigitString()
    //does not need any extra steps since we store the numbers from a 0-23 or 0-59
    string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string format24 = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);


    return format24;
}

    //Displays the clocks in a set manner
    void displayClocks(unsigned int h, unsigned int m, unsigned int s) {


    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
    cout << "*      " << "12-HOUR CLOCK" << "      *   ";
    cout << "*      " << "24-HOUR CLOCK" << "      *" << endl;
    cout << endl;
    cout << "*      " << formatTime12(h, m, s) << "       *   ";
    cout << "*        " << formatTime24(h, m, s) << "         *" << endl;
    cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
}



    //gets the users choice and checks input
    unsigned int getMenuChoice(unsigned int maxChoice) {
        //initializes the menuchoice at zero to let us use it
        int menuChoice = 0;
        //ask for user choice
        cin >> menuChoice;
        //if user choice is not the maxxhoice then enter the loop
        //loop checks if choice is greater then max choice or lower then 0. Letting only a good input in
        while (menuChoice != maxChoice) {
         
            if (menuChoice > maxChoice) {
                cin >> menuChoice;
            }
            else if (menuChoice > 0) {
                return menuChoice;
            }
            else {
                cin >> menuChoice;
            }

        }

        return menuChoice;
    }

    //goes the array menuChoice and prints it out to the console
    void printMenu(const char* strings[], unsigned int numStrings, unsigned char width) {

    cout << nCharString(width, '*') << endl;
    for (unsigned int i = 0; i < numStrings; i++) {
        //this is needed since getSize doesnt seem to count spaces 
        string word = strings[i];
        //displays each menu choice calculating automatically using the length of each menu choice individually to center it 
        cout << "* " << i + 1 << " - " << strings[i] << nCharString(width - (word.length() + 7), ' ') << "*" << endl;

        //prevents us from printing an end line at the end
        if (i <= numStrings - 2) {
            cout << endl;
        }
    }
    cout << nCharString(width, '*') << endl;
}
    

    //The engine of the program. It displays everything and allows the user to interact with the clock until they exit
    void mainMenu() {
    printMenu(menuChoice, 4, 52);

    //assings an appriorpiate choice to choice
    int choice = getMenuChoice(4);

    //exits if choice is 4. Assigns approiate function to users choice
    while (choice != 4) {

        if (choice == 1) {
            addOneHour();
        }
        else if (choice == 2) {
            addOneMinute();
        }
        else if (choice == 3) {
            addOneSecond();
        }
        //displays the clock after every choice
        displayClocks(getHour(), getMinute(), getSecond());
        //prints menu
        printMenu(menuChoice, 4, 52);
        //reasks user for menu input
        choice = getMenuChoice(4);

    }

}

};









int main()
{
    //sets myobject
    timeClock myobject;
    //lets user set clock
    myobject.setClock();
    //immediately display clock after user sets it
    myobject.displayClocks(myobject.getHour(), myobject.getMinute(), myobject.getSecond());

    //starts the mainmenu functiion
    myobject.mainMenu();
}

