//Lab13-1
#include<iostream>
#include<fstream>
#include<string>

void pressEnterToContinue();
int countChar(string filename);
int countWords(string filename);
using namespace std;

int main() {
    string datafile;
    cout << "input file: ";
    getline(cin, datafile);
    pressEnterToContinue();
    int words = countWords(datafile);
    cout << "Words: " << words << endl;
    int letters = countChar(datafile);
    cout << "Characters: " << letters << endl;
}

int countChar(string filename){
    ifstream inFile;
    int total = 0, tot_words = 0, i = 0;
    char ch, str[1000];
    inFile.open(filename);
    while (inFile >> filename >> ch) {
        str[total] = ch;
        total++;
    }
    inFile.close();
    str[total] = '\0';
    while (str[i] != '\0') {
        if (str[i] == '\n') {
            if (str[i + 1] != '\0' && str[i + 1] != ' ') {
                tot_words++;
                i++;
            }
        }
        else if (str[i] != ' ') i++;
        else {
            if (str[i + 1] != '\0' && str [i + 1] != ' ') {
                tot_words++;
                i++;
            }
        }
    }
    return tot_words;
}

int countWords(string filename) {
    ifstream inFile;
    int tot = 0;
    char file[1000], ch;
    inFile.open(filename);
    while(inFile >> filename >> ch) {
        tot++;
    }
    inFile.close();
    return tot;
}

void pressEnterToContinue() {
    cout << "\nPress enter to continue... \n";
    cin.clear();
    while (cin.get() != '\n');
}