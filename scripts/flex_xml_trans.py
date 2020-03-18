#!/usr/bin/env python

from lxml import etree 
from lxml.etree import QName
from argparse import ArgumentParser
import json
import codecs
import unicodedata
import os

class XMLNamespces:
    android = 'http://schemas.android.com/apk/res/android'
    tools = 'http://schemas.android.com/tools'
    app = 'http://schemas.android.com/apk/res-auto'
    ios = 'https://github.com/zionfong/FlexLib2.git'

def trans_xml_file(filePath):
    print "working on : " + filePath

    parser = etree.XMLParser(encoding='utf-8', remove_blank_text = True)
    tree = etree.parse(filePath, parser = parser)

    root = tree.getroot()



    nsmap = root.nsmap
    nsmap["android"] = XMLNamespces.android
    nsmap["tools"] = XMLNamespces.tools
    nsmap["app"] = XMLNamespces.app
    nsmap["ios"] = XMLNamespces.ios

    rootNew = make_new_node(root, nsmap)


    prePath = ""
    fullFileName = filePath
    if '/' in filePath:
        comps = os.path.split(filePath)
        prePath = comps[0] + "/"
        fullFileName = comps[1]

    outputPath = prePath + "xml_trans_result/"
    if not os.path.exists(outputPath):
        os.mkdir(outputPath)

    #treeNew = etree.ElementTree(rootNew)
    tree._setroot(rootNew)

    #headComments = tree.xpath("/comment()")
    #index = 0
    #for cmt in headComments:
    #    tree.insert(index, cmt)
    #    index += 1

    tree.write(outputPath + fullFileName, pretty_print=True, xml_declaration=True, encoding='utf-8')

    print "trans succes!"



def make_new_node(node, nsmap=None):
    if node.tag == etree.Comment:
        return node
    nodeNew = etree.Element(node.tag, nsmap=nsmap)
    keys = node.keys()
    for key in keys:
        if 'name' == key or 'onPress' == key:
            value = node.get(key, '')
            nodeNew.set(QName(XMLNamespces.ios, key), value)
        elif 'layout' == key:
            value = node.get(key, '')
            items = value.split(',')
            for item in items:
                kvs = item.split(':')
                if 2 == len(kvs):
                    attKey = kvs[0].strip()
                    attValue = kvs[1]
                    if "@" == attKey:
                        attKey = "style"
                    nodeNew.set(QName(XMLNamespces.app, attKey), attValue)
        elif 'attr' == key:
            value = node.get(key, '')
            items = value.split(',')
            for item in items:
                kvs = item.split(':')
                if 2 == len(kvs):
                    attKey = kvs[0].strip()
                    attValue = kvs[1]
                    if "@" == attKey:
                        attKey = "style"
                    nodeNew.set(QName(XMLNamespces.ios, attKey), attValue)

    for child in node:
        nodeNew.append(make_new_node(child))

    return nodeNew



if __name__ == '__main__':
    parser = ArgumentParser()
    parser.add_argument('xmlFilePath', type=str, help='XML file Path to be modified.')
    args = parser.parse_args()

    if os.path.isdir(args.xmlFilePath):
        for file in os.listdir(args.xmlFilePath):
            if file.endswith(".xml"):
                trans_xml_file(os.path.join(args.xmlFilePath, file))
    else:
        trans_xml_file(args.xmlFilePath)

