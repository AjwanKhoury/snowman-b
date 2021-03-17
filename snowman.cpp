#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <array>

using namespace std;
enum parts{
    HAT, NOSE, LEFT_EYE, RIGHT_EYE, LEFT_ARM, RIGHT_ARM, TORSO, BASE //moth and nose are the same
} ;


const int sec=4, inputSize=8;
const char minD='1', maxD='4';

const array<std::string,sec> hats={"_===_"," ___\n .....","  _\n  /_\\"," ___\n (_*_)"};
const array<std::string,sec> noses={",", ".", "_"," "}; // moth and nose are the same
const array<std::string,sec> eyes={".", "o", "O","-"};
const array<std::string,sec> leftArmUp={" ","\\"," "," "};
const array<std::string,sec> leftArm={"<"," ","/"," "};
const array<std::string,sec> RightArmUp={" ","/"," "," "};
const array<std::string,sec> RightArm={">"," ","\\"," "};
const array<std::string,sec> torsos={" : ", "] [", "> <","   "};
const array<std::string,sec> bases={" : ", "\" \"", "___","   "};




void checkInput(int num){
    //we check if the length of the input is equal to 8
    std:: string numString= std:: to_string(num);
    int numLength= numString.length();
    if(numLength != inputSize){
        throw std:: out_of_range("The length must be 8!");
    }
    //we check the range of the  numbers - they have to be between 1 To 4
    for(int i=0; i<numLength; i++){
        if(numString[i]< minD || numString[i]> maxD){
            throw std:: out_of_range("The numbers in the input must be between 1 to 4");
        }
    }   
}

string buildSnowman(array<int, inputSize> arr){
    string hat=" "+hats.at(arr[HAT]);
    string face=leftArmUp.at(arr[LEFT_ARM])+"("+eyes.at(arr[LEFT_EYE]) + noses.at(arr[NOSE])+eyes.at(arr[RIGHT_EYE])+")" + RightArmUp.at(arr[RIGHT_ARM]);
    string torso=leftArm.at(arr[LEFT_ARM])+"("+torsos.at(arr[TORSO])+")"+ RightArm.at(arr[RIGHT_ARM]);
    string base=" ("+bases.at(arr[BASE])+")";
    return ""+hat+"\n"+face+"\n"+torso+"\n"+base+"\n";
}



namespace ariel{
    string snowman(int t){
        checkInput(t);
        array<int,inputSize> arr={};
        const int basee=10;

        for(int i=inputSize-1; i>=0; i--){
            arr.at(i)=(t%basee)-1;
            t/=basee;
        }
        return buildSnowman(arr);
    }
}

