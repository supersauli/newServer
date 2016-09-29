

#include <stdio.h>
#include <iostream>
#include <memory>
//#include <libxml/parser.h>

#include <libxml/tree.h>
#include <libxml/parser.h>
using namespace std;

template<class R>
class FunctionAbstract;
template <class R>
class FunctionAbstract<R(*)()>
{
public:
	typedef  R (FuncType)();
	FunctionAbstract(R(*func)()) :_func(func) {};
	R Run() {
		return _func();
	}
private:
	 R(*_func)();

};


void myprintf(){

	cout<<"This is a  test"<<endl;

};

#include <iostream>
#include <tuple>
using namespace std;
template<class ...T>
struct sSize;

template<class T,class ...R>
struct sSize<T,R...>
{

		
		enum {
					size = sSize<R...>::size + 1,
						};
};

template<class T>
struct sSize<T> 
{
		enum {
					size = 1,
						};
};

void  fdfsf(int a ,int b,int c ){
}
;


enum class type1{a, b, c};
enum class type2{a, d, e};


//template<T>
//#define   Value(Type,Name) \
//Type  Name ; \
//const Type get(){return Name;} \
//void set(Type value){ Name = value;}
//

//#include <wctype.h>
//class M{
//
//	public:
//
//	//Value(int ,aa);
//	//
//	
//	property_rw<string> name = property_rw<string>(
//			property_setter(std::string)
//			{}
//			property_getter(std::string)
//			{
//				return "aaaa";
//			}
//			);
//	
//	private:
//};

void f1(void *)
{
	cout<<"1"<<endl;
};

void f1(int )
{
	cout<<"2"<<endl;
};

class A1{
	public:
		A1(int value): m(value){	
			m = 0;
		}
	void ff(){
		m++;
		cout<<m<<endl;

	};
	private:
	int m = 0;

};


template <class T> struct A {};
template <class T> struct B : A<T> {};

template <class T> void f(T &, const int &, int = 0) {std::cout << 1;}
template <class T> void f(A<T> &, const int &, int = 0) {std::cout << 2;}
template <class T> void f2(A<T> &, const int &) {std::cout << 3;}

template <typename T>
void delf1(T& f){
	f();
};

#include <stdlib.h>
#include <limits> 
#define NAME(x) #x,

#define PUSH(VALUE) \
static char *buf[] = {VALUE""};


static string getName(char *name){
	return string(name);
}

#include <random>

int main(int argc, char **argv){

	std::default_random_engine e;
	
	e.seed(time(nullptr));
	for(size_t i = 0;i<10;i++)
	{
			cout<<e()<<endl;
	}

	//整数
	std::uniform_int_distribution<unsigned> m1(0,9);
	for(int i =0 ;i<10;i++)
	{
		cout<<m1(e)<<endl;	
	
	}



	//实数
	std::uniform_real_distribution<double> m2(1,10);
	for(int i =0 ;i<10;i++)
	{
		cout<<m2(e)<<endl;	
	}






































/*

char *xmlFile = nullptr;
if(argc <= 1)
{
	return 0;	

}
xmlFile = argv[1];


auto parseDoc = [xmlFile]()->int
{

		xmlDocPtr doc;
		xmlNodePtr cur;
		doc = xmlParseFile(xmlFile);
		if(doc == nullptr)
		{
			printf("fffff\n");	
			return 0;	
		}

		cur = xmlDocGetRootElement(doc);
		if(cur == nullptr)
		{
			printf("empty xmlFile\n");	
		
			return 0;
		}

		if(xmlStrcmp(cur->name,(const xmlChar*)"story"))
		{
			printf("document of the wrong type,root node !=story");		;
			return 0;	
		}

		cur = cur->xmlChildrenNode;
		while(cur != NULL)
		{
				if(!xmlStrcmp(cur->name,(const xmlChar*)"storyinfo"))	
				{
					auto parseStory = [=](xmlDocPtr doc,xmlNodePtr cur)->void
					{
						xmlChar* key;
						cur=cur->xmlChildrenNode;
						while(cur != NULL)
						{

							if(!xmlStrcmp(cur->name,(const xmlChar*)"Keyword"))	{
								key = xmlNodeListGetString(doc,cur->xmlChildrenNode,1);
								printf("keyword:%s\n",key);
								xmlFree(key);
							}
							cur =cur->next;

						}

						return;

				 	};

					parseStory(doc,cur);					

				}
				cur = cur->next;
		}

		xmlFreeDoc(doc);	
		return 0 ;

};


parseDoc();















//
//	PUSH(NAME(f0)NAME(f1)NAME(f2));
//
//cout<<*buf<<endl;
//
//
//
//	std::function<void()> f1;
//
//	{
//		f1 = std::bind([](){cout<<"123"<<endl;});
//	
//	}
//
//	delf1(f1);
//
//
//
//









//	int a  = 111;
//	a = a>>1;
//	cout<<a<<endl;
//


//int doc;
//B<int> of;
//f2(of, doc);
//f(of, doc, 0);
//f((A<int> &)of, doc, 0); 



//	std::shared_ptr<A1> p1= std::make_shared<A1>(100);
//
//
//	p1 ->ff();
//	p1 ->ff();
//	p1 ->ff();
//	p1 ->ff();
//
//
//
//










//f1(0);
//f1(nullptr);

//	int m1[] = {1,2,3};
//	for(auto i : m1)
//	{
//		cout<<i<<endl;	
//	
//	};


//	M a;
//	a.set(1011);
//	cout<<a.get()<<endl;



//	cout <<sSize<int, int, int>::size << endl;
//FunctionAbstract<void> f;
//FunctionAbstract<void> f;
//	f = myprintf();
//	f.Run();
//
//
//
//
//
//
//
//
//
//
//
//
*/
	return 0;

}


