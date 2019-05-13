#include<iostream>
#include<fstream>
#include<vector>
#include<string>

//This is a sequential search file I created to search words in a dictionary("sgb-words.txt") of 5756 words.

using namespace std;

int myTest(vector<string>testVector,int number,string key);

int main(){
    ifstream myFile;
    myFile.open("sgb-words.txt");
    if(myFile.is_open()){
        cout << "file opened" << endl;
    }
    vector<string>myVector;
    string words, findWord;
    int wordLocation;
    //Passing words into myVector.
    while(myFile >> words){
        myVector.push_back(words);
    }
    cout << "Enter the word you want to find in the word list" << endl;
    cin >> findWord;
    while(findWord.size() != 5){
        cout << "Re-enter a five-letter word for searching." << endl;
        cin >> findWord;
    }
    //This is a simple loop to perform sequential search.
    for(int i = 0; i < myVector.size(); i++){
        if(myVector[i] == findWord){
            wordLocation = i;
        }
    }
    //Checking the boundary.
    if(wordLocation == 0){
        cout << "The word you entered can not be found in the dictionary." << endl;
    }
    //printing out the index of the word you entered.
    else{
    cout << "The index number of your word is: " << wordLocation << endl;
    }
    //-------------.
    //myTest function is what I learned from Data structure class.
    myTest(myVector,myVector.size(),findWord);
        return 0;
}
int myTest(vector<string>testVector,int number,string key){
    int i = 0;
    while(i < number && testVector[i] != key){
         i++;
    }
    //Checking the boundary.
    if(i == number && key != testVector[i]){
        cout << "The word you entered can not be found in the dictionary." << endl;
    }
    else{
    //printing out the index of the word you entered.
        cout << "The index number of your word is: " << i << endl;
    }
    if(i < number){
        return true;
    }
    else{
        return false;
    }
}
