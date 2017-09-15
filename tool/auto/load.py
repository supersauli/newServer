import xml.dom.minidom
import write
dom = xml.dom.minidom.parse('element.xml')



def ParseAtrrNode(node):
    global outStr
    attrNode = node.getElementsByTagName("property")
    for attr in attrNode:
        attrType = attr.getAttribute("type")
        attrName = attr.getAttribute("name")
        outStr = outStr + "\n"
        outStr = outStr + attrType
        outStr = outStr + " "
        outStr = outStr + attrName 
        outStr = outStr + ";"




def ParaseNode(node):
   ParseAtrrNode(node) 


def ParseRootNode(root):
    #classNode = root.getElementsByTagName("vector")
    #print classNode
    global outStr
    outStr = "class "
    className = root.getAttribute("name")
    outStr=outStr + className
    outStr=outStr+"\n{"
    #for child in root.childNodes:
    ParaseNode(root)
    outStr=outStr+"\n};"


def test():
    root = dom.documentElement
    print root.nodeName
    print root.nodeValue
    print root.nodeType
    print root.ELEMENT_NODE
    print root.getElementsByTagName('map')
    print root.getAttribute("name")



if __name__ == "__main__":
    global outStr
    root = dom.documentElement
    ParseRootNode(root)
    write.WriteFile(outStr)

