//
// Created by Carlos A. Fernández on 28/08/2016.
// main.cpp on 06:10 PM
// Copyright (c) 2016 TK team. All rights reserved.
//
#include <iostream>
#include "SyntacticAnalyzer.h"

int main(){
    std::ifstream in_file("entrada.txt");
    std::ofstream out_file("salida.txt");
    LexycalAnalyzer lexycalAnalyzer(in_file);
    SyntacticAnalyzer syntacticAnalyzer(&lexycalAnalyzer);
    std::cout<<syntacticAnalyzer.analyze()<<std::endl;
    /*try{
        std::cout<<syntacticAnalyzer.analyze()<<std::endl;
        std::cout<<"1"<<std::endl;
        out_file<<"1";
    }catch(SintaxException& e){
        e.getMessage();
        std::cout<<"0"<<std::endl;
        out_file<<"0";
    }*/
    return 0;
}