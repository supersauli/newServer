#ifndef __XML_FILE_H__
#define __XML_FILE_H__
#include "sDefine.h"
#include <libxml/tree.h>
#include <libxml/parser.h>
#include <string>
class XmlFile
{

	public:
		~XmlFile(){
			if(_doc != nullptr){
				xmlFreeDoc(_doc);
			}

		};
		bool InitXml(const char *fileName);

		xmlNodePtr GetRootElement();
		xmlNodePtr GetRootElement(const char* name);
		xmlNodePtr GetChildNode(const xmlNodePtr node,const char* name);
		xmlNodePtr GetNodeElement(const xmlNodePtr node,const char*name);
		void GetNodeElement(const xmlNodePtr node,const char*name,DWORD&value,DWORD defaultValue = 0 );
		void GetNodeElement(const xmlNodePtr node,const char*name,std::string&value,std::string defaultValue = "");


		xmlNodePtr GetNext(xmlNodePtr node);

	private:

		xmlDocPtr _doc{nullptr};
		xmlNodePtr _cur{nullptr};

};


#endif
