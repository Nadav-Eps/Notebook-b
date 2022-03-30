#include <iostream>
#include <string>
#include "Notebook.hpp"
using namespace ariel;
const int max_col = 100;
const int zero =0;


std::string Notebook::read(int page, int row,int col,Direction d,int len){
        if(row<zero||col<zero||page<zero||col>=max_col||len<zero){
            throw std::invalid_argument{"cant write to negative pages/cols/rows or to col bigger then 100"};
        }
        string ans;

        if(d == Direction::Horizontal){
            if(col+len > max_col){
                throw std::invalid_argument{"cant write outside the bounderies"};
            }
            // for (int i = col; i < col+len; i++){
            //     ans+=notebook_1[page][row].rows[(size_t)i];
            // }
            ans = notebook_1[page][row].rows.substr((size_t)col, (size_t)len);
        }

        else{
            for (int i = row; i < row+len; i++){
                ans+=notebook_1[page][i].rows[(size_t)col];
            }
        }

        return ans;
    }
void Notebook::write(int page, int row, int col, Direction d,const string  &s){

        if(s.length()!=is_legit(s)){
            throw std::invalid_argument{"cant write unprinted chars"};
        }
        if(row<zero||col<zero||page<zero||col>max_col){
            throw std::invalid_argument{"cant write to negative pages/cols/rows"};
        }
        if (d == Direction::Horizontal){
            if(col+(int)s.length()>=max_col){throw std::invalid_argument{"cant write outside the bounderies"};}
            
                for (int i = col; i < col+(int)s.length(); i++)
                {
                    if(notebook_1[page][row].rows[(size_t)i] == '_'){
                       
                    }
                    else{
                         throw std::invalid_argument{"cant write because this place is already written"};
                    }
                }
                 for (int i = col; i < col+(int)s.length(); i++)
                {
                        notebook_1[page][row].rows[(size_t)i] = s[(size_t)(i-col)];
                    
                }
                
       }

        else{
            for (int i = row; i < row+(int)s.length(); i++)
                {
                    if(notebook_1[page][i].rows[(size_t)col] == '_'){
                        
                    }
                    else{
                         throw std::invalid_argument{"cant write because this place is already written"};
                    }
                    
                    
                }
                for (int i = row; i < row+(int)s.length(); i++)
                {
                        notebook_1[page][i].rows[(size_t)col] = s[(size_t)(i-row)];
                    
                }

        }
        
    }
void Notebook::show(int page){
    if(page<zero){
        throw std::invalid_argument{"cant show to negative pages"};
    }

    }
void Notebook::erase(int page, int row,int col,Direction d,int len){
        if(row<zero||col<zero||page<zero||col>=max_col||len<zero){
            throw std::invalid_argument{"cant write to negative pages/cols/rows"};
        }
        if (d == Direction::Horizontal){
            if(col+len>max_col){throw std::invalid_argument{"cant write outside the bounderies"};}
            
                for (int i = col; i < col+(int)len; i++)
                {
                        notebook_1[page][row].rows[(size_t)i] = '~';
                }
                
       }

        else{
            for (int i = row; i < row+(int)len; i++)
                {
                    notebook_1[page][i].rows[(size_t)col] = '~';
                }
            }

        }
        
    
int Notebook::is_legit(const string &s){
        int count = 0;
        for(char c : s){
            if((isprint(c)!=0)&&(c!='~')){
                count++;
            }

        }
        return count;
    }
