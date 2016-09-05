//
// Created by Carlos A. Fernández on 04/09/2016.
// SyntacticAnalyzer.h on 09:50 AM 
// Copyright (c) 2016 TK team. All rights reserved.
//

#ifndef SYNTACTIC_ANALYZER_SYNTACTICANALYZER_H
#define SYNTACTIC_ANALYZER_SYNTACTICANALYZER_H
#include "LexycalAnalyzer.h"

class SyntacticAnalyzer{
private:
    LexycalAnalyzer* lexycalAnalyzer;
    std::string error;
    bool is_error;
    bool is_current_symbol(std::string symbol){
        return lexycalAnalyzer->get_current_symbol()->getContent().compare(symbol)==0;
    }
    bool set_lexycal_analyzer(LexycalAnalyzer* lexycalAnalyzer){
        if(lexycalAnalyzer!= nullptr){
            this->lexycalAnalyzer=lexycalAnalyzer;
            return true;
        }
        else{
            return false;
        }
    }
    void comprueba(std::string symbol){
        //std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
        if((lexycalAnalyzer->get_current_symbol()->getContent().compare(symbol)==0)) {
            //std::cout<<"Current: "<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
            lexycalAnalyzer->next_symbol();
            //std::cout<<"ENTRE"<<std::endl;
        }
        else{
            std::cout<<"NOOO"<<std::endl;

            is_error=true;

        }
        //if simbolo es igual al simbolo
        //consumir
        //contrario error
    }/*
    void A(){
        std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
        if(lexycalAnalyzer->get_current_symbol()->getType()==IDENTIFIER){
            lexycalAnalyzer->next_symbol();
            std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
            B();
        }
    }

    void B(){
        if(is_current_symbol("=")){
            lexycalAnalyzer->next_symbol();
            std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
            C();
            std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
            comprueba(";");
            A();
        }else{
            std::cout<<"YEI"<<std::endl;
            lexycalAnalyzer->next_symbol();
            std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
            D();
        }
    }
    void C(){
        if(is_current_symbol("(")){
            lexycalAnalyzer->next_symbol();
            std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
            C();

            std::cout<<"NEL"<<std::endl;
            comprueba(")");
        }else{ lexycalAnalyzer->next_symbol();}
    }

    void D(){
        std::cout<<"DOBLE YEI"<<std::endl;
        if(is_current_symbol("(")){
            std::cout<<"TRIPLE YEI"<<std::endl;
            lexycalAnalyzer->next_symbol();
            comprueba(")");
            comprueba(";");
            A();
        }
    }*/

    bool A(){
        if(lexycalAnalyzer->get_current_symbol()->getType()==IDENTIFIER){
            //std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
            lexycalAnalyzer->next_symbol();
            if(is_current_symbol("=")){
               // std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;

                lexycalAnalyzer->next_symbol();
                if(is_current_symbol("(")){
                    //std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;

                    lexycalAnalyzer->next_symbol();

                    B();
                    if(is_current_symbol(")")){
                        lexycalAnalyzer->next_symbol();
                        //std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;

                        if(is_current_symbol(";")) {
                            lexycalAnalyzer->next_symbol();
                            //std::cout<<"AF: "<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
                            //if(lexycalAnalyzer->get_current_symbol()->getContent()=="\n") lexycalAnalyzer->next_symbol();
                            //std::cout<<"AF: "<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
                        }else{
                            is_error=true;
                            error+="falta ;\n";
                        }
                    }
                    else{
                        is_error=true;

                        error+="falta un )\n";
                    }
                }
                else{
                    is_error=true;

                    error+="falta (\n";
                }

            }else
                if(is_current_symbol("(")){
                    //std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;

                    lexycalAnalyzer->next_symbol();

                    B();
                    if(is_current_symbol(")")){
                        lexycalAnalyzer->next_symbol();
                        //std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;

                        if(is_current_symbol(";")) {
                            //std::cout<<"QUE?"<<std::endl;
                            lexycalAnalyzer->next_symbol();
                            //std::cout<<"AF: "<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
                            //if(lexycalAnalyzer->get_current_symbol()->getContent()=="\n") lexycalAnalyzer->next_symbol();
                            //std::cout<<"AF: "<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
                        }else{
                            is_error=true;

                            error+="falta ;\n";
                        }
                    }
                    else{
                        is_error=true;

                        error+="falta un )\n";
                    }
                }
                else{
                    is_error=true;

                    error+="falta (\n";
                }
            A();
        }
        //std::cout<<"LLEGO AQUI"<<std::endl;

    }
    void B(){
        //std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;
        if(is_current_symbol("(")){
            //cout<<"s:("<<endl;
            lexycalAnalyzer->next_symbol();
            B();
            if(is_current_symbol(")")){
                //std::cout<<lexycalAnalyzer->get_current_symbol()->getContent()<<std::endl;

                //cout<<"s:)"<<endl;
                lexycalAnalyzer->next_symbol();
            }
            else{
                //cout<<"ERROR"<<endl;
                is_error=true;

                error+="falta un )\n";
            }
        }
    }
public:
    SyntacticAnalyzer(LexycalAnalyzer* lexycalAnalyzer){
        set_lexycal_analyzer(lexycalAnalyzer);
        error="";
        is_error=false;
    }
    bool analyze(){
        lexycalAnalyzer->next_symbol();
        A();
        comprueba("$");
        return !is_error;
    }
};
#endif //SYNTACTIC_ANALYZER_SYNTACTICANALYZER_H
