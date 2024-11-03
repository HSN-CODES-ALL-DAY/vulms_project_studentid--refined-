#include "student.hpp"

studentid::studentid(const std::string &id,const std::string &name) : eid (id), lengths(eid.size()),ename(name){}
    bool studentid::errorstate() const {
    return alphabeticalpart().size() > 3;
    }
    std::string studentid::student()const{
      return eid;
}

std::string studentid::numaricalpart()const{
      std::string numaricalpart;
      for(char ch : eid){
        if (isdigit(ch))
         numaricalpart+=ch;
      }
      return numaricalpart;
}

std::string studentid::alphabeticalpart()const{
      std::string alphabeticalpart;
      
      for(char ch : eid){
        if (isalpha(ch))
         alphabeticalpart+=ch;
      }
      return alphabeticalpart;
    }
    int studentid::length()const{
      return lengths;
}

std::string studentid::names()const{
    return ename;
}

std::string studentid::firstname(const std::string &namess) const{
    size_t spacepos = ename.find(' ');
    return ename.substr(0,spacepos);
}

std::string studentid::lastname(const std::string &namess) const{
    size_t spacePos = ename.rfind(' ');
    return (spacePos != std::string::npos) ? ename.substr(spacePos + 1, ename.size()) : "No Last Name";
}

