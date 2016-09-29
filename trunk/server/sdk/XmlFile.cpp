#include "XmlFile.h"

bool XmlFile::InitXml(const char *fileName)
{

	if(fileName == nullptr){
		return false;
	}

	if(_doc != NULL){
		xmlFreeDoc(_doc);
	}
	_doc = xmlParseFile(fileName);

	if(_doc == nullptr){
		return false;
	}

	return true;
};


xmlNodePtr XmlFile::GetRootElement()
{
	CHECK_NULL_RETURN(_doc);


	return xmlDocGetRootElement(_doc);
}

xmlNodePtr XmlFile::GetChildNode(const xmlNodePtr node,const char* name)
{
	if(node == nullptr){
		return nullptr;
	}
	xmlNodePtr cur = node->xmlChildrenNode;
	do{
		if(cur == nullptr){
			break;
		}
	
		if(!xmlStrcmp(cur->name,reinterpret_cast<const xmlChar*>(name)))	
		{
			return cur;	
		}
	
	
		cur = cur->next;
	
	}while(true);

	return nullptr;

}

xmlNodePtr XmlFile::GetRootElement(const char* name)
{

		CHECK_NULL_RETURN(_doc);
		_cur = xmlDocGetRootElement(_doc);

		CHECK_NULL_RETURN(_cur);
		
		do
		{
			if(!xmlStrcmp(_cur->name, reinterpret_cast <const xmlChar*>(name))){
					return _cur;
			}

			 _cur = _cur->xmlChildrenNode;

			 if(_cur == nullptr){
				 break;
			 }
		}while(true);


	return nullptr;
}


xmlNodePtr XmlFile::GetNodeElement(const xmlNodePtr node,const char*name)
{
	xmlNodePtr cur = node;

	do{
		if(cur == nullptr){
			break;
		}
	

		if(!xmlStrcmp(cur->name,reinterpret_cast<const xmlChar*>(name))){
			return cur;
		}
	cur = cur->next;	
	}while(true);



	return nullptr;


}

void XmlFile::GetNodeElement(const xmlNodePtr node,const char*name,DWORD&value,DWORD defaultValue )
{

	xmlNodePtr cur = node;

	do{
		if(cur == nullptr){
			break;
		}
	

		if(!xmlStrcmp(cur->name,reinterpret_cast<const xmlChar*>(name))){
			 value = atoi(reinterpret_cast<const char*>(xmlNodeGetContent(cur)));
		}
	cur = cur->next;	
	}while(true);



	value = defaultValue;

}



void XmlFile::GetNodeElement(const xmlNodePtr node,const char*name,std::string&value,std::string defaultValue)
{

	xmlNodePtr cur = node;

	do{
		if(cur == nullptr){
			break;
		}
	

		if(!xmlStrcmp(cur->name,reinterpret_cast<const xmlChar*>(name))){
			 value = reinterpret_cast<const char*>(xmlNodeGetContent(cur));
		}
	cur = cur->next;	
	}while(true);

	value = defaultValue;

}
xmlNodePtr XmlFile::GetNext(xmlNodePtr node)
{

	CHECK_NULL_RETURN(node);
	return node->next;

}