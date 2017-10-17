#include<stdio.h>
#include<string>
#include<string.h>
#include <vector>
#include <map>
#include <iostream>
#include "Template.h"
#include<utility>
#include <typeinfo>
#include"Data.h"
using namespace std;


#define CheckVector CheckV




void f(int a,int b){};
void ff(const char*){};



class U{
    public:
 //       template<typename T>
//            typename std::conditional<true,typename enable_if<is_int<T>::value,void>::type,void>::type Add(){
//                cout<<"1"<<endl;
//            }
//typename std::conditional<CheckM<T>::value,
//         typename std::conditional<CheckV<typename T::mapped_type>::value,
//         typename std::enable_if<is_int<typename T::mapped_type::mapped_type>::value,void>::type,
//         void>::type,void>::type Add(){
//             cout<<"1"<<endl;
//         }
//
//
//
//    template<typename T>
//    typename std::conditional<CheckM<T>::value,
//             typename std::conditional<CheckV<typename T::mapped_type>::value,
//              typename std::enable_if<is_double<typename T::mapped_type::mapped_type>::value,void>::type,
//                void>::type,void>::type Add(){
//                cout<<"2"<<endl;
//    }
//
//    template<typename T>
//    typename std::conditional<CheckM<T>::value,
//             typename std::conditional<CheckM<typename T::mapped_type>::value,
//              typename std::enable_if<is_double<typename T::mapped_type::mapped_type>::value,void>::type,
//                void>::type,void>::type Add(){
//                cout<<"3"<<endl;
//            }
//

};

template<bool result,typename T,typename U> 
struct Condition{
    typedef T type;
};

template<typename T,typename U> 
struct Condition<false,T,U>{
};

class FC{
	public:
	//private:
	//void push_back(const int &);
	template<typename T>
	void   push_back(const T& __x);

	void Hash1Key();
};

template<typename T>
 void PrintType(T& obj)
{

    //for(   int i =0;i<ObjDepth<decltype(obj)>;i++)
    {
        cout<< typeid(DepthType<0,decltype(obj)>).name()<<endl;;
        cout<< typeid(DepthType<1,decltype(obj)>).name()<<endl;;
        cout<< typeid(DepthType<2,decltype(obj)>).name()<<endl;;
    }
}




int main()
{


    cout<<CheckParamConsis<decltype(f),int,const char*>::value<<endl;















//		std::vector<int> a;
//
//
//
//	cout<<"check push back " <<CheckPushBack<std::map<int,int>>::value<<endl;
//	cout<<"check push back " <<CheckInsert<std::map<int,int>, std::map<int,int>::value_type >::value<<endl;
//	cout<<"check push back " <<CheckPushBack<std::vector<int>,int>::value<<endl;
//	cout<<"check push back " <<CheckPushBack<FC>::value<<endl;
//	


















    //typename enable_if<true,enable_if<false,int>::type>::type  a = 10;
//    typename std::conditional<true,std::conditional<true,int,enable_if<false,void>>::type,int>::type a  = 10;


//     U u;
//     u.Add<std::map<int,std::map<int,int>>>();
//     u.Add<std::map<int,std::map<int,double>>>();
//

    ///using type1 =  std::map<int,std::vector<int>>::mapped_type;
    //cout<<typeid(type1).name()<<endl;
	smap<std::string,std::map<int,std::map<int,Npc>>> npcList;
	smap<std::string,std::map<int,Npc>> npcList2;
	smap<std::string,std::map<int,std::vector<Npc>>> npcList3;
	smap<std::string,std::vector<Npc>> npcList4;
	smap<std::string,Npc> npcList5;
	Npc npc;
	npc.name = "npc";
	npc.level = 11;
	npc.sex = 2;
	npcList.Push(npc);
	npcList2.Push(npc);

	npcList3.Push(npc);
	npcList4.Push(npc);
    npcList5.Push(npc);
    //cout<<is_containers<>::value<<endl;
    std::map<int ,int> fff;
    cout<< TypeDepth<decltype(npcList)>()<<endl;
    //std::map<int,std::map<int,int>> a;
    //cout<< typeid(typename DepthType<0,decltype(a)>::type).name()<<endl;;
   // typename DepthType<0,decltype(a)>::type ffa;
    cout<< typeid(DepthType<0,decltype(npcList)>::type).name()<<endl;;
    cout<< typeid(DepthType<1,decltype(npcList)>::type).name()<<endl;;
    cout<< typeid(DepthType<2,decltype(npcList)>::type).name()<<endl;;
    cout<< typeid(DepthType<3,decltype(npcList)>::type).name()<<endl;;
    cout<< TypeDepth<decltype(npcList2)>()<<endl;
    cout<< typeid(DepthType<0,decltype(npcList2)>::type).name()<<endl;;
    cout<< typeid(DepthType<1,decltype(npcList2)>::type).name()<<endl;;
    cout<< typeid(DepthType<2,decltype(npcList2)>::type).name()<<endl;;
    cout<< TypeDepth<decltype(npcList3)>()<<endl;
    cout<< TypeDepth<decltype(npcList4)>()<<endl;
    //PrintType(npcList4);





    return 0;

    //cout<<std::is_class<Npc>::value <<endl;
    //cout<<std::is_class<std::map<int,int>>::value <<endl;
	
	//typedef decltype(npcList)::_Base_iterator uuu ;

	for(auto it :npcList)
	{
		for(auto its:it.second)	
		{
			for(auto itt:its.second)
			{
				auto npc= itt.second;
				cout<<"name  = " <<npc.name.c_str()<<" level = "<<npc.level<<" sex="<<npc.sex<<endl;
                //npcList.Set(it->first(),its->first(),"level",1);
                //npcList.Del(its.second);
			}
		}
	}

	for(auto it :npcList)
	{
		for(auto its:it.second)	
		{
			for(auto itt:its.second)
			{
				auto npc= itt.second;
				cout<<"name  = " <<npc.name.c_str()<<" level = "<<npc.level<<" sex="<<npc.sex<<endl;
                //npcList.Set(it->first(),its->first(),"level",1);
                //npcList.Del(its.second);
			}
		}
	}	

    std::map<int,std::map<int,int>> m1;
    for(int i = 0;i<20;i++)
    {
        m1[i][i] = i*10;
    }

    for(std::map<int,std::map<int,int>>::iterator it = m1.begin() ;it!=m1.end();it++) 
    {
        for(auto its = it->second.begin();its != it->second.end();its++)
        {
            cout<<its->second<<endl;
            it->second.erase(its);
            cout<<typeid(its).name()<<endl;
        }
        m1.erase(it);
    }

for(auto it = m1.begin() ;it!=m1.end();it++) 
    {
        for(auto its = it->second.begin();its != it->second.end();its++)
        {
            cout<<its->second<<endl;
//            it->second.erase(its);
        }
    }




	for(auto it :npcList4)
	{
        for(auto its:it.second)	
        {
            auto npc = its;
            cout<<"name  = " <<npc.name.c_str()<<" level = "<<npc.level<<" sex ="<<npc.sex<<endl;
            //npcList.Set(it->first(),its->first(),"level",1);
            //npcList.Del(its);
        }
	}








	//smap<std::string,std::map<int,Npc>> npcList2;

	//npcList2.Push(npc);

	
//	for(auto it :npcList2)
//	{
//		for(auto its:it.second)	
//		{
//			auto npc= its.second;
//			cout<<"name  = " <<npc.name.c_str()<<" level = "<<npc.level<<" sex="<<npc.sex<<endl;
//		}
//	}


//	smap<std::string,Npc> npcList3;
//	npcList3.Push(npc);


//	std::map<std::vector<int>,std::vector<int>> f1;
//	std::map<std::vector<int>,std::map<int,std::vector<int>>> f2;
//
//	cout<<CheckMV<decltype(f1)>::value<<endl;
//	cout<<CheckMMV<decltype(f2)>::value<<endl;
//
//	smap<std::string,std::vector<Npc>> npcList4;
	
//

//	std::vector<int> a1;
//	a1.push_back(11);
//	a1.push_back(12);
//	a1.push_back(13);
//	std::vector<int> a2;
//	a2.push_back(112);
//	a2.push_back(113);
//	a2.push_back(114);
//	f1[a1] =a2;
//	std::vector<int> a3;
//	{	
//		auto it = f1.find(a3);
//		if(it!=f1.end())
//		{
//			cout<<"ssssss"<<endl;	
//		}
//	}



	//cout<<CanContinue<decltype(ff),bool,int>::value<<endl;

	//std::vector<std::map<int,int>> a;
	
	//cout<<CheckM<decltype(a)>::value<<endl;
	
//	std::map<int,std::map<int,int>> a;
//	cout<<CheckMMM<decltype(a)>::value<<endl;
//


    Friend f;
    smap<std::string,Friend>  f1;
    f1.Push(f);

    smap<std::string,std::map<int,Friend>>  f2;
    f2.Push(f);

    smap<std::string,std::vector<Friend>>  f3;
    f3.Push(f);


    User u;
    smap<std::string,User> u1;
    smap<std::string,std::vector<User>> u2;
    u1.Push(u);
    u2.Push(u);






#if 0
    cout<<is_int<int>::value<<endl;
    cout<<is_int<double>::value<<endl;

    Data data;
    data.InitAttrCallBack();
    data.SetLevel(10);
    data.SetAge(122);
    data.SetName("test");
    data.Set("level",11111);
    data.Set("age",11111);
    data.Set("name","uuuu");

    auto attrList = data.GetAttrList();
    for(auto it :attrList)
    {
        cout<<it.c_str()<<"="<<data.GetInt(it.c_str())<<endl;;
    }

   for(auto it :attrList)
    {
        cout<<it.c_str()<<"="<<data.GetStr(it.c_str())<<endl;;
    }


#endif























////cout<<CheckM<std::vector<std::string>>::value<<endl;
//cout<<CheckM<std::map<int,int>>::value<<endl;
//cout<<CheckM<std::vector<std::pair<int,int>>>::value<<endl;
//












//    cout<<CheckMV<std::map<int,std::vector<std::string>>>::value <<endl;
//
//    vector<int> a111;
//    cout<<typeid(a111).name()<<endl;
//
//
//
//    std::vector<std::string> ff;
//    std::map<int,int> fff;
//    cout<<CheckVector<decltype( ff)>::value<<endl;
//    cout<<CheckVector<decltype( fff)>::value<<endl;
//
//
//    typedef smap<std::string,smap<int,smap<int,Npc>>>  NPC;
//    NPC npcList;
//    Npc npc;
//    npc.name="npc";
//
//    typename enable_if<CheckVector<decltype(ff)>::value,int>::type a;
//    a = 10;
//

   // cout<<"xxx="<<HashFunc1<Npc>::value<<endl;
   // cout<<"xxx="<<HashFunc2<Npc>::value<<endl;
   // cout<<"xxx="<<HashFunc3<Npc>::value<<endl;
 //   npcList.Push(npc); 
 //   for(auto it:npcList)
 //   {
 //      cout<<"npc name"  <<it.second.begin()->second.begin()->second.name.c_str()<<endl;
 //   }


 //   smap<std::string ,User> userList;
 //   smap<std::string,std::vector<User>> userVec;
 //   smap<std::string ,smap<int,Friend> > f1;

 //   Friend f;
 //   f.name = "a";
 //   f.age = 10;

 //   User user;
 //   user.userName = "abc";
 //   userList.Push(user);

 //   f1.Push(f);

 //   userVec.Push(user);



 //   for(auto it:userList)
 //   {
 //       cout<<"name="<<it.second.userName.c_str()<<endl;
 //   
 //   }

 //   for(auto it:f1)
 //   {
 //       //cout<<"name="<<it.second.name.c_str()<<"  age="<<it.second.age<<endl;
 //       //
 //       cout<<"firstkey = "<<it.first.c_str()<<endl;;

 //       for(auto its:it.second){
 //           cout<<"second="<<its.first<<"\n"<<"id="<<its.second.id;
 //       }
 //   
 //   }








//    char buf [1023];
//    std::string str;
//   const  char*a = str.c_str();
//
//    memcpy(&buf,a,strlen(a)+1);
//


 //   printf("%s",buf);



    return 0;
}
