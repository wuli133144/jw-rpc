
#ifndef USER_H
#define USER_H

//user model 
//

class userinfo
{
public:

   userinfo();
   userinfo(string name,int _age,string portraits="",string sch=""):user_name(name),age(_age),portrait_url(portraits),school(sch)
   {
   }
   ~userinfo();
   void setusername(string name);
   string getusername();

   void setage(int _age);
   int getage()const ;
   
   void setportraitsurl(string portrait);
   string getportraitsurl()const;

   void setschool(string _school);
   string getschool()const;


private:

	string user_name;
	int age;
	string portrait_url;
	string school;

}






#endif // USER_H


