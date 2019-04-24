#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
void printText(int spaceToTakeUp, std::string& text) {
    std::cout << std::setw(spaceToTakeUp) << text << std::setw(4) << "";
}
void printInt(int spaceToTakeUp, int num) {
    std::cout << std::setw(spaceToTakeUp) << std::right << num << std::setw(4) << "";
}
void printNormalLine(int sec1, int sec2, int sec3, int sec4, int num, string& teacher, string& firstStudent, string& lastStudent){
    printInt(sec1,num);
    printText(sec2, teacher);
    printText(sec3, firstStudent);
    printText(sec4, lastStudent);
    cout << endl;
}

int main() {

    using namespace std;


        /* PART 1: This code reads lines (names) from 3 files, and assigns 6 strings that represent students in a
         *          class to a roster based on their first name's alphabetical priority. (First student and last student)
         *
         * ...   ....   So on this I'm not sure whether we were just supposed to base it on the first letter or all of them, so
         *              I did what I could to get it so that we check every character in the name. It took me longer than it should have
         *              and if feels clunky (probably because I tried multiple solutions until it worked) but it's functional now.*/

    bool skipPart1 = false;
    if (!skipPart1) {
        ifstream file;

        string firstStudentLeslie, lastStudentLeslie, firstStudentRobert, lastStudentRobert, firstStudentAlice, lastStudentAlice;


        for (int i = 0; i < 3; i++) {

            string fileName = "textFile" + to_string(i + 1) + ".txt";
            file.open(fileName);

            string student;
            string firstStudent = "zzzzzzzzzzzzz";
            string lastStudent = "AAAAAAAAAAAA";

            while (getline(file, student)) {


                int size;

                // iterate for as long as the shorter word has chars
                if (student.length() < firstStudent.length())
                    size = student.length();
                else
                    size = firstStudent.length();

                // loop that for that amount of chars
                for (int j = 0; j < size; j++) {
                    // if the character at the iterator index has an ASCII value less than the character at the same index that is
                    //      already in the string 'firstStudent', replace the string and break loop
                    if (student[j] < firstStudent[j]) {
                        firstStudent = student;
                        break;
                    }
                    // if they are the same character, continue and check the next character
                    if (student[j] == firstStudent[j])
                        continue;
                        // otherwise it's further down the alphabet and we get outta here
                    else
                        break;
                }

                // iterate for as long as the shorter word has chars
                if (student.length() < lastStudent.length())
                    size = student.length();
                else
                    size = lastStudent.length();

                // loop that for that amount of chars
                for (int j = 0; j < size; j++) {
                    // if the character at the iterator index has an ASCII value less than the character at the same index that is
                    //      already in the string 'lastStudent', replace the string and break loop
                    if (student[j] > lastStudent[j]) {
                        lastStudent = student;
                        break;
                    }
                    // if they are the same character, continue and check the next character
                    if (student[j] == lastStudent[j])
                        continue;
                        // otherwise it's further down the alphabet and we get outta here
                    else
                        break;
                }
            }

            switch (i) {
                case (0) :
                    firstStudentLeslie = firstStudent;
                    lastStudentLeslie = lastStudent;
                    break;
                case (1):
                    firstStudentRobert = firstStudent;
                    lastStudentRobert = lastStudent;
                    break;
                case (2):
                    firstStudentAlice = firstStudent;
                    lastStudentAlice = lastStudent;
                    break;
                default:
                    break;

            }

            file.close();

        }

        int sec1 = 10, sec2 = 12, sec3 = 16, sec4 = 16;

        printText(sec1, "Lineup");
        printText(sec2, "Teacher");
        printText(sec3, "First Student");
        printText(sec4, "Last Student");
        cout << endl;

        printText(sec1, "----------");
        printText(sec2, "------------");
        printText(sec3, "---------------");
        printText(sec4, "---------------");
        cout << endl;

        printNormalLine(sec1, sec2, sec3, sec4, 1, "Leslie", firstStudentLeslie, lastStudentLeslie);
        printNormalLine(sec1, sec2, sec3, sec4, 2, "Robert", firstStudentRobert, lastStudentRobert);
        printNormalLine(sec1, sec2, sec3, sec4, 3, "Alice", firstStudentAlice, lastStudentAlice);

        cout << "3 Lineups shown" << endl;
    }




        /*
         * PART 2: Read numbers from a file and output them to console. Each line represents a hotel floor, as we progress through
         *              the file, the floor ascends to the next. Each number written in the file represents the occupancy on that floor
         *              We will skip floor 13
         */


    bool skipPart2 = true;

    if (!skipPart2) {

        const double totalSuites = 120;
        double totalOcc{0}; // occupied
        ifstream file("occupancy.txt");
        int floorOcc;


        cout << " ** Occupancy Calculator ** " << endl;

        cout << " * Suites Occupied On: * " << endl;


        for (int i = 10; i < 17; i++) {

            if (i==13)
                continue;

            string s;
            getline(file, s);
            floorOcc = stoi(s);
            totalOcc+=floorOcc;

            cout << "Floor " << i << ": " << floorOcc << endl;
        }

        cout << "\n" << setw(30) << "Total suites available: " << setw(10) << right << totalSuites << endl;
        cout << setw(30) << "Suites Occupied: " << setw(10) << right << totalOcc << endl;
        cout << setw(30) << "Percentage Occupied: " << setw(10) << right << fixed <<
             setprecision(2) << (totalOcc/totalSuites)*100 << "%" << endl;


    }




    return 0;
}