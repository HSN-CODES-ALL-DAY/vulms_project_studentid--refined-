#include <iostream>
#include "student.hpp"


int main(int argc,const char* argv[]){

  std::string student = "bc240411700";
  std::string name = "Muhammad Hassaan";
  bool iname=0;
  bool istudent=0;
  //argument logic 
  if (argc>=2){
    for(int i = 1; i < argc;i++){
      std::string argument = argv[i];
      if (argument=="-id"&&i<argc-1){
        student=argv[i+1];
        istudent = 1;
        i++;
      }
      else if (argument=="-n"&&i<argc-1){
        name=argv[i+1];
        iname = 1;
        i++;
      }
      else if(argument=="-h"){
        std::cout<<"to get user input prompt use -p,\nto input using command line argument use -id {student id}to input id,use -n {name} to input name, you have to use both -id and -n else the program will give an error,\n";
        return 0;
      }
      else if (argument=="-p"){
        std::cout<<"input your name :";
        std::getline (std::cin,name);
        std::cout<<"input your id :";
        std::getline (std::cin,student);
      }
      else {
      std::cerr << "Invalid argument use -h for help\n";
      return -1;
      }    
    }
  }
  //error checking 
  if (iname!=istudent){
    std::cerr << "please input both id and name use -h for help\n";
    return 5;
  }

  if (student.size()<4){
      std::cerr << "student id cannot be less than 4 characters\n";
      return 2;
  }
  
  studentid hsn = {student,name};
  if (hsn.errorstate()){
    std::cerr<<"studentid cannot have more than 3 alphabets\n";
    return 3;
  }
  
  std::cout<<"Student name: "<<hsn.names()<<"\n";
  std::cout<<"First name: "<<hsn.firstname(hsn.names())<<"\n";
  std::cout<<"Last name: "<<hsn.lastname(hsn.names())<<"\n";
  std::cout<<"Student ID: "<<hsn.student()<<"\n";
  std::cout<<"Aplhabetical part: "<<hsn.alphabeticalpart()<<"\n";
  std::cout<<"Numarical part: "<<hsn.numaricalpart()<<"\n";
  std::cout<<"size: "<<hsn.length()<<"\n";
    
  #if _WIN32
  std::cout<<":S\n";
  #endif
  return 0;
}
