#!/usr/bin/python
import os
import re
import xml.etree.ElementTree as ET
import csv
import json

# Create a JSON dictionary of all the cards

allcards={}
for folder in next(os.walk('Sets'))[1]:
    tree = ET.parse('Sets/'+folder+"/set.xml")
    root = tree.getroot()
    setname = root.get('name')
    if 'Custom' in setname: continue
    for card in root.getiterator('card'):
        newcard = {}
        newcard["Name"] = card.get('name')
        newcard["OctgnID"] = card.get('id')
        for property in card.getiterator('property'):
            propname = property.get('name')
            propvalue = property.get('value')
            newcard[propname] = propvalue
        
        allcards[newcard["OctgnID"]] = newcard				

with open('Dictionary.json', 'w') as outfile:
    json.dump(allcards, outfile, sort_keys = True, indent = 4)
