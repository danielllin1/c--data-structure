#include<iostream>
#include<fstream>
#include<vector>
#include<string>

//This is Sequential search I created to search words in a dictionary of 5757 words.

using namespace std;

int main(){
    ifstream myFile;
    myFile.open("sgb-words.txt");
    if(myFile.is_open()){
        cout << "file opened" << endl;
    }
    vector<string>myVector;
    string words, findWord;
    int wordLocation;
    while(myFile >> words){
        myVector.push_back(words);
    }
    cout << "Enter the word you want to find in the word list" << endl;
    cin >> findWord;
    if(findWord.size()!= 5){
        cout << "Re-enter a five-letter word for searching." << endl;
    }
    while(findWord.size() != 5){
        cin >> findWord;
    }
    for(int i = 0; i < myVector.size(); i++){
        if(myVector[i] == findWord){
            wordLocation = i;
        }
    }
    cout << "The index number of your word is: " << wordLocation << endl;
    cout << myVector.size() << endl;
    return 0;
}