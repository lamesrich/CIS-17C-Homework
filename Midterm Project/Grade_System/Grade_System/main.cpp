//
//  main.cpp
//  Grade_System
//
//  Created by William Sun on 10/20/15.
//  Copyright © 2015 com.mycompany. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include "ScoreList.h"

using namespace std;
void clear();
//void showtheTopN(ScoreList &);
void interface();

int main(int argc, const char * argv[])
{
    ScoreList a;
    a.addScore("Will", 99, 99, 99);
    a.addScore("Sun", 100, 100, 100);
    a.addScore("John", 55, 88, 70);
    a.addScore("Bill", 72, 91, 73);
    a.addScore("Jack", 87, 76, 75);
    ScoreList b(a);
    while(1)
    {
        interface();
        int choice;
        cin >> choice;
        switch(choice)
        {
            case 0: break;
            case 1:
            {
                cout << endl;
                b.DisplayScores();
            }
            case 2: a.sort();
//            case 3: showtheTopN(a);
    
        }
        if(choice == 0) break;
        cout << "Continue(Y/N) ?" << endl;
        char c;// take continue
        cin >> c;
        if(c == 'N' || c == 'n') break;
        clear();
    }
    cout << endl;
    
    
    return 0;
}


void interface()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "|        Welcome to Student Score Management System        |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|        1. Show the original Stuents' score               |" << endl;
    cout << "|        2. Show the ranked stuents' socre                 |" << endl;
    cout << "|        3. Show the top n(number) student                 |" << endl;
    cout << "|        4. Show the average score of top n student        |" << endl;
    cout << "|        5. Show the last n stuents' score                 |" << endl;
    cout << "|        6. Change student's score                         |" << endl;
    cout << "|        7. add student's score                            |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|                                                          |" << endl;
    cout << "|                                                          |" << endl;
    cout << "------------------------------------------------------------" << endl;
    cout << "Please input the number to select or 0 to quit: ";
    
}


void clear()
{
    for(int i = 0; i < 20; i++) cout << endl;
}





