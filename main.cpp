/*
 * Module 1 - Lab Assignment
 * Title: Infix, Prefix, and Postfix
 * Coded by: Franki Micheo on January 4th, 2019
 * Requirements:
    * Write a C++ program that will do the following:

    -Ask the user to enter the option to pick between infix, prefix, or postfix.
    -Allow the user to enter a mathematical expression per the option above.
    -Allow the user to enter the option to pick between infix, prefix, or postfix.
    -Ensure that the user does not pick the same exact option again.
    -Validate that the expression entered is correct per the option picked in step 1.
    -Evaluate the expression entered per the option selected in step 1.
    -Display the value produced in the above step.
    -Convert the expression to be represented per the option picked in step 3.
    -Display the new expression after being converted in the above step.
    -Evaluate the expression after being converted.
    -Display the value produced in the above step.

 */

#include <cstdlib>
#include <iostream>
#include <stack>
#include <string>
#include <array>
#include <stdlib.h>
#include <stdio.h>


using namespace std;

//Functions and methods used.
void Header();
void DrawLine(int n);
void RefreshScreen();
void AvailableOptions(int n);
void InputInfix(stack<string> &e);
void InputPrefix(stack<string> &e);
void InputPostfix(stack<string> &e);
void OutputInfix(stack<string> e, int n);
void OutputPrefix(stack<string> e, int n);
void OutputPostfix(stack<string> e, int n);
double Sum(double num1, double num2);
double Sub(double num1, double num2);
double Mult(double num1, double num2);
double Div(double num1, double num2);
void EvaluateExpression(double a, double b, string c);
bool isOperand(string n);
bool isOperator(string n);


//Main method
int main() {
    
    //Variables
    string selection;  //Variable to hold input selections
    stack<string> equation;  //stack to hold the equation on the main method
    int option = 0;  //variable to hold the integer value of a selection
    
    //Program Start
    START:  //label to return to the beginning.
    RefreshScreen(); //clear the screen

    //Provide menu
    cout << "\n\nWhich type of equation would you like to enter (Input)?" << endl;
    AvailableOptions(0); //Default Options. '0' indicates that none of the options have been used.
    cout << "Please make a selection: ";
    cin >> selection;
    
    //Convert the selection to integer to use a switch/case for the options
    option = stoi(selection);
    
    switch(option){
        case 1: //Input is INFIX
            InputInfix(equation);
            OUT1:  //label to restart if the user enters an invalid selection
            cout << "Select a type of equation for conversion (Output): " << endl;
            AvailableOptions(1); //Indicates that the infix has been used
            cout << "Please make a selection: ";
            cin >> option;
            
            //Convert from INFIX to PREFIX
            if(option == 1){
                OutputPrefix(equation, 1); 
            }
            
            //Convert from INFIX to POSTFIX
            else if(option == 2){
                OutputPostfix(equation, 1);
            }
            else{
                goto OUT1; //Go back if selection is not 1 or 2
            }
            break;
        case 2: //Input is PREFIX
            InputPrefix(equation);
            OUT2: 
            cout << "Select a type of equation for conversion (Output): " << endl;
            AvailableOptions(2); //indicates that prefix has been used
            cout << "Please make a selection: ";
            cin >> option;
            
            //Convert from PREFIX to INFIX
            if(option == 1){
                OutputInfix(equation, 1);
            }
            
            //Convert from PREFIX to POSTFIX
            else if(option == 2){
                OutputPostfix(equation, 2);
            }
            else{
                goto OUT2;
            }
            break;
        case 3: //Input is POSTFIX
            InputPostfix(equation);
            OUT3:
            cout << "Select a type of equation for conversion (Output): " << endl;
            AvailableOptions(3);  //indicates that postfix has been used
            cout << "Please make a selection: ";
            cin >> option;
            
            //Convert from POSTFIX to INFIX
            if(option == 1){
                OutputInfix(equation, 2);
            }
            
            //Convert from POSTFIX to PREFIX
            else if(option == 2){
                OutputPrefix(equation, 2);
            }
            else{
                goto OUT3;
            }
            break;
        default:
            cout << "\nThis is an invalid selection! Please enter 1, 2, or 3.";
            break;
    }
    
    cout << "\nWould you like to start again? <Y or N>: ";  //Prompt to start over
    cin >> selection;
    
    //Check if the user enters Y or y. Otherwise, end the program.
    if(selection == "y" || selection == "Y"){
        goto START;
    }
    else{
        cout << "Bye!";
    }
    return 0;
}

//Methods

//Header of the program.
void Header(){
    DrawLine(40);
    cout << "\tModule 1 - Lab Assignment\n\tInfix, Prefix, and Postfix\n";
    DrawLine(40);
}


//Draw a line of variable size
void DrawLine(int n){
    for(int i = 0; i < n; i++){
        cout << "*";
    }
    cout << endl;
}

//Clear the screen and redraw the header
void RefreshScreen(){
    
    system("clear");
    
    Header();
}

//Display menu based on the selections made
void AvailableOptions(int n){
       
    switch(n){
        case 1: //INFIX
            cout << "\t1 - PREFIX\n\t2 - POSTFIX\n";
            break;
        case 2: //PREFIX
            cout << "\t1 - INFIX\n\t2 - POSTFIX\n";
            break;
        case 3: //POSTFIX
            cout << "\t1 - INFIX\n\t2 - PREFIX\n";
            break;
        default: //NOTHING
            cout << "\t1 - INFIX\n\t2 - PREFIX\n\t3 - POSTFIX\n";
            break;
    }
   
        
}

//Infix input dialog
void InputInfix(stack<string> &e){
    string input;
    
    //Label to go back and redo if the input format is not valid.
    INFIX:
    
    bool isValid = true;
    RefreshScreen();
    
    cout << "\nEnter the first operand: ";
    cin >> input;
    if(isOperand(input)){
        e.push(input);
    }
    else{
        isValid = false;
        cout << "This is not an operand... \n";
    }
    
    
    cout << "Enter the operator (+, -, *, or /): ";
    cin >> input;
    if(isOperator(input)){
        e.push(input);
    }
    else{
        isValid = false;
        cout << "This is not an operator...\n";
                
    }
    
    
    cout << "Enter the second operand: ";
    cin >> input;
   if(isOperand(input)){
        e.push(input);
    }
    else{
        isValid = false;
        cout << "This is not an operand...\n ";
    }
    
    if(!isValid){
        goto INFIX;
    }
    
    
    RefreshScreen();
}

//Prefix input dialog
void InputPrefix(stack<string> &e){
    string input;
    
    PREFIX:
    bool isValid = true;       
    RefreshScreen();

    cout << "\nEnter the operator (+, -, *, or /): ";
    cin >> input;
    if(isOperator(input)){
        e.push(input);
    }
    else{
        isValid = false;
        cout << "This is not an operator...\n";
                
    }
   
    cout << "Enter the first operand: ";
    cin >> input;
    if(isOperand(input)){
        e.push(input);
    }
    else{
        isValid = false;
        cout << "This is not an operand... \n";
    }
    
    cout << "Enter the second operand: ";
    cin >> input;
    if(isOperand(input)){
        e.push(input);
    }
    else{
        isValid = false;
        cout << "This is not an operand... \n";
    }
    
    
    if(!isValid){
        goto PREFIX;
    }
    
    RefreshScreen();
}

//Postfix input dialog
void InputPostfix(stack<string> &e){
    string input;
    
    POSTFIX:
    bool isValid = true;
    
    RefreshScreen();
  
    cout << "\nEnter the first operand: ";
    cin >> input;
    if(isOperand(input)){
        e.push(input);
    }
    else{
        isValid = false;
        cout << "This is not an operand... \n";
    }
    
    cout << "Enter the second operand: ";
    cin >> input;
    if(isOperand(input)){
        e.push(input);
    }
    else{
        isValid = false;
        cout << "This is not an operand... \n";
    }

    cout << "Enter the operator (+, -, *, or /): ";
    cin >> input;
    if(isOperator(input)){
        e.push(input);
    }
    else{
        isValid = false;
        cout << "This is not an operator...\n";
                
    }
    
    
    if(!isValid){
        goto POSTFIX;
    }
    
    RefreshScreen();
}

//Infix output dialog
void OutputInfix(stack<string> e, int n){
    double operand1, operand2;
    string Operator;
    
    switch(n){
        case 1: //Input was PREFIX
            operand2 = stod(e.top());
            e.pop();
            operand1 = stod(e.top());
            e.pop();
            Operator = e.top();
            e.pop();
            EvaluateExpression(operand1, operand2, Operator);
            cout << "\nThis expression is in Infix form.";
            break;
        case 2: //Input was POSTFIX
            Operator = e.top();
            e.pop();
            operand2 = stod(e.top());
            e.pop();
            operand1 = stod(e.top());
            e.pop();
            EvaluateExpression(operand1, operand2, Operator);
            cout << "\nThis expression is in Infix form.";
            break;
    }
}

//Prefix output dialog
void OutputPrefix(stack<string> e, int n){
    double operand1, operand2;
    string Operator;
    
    switch(n){
        case 1: //Input was INFIX 
            operand2 = stod(e.top());
            e.pop();
            Operator = e.top();
            e.pop();
            operand1 = stod(e.top());
            e.pop();
            EvaluateExpression(operand1, operand2, Operator);
            cout << "\nPrefix form: " << Operator << " " << operand1 << " " << operand2 << endl;
            break;
        case 2: //Input was POSTFIX
            Operator = e.top();
            e.pop();
            operand2 = stod(e.top());
            e.pop();
            operand1 = stod(e.top());
            e.pop();
            EvaluateExpression(operand1, operand2, Operator);
            cout << "\nPrefix form: " << Operator << " " << operand1 << " " << operand2 << endl;
            break;
    }
}

//Postfix output dialog
void OutputPostfix(stack<string> e, int n){
    double operand1, operand2;
    string Operator;
    
    switch(n){
        case 1: //Input was INFIX 
            operand2 = stod(e.top());
            e.pop();
            Operator = e.top();
            e.pop();
            operand1 = stod(e.top());
            e.pop();
            EvaluateExpression(operand1, operand2, Operator);
            cout << "\nPostfix form: " << operand1 << " " << operand2 << " " << Operator << endl; 
            break;
        case 2: //Input was PREFIX
            operand2 = stod(e.top());
            e.pop();
            operand1 = stod(e.top());
            e.pop();
            Operator = e.top();
            e.pop();
            EvaluateExpression(operand1, operand2, Operator);
            cout << "\nPostfix form: " << operand1 << " " << operand2 << " " << Operator << endl; 
            break;
    }
}

//Function to perform addition
double Sum(double num1, double num2){
    return num1 + num2;
}

//Function to perform subtraction
double Sub(double num1, double num2){
    return num1 - num2;
}

//Function to perform multiplication
double Mult(double num1, double num2){
    return num1 * num2;
}

//Function to perform division
double Div(double num1, double num2){
    return num1 / num2;
}

//Method to evaluate the expressions
void EvaluateExpression(double a, double b, string c){
    double result;
    
    if(c == "+"){
        result = Sum(a,b);  
    }
    else if(c == "-"){
        result = Sub(a,b);
    }
    else if(c == "*"){
        result = Mult(a,b);
    }
    else if(c == "/"){
        result = Div(a,b);
    }
    
    cout << "\nExpression: " << a << " " << c << " " << b << " = " << result;
}

//Function to test if the input is an operand (number)
bool isOperand(string n){
    bool isNumber = false;
    
    for(int i = 0; i < n.size(); i++){
        if(int(n[i]) > 65 && int(n[i]) < 122){
            isNumber = false;
        }
        else if(isOperator(n)){
            isNumber = false;
        }
        else{
            isNumber = true;
        }
    }
    
    return isNumber;
    
     
}

//Function to test if the input is an operator: +,-,*,/
bool isOperator(string n){
    if(n == "+" || n == "-" || n == "*" || n=="/"){
        return true;
    }
    else{
        return false;
    }
}