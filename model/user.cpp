//model.cpp
//test jw-rpc



#include "user.h"

userinfo::userinfo(){}
userinfo::~userinfo(){}


void userinfo::setusername(string name)
{
	 user_name=name;
}

string userinfo::getusername()const 
{

    return  user_name;
}

void userinfo::setage(int _age)
{
     age=_age;
}

int userinfo::getage()
{
    return age;
}

void userinfo::setschool(string ch)
{
    school=ch;
}

string userinfo::setschool()const
{

  return school;
  
}


string userinfo::getportraits_url(string url)const
{
   portrait_url=url;
}

void userinfo::setportraits_url()
{
  return portrait_url;
}









