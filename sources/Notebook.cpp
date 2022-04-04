#include <iostream>
#include <string>
#include "Notebook.hpp"
using namespace ariel;
const int max_col = 100;
const int zero =0;
const int min_row =10;
const int min_col =10;

// first checks if the input is good then read it by its direction (in horizontal i can use substr because of the struct)
std::string Notebook::read(int page, int row,int col,Direction d,int len){
        if(row<zero||col<zero||page<zero||col>=max_col||len<zero){
            throw std::invalid_argument{"cant write to negative pages/cols/rows or to col bigger then 100"};
        }
        string ans;

        if(d == Direction::Horizontal){
            if(col+len > max_col){
                throw std::invalid_argument{"cant write outside the bounderies"};
            }
            ans = notebook_1[page][row].rows.substr((size_t)col, (size_t)len);
        }

        else{
            for (int i = row; i < row+len; i++){
                ans+=notebook_1[page][i].rows[(size_t)col];
            }
        }

        return ans;
    }
    //changes the max row of a page
void Notebook::change_max(int row,int page){
    max_row[page]=row;
}    

//first checks the inputs then if its writable then write in for loop
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
        //check if need to change the max col/row and change it if so.
        if(max_row[page]<row+(int)s.length()&&d==Direction::Vertical){
            change_max(row+(int)s.length(),page);
        }
        if(max_row[page]<row){
            change_max(row,page);
        }
        if(max_cole[page]<col+(int)s.length()&&d==Direction::Horizontal){
            max_cole[page]=col+(int)s.length();
        }
        if(max_cole[page]<col){
            max_cole[page]=col;
        }
        
    }
    //returns the max row but if the max is smaller then 10 returns 10.
int Notebook::check_max(int page){
    int ans=0;
    if(max_row[page]<=0){
        ans = min_row;
    }
    else{
        ans = max_row[page];
    }
    return ans;
}
//returns the max col but if the max is smaller then 10 returns 10.
int Notebook::check_max_col(int page){
    int ans=0;
    if(max_cole[page]<=min_col){
        ans = min_col;
    }
    else{
        ans = max_cole[page];
    }
    return ans;
}        
//gets max row and col and prints each row
void Notebook::show(int page){
    if(page<zero){
        throw std::invalid_argument{"cant show to negative pages"};

    }
    int max_r = check_max(page);
    int max_c = check_max_col(page);
    cout<<"             page number is :         "<<page<<endl;
    for (size_t i = 0; i <= max_r; i++)
    {
       cout<<"row"<<i+1<<" :"<<notebook_1[page][i].rows.substr((size_t)zero, (size_t)max_c)<<endl;
       cout<<"\n"<<endl;
        
    }
    

    }
    //check valid inputs and earase (replace it with ~ ) the chossen location
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
        
    // check there arent /n /t etc.
int Notebook::is_legit(const string &s){
        int count = 0;
        for(char c : s){
            if((isprint(c)!=0)&&(c!='~')){
                count++;
            }

        }
        return count;
    }

int main(int argc, char const *argv[])
{
  ariel::Notebook notebook;
    notebook.write(1, 2, 2, Direction::Horizontal, "Nadav");
    notebook.write(1, 4, 15, Direction::Horizontal, "Yosii");
    notebook.write(1, 6, 18, Direction::Horizontal, "Hello");
    notebook.write(1, 14, 85, Direction::Horizontal, "Makore");
    notebook.write(1, 16, 88, Direction::Horizontal, "Shalom");
    notebook.write(1, 7, 15, Direction::Vertical, "Yalla");
    notebook.write(1, 21, 56, Direction::Vertical, "Cppc++");
    notebook.write(1, 31, 31, Direction::Vertical, "Mishma");
    notebook.write(1, 34, 38, Direction::Vertical, "TryThis");
    notebook.show(1);
    notebook.show(2);
    notebook.erase(1,34,38,Direction::Vertical,7);
    notebook.show(1);
    return 0;
}
