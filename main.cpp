#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    ifstream filein("Ir.txt");
    ofstream fileout("temp.txt");
    int foundInt;
    if (!filein || !fileout) {
        cout << "ERROR: can't open file(s)\n";
        return 1;
    }

    string strTemp;
    int intTemp;
    bool newLine;
    while (filein >> strTemp) {
        /*if (isdigit(strTemp[0])) { //check if current string within line is an int
            intTemp = stoi(strTemp);
            if (intTemp >= 10) intTemp -= 147600;
            size_t start_pos = strTemp.find(strTemp);
            if (start_pos == std::string::npos) return false;
            strTemp.replace(start_pos, strTemp.length(), to_string(intTemp));
            fileout << "  ";
        }
        fileout << strTemp << " \n";*/
        newLine = false;
        if (isdigit(strTemp[0])) {
            intTemp = stoi(strTemp);
            if (intTemp >= 10) newLine = true;
        }
        if (newLine) fileout << "\n  ";
        fileout << strTemp << " ";
    }
    fileout.close();
    return 0;
}