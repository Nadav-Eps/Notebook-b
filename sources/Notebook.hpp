#include <iostream>
#include <string>
#include "Direction.hpp"
#include <map>
#include <unordered_map>
#include <stdlib.h>
#include <stdexcept>
using namespace std;
const int maxi = 100;

namespace ariel {
   class Notebook{

      struct rowe{
         string rows = string(maxi,'_');
                 };
    private :
        map<int , int> max_row;
        map<int , int> max_cole; 
        unordered_map <int,map<int,rowe>> notebook_1;


    public :

      std::string read(int page ,int row,int col,Direction d,int len);
      void write(int page, int row, int col, Direction d,const std::string &s);
      void erase(int page ,int row,int col,Direction d,int len);
      static int is_legit(const std::string &s);
      void show(int page);
      void change_max(int row,int page);
      int check_max(int page);
      int check_max_col(int page);
            };
   };