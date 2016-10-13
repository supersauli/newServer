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

		/**
		 * @brief 获得根节点
		 *
		 * @return 
		 */
		xmlNodePtr GetRootElement();
		/**
		 * @brief 获得当前名字的根节点
		 *
		 * @param name
		 *
		 * @return 
		 */
		xmlNodePtr GetRootElement(const char* name);

		/**
		 * @brief 获得子节点
		 *
		 * @param node
		 * @param name
		 *
		 * @return 
		 */
		xmlNodePtr GetChildNode(const xmlNodePtr node,const char* name);

		/**
		 * @brief 
		 *
		 * @param node
		 * @param name
		 *
		 * @return 
		 */
		xmlNodePtr GetNodeElement(const xmlNodePtr node,const char*name);

		/**
		 * @brief 过得根节点数据
		 *
		 * @param node
		 * @param name
		 * @param value
		 * @param defaultValue
		 */
		void GetNodeValue(const xmlNodePtr node,const char*name,DWORD&value,DWORD defaultValue = 0 );

		/**
		 * @brief 获得根节点数据
		 *
		 * @param node
		 * @param name
		 * @param value
		 * @param defaultValue
		 */
		void GetNodeValue(const xmlNodePtr node,const char*name,std::string&value,std::string defaultValue = "");

		/**
		 * @brief 获得根节点数据
		 *
		 * @param node
		 * @param name
		 * @param value
		 * @param defaultValue
		 */

		void GetNodeValue(const xmlNodePtr node,const char*name,float &value,float defaultValue = 0.0f);

		/**
		 * @brief 获得根节点数据
		 *
		 * @param node
		 * @param name
		 * @param value
		 * @param defaultValue
		 */
		void GetNodeValue(const xmlNodePtr node,const char*name,double &value,double defaultValue = 0.0);


		xmlNodePtr GetNext(xmlNodePtr node);

	private:

		xmlDocPtr _doc{nullptr};
		xmlNodePtr _cur{nullptr};

};


#endif
