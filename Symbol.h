//
// Created by Carlos A. Fernández on 28/08/2016.
// Symbol.h on 02:10 PM 
// Copyright (c) 2016 TK team. All rights reserved.
//
#ifndef LEXYCAL_ANALYZER_SYMBOL_H
#define LEXYCAL_ANALYZER_SYMBOL_H

#include <iostream>

enum{
    DIGIT = 1,
    INTEGER,
    REAL,
    ADDITION_OP,
    MULTIPLICATION_OP,
    IDENTIFIER,
    PARENTHESIS,
    DELIMITER,
    LOGICAL_OP,
    RELATIONAL_OP,
    ARITHMETIC_OP,
    STRING,
    SPACE,
    ASSIGNMENT_OP,
    COMMA
};

std::string stringType(int type){
    switch(type){
        case REAL:return "REAL";
        case DIGIT:return"DIGIT";
        case SPACE:return "SPACE";
        case COMMA:return "COMMA";
        case STRING:return "STRING";
        case INTEGER:return"INTEGER";
        case ARITHMETIC_OP: return "ARITHMETIC_OP";
        case DELIMITER:return "DELIMITER";
        case IDENTIFIER:return "IDENTIFIER";
        case PARENTHESIS:return "PARENTHESIS";
        case LOGICAL_OP:return "LOGICAL_OP";
        case ADDITION_OP:return "ADDITION_OP";
        case ASSIGNMENT_OP:return "ASSIGNMENT_OP";
        case RELATIONAL_OP:return "RELATIONAL_OP";
        case MULTIPLICATION_OP:return "MULTIPLICATION_OP";
    }
}

class Symbol{
private:
    std::string content;
    int type;
public:
    Symbol(){}
    Symbol(std::string content,int type){
        setContent(content);
        setType(type);
    }
    ~Symbol(){}
    bool concatenateContent(char c){
        return setContent(getContent()+c);
    }
    bool concatenateContent(std::string s){
        return setContent(getContent()+s);
    }
    bool setContent(std::string content) {
        this->content = content;
        return true;
    }
    bool setContent(int content) {
        this->content = std::to_string(content);
        return true;
    }
    std::string getContent(){
        return content;
    }
    bool setType(int type){
        this->type=type;
        return true;
    }
    int getType(){
        return type;
    }
};

#endif //LEXYCAL_ANALYZER_SYMBOL_H
