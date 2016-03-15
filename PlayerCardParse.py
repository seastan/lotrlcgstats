#!/usr/bin/python
import os
import re
import xml.etree.ElementTree as ET
import csv
import json


allcards=[]
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
        
        # Only allow player card types, including side quests, but not side quests that belong to an encounter set. 
        cardtype = newcard.get("Type","")
        if (cardtype!='Hero' and cardtype!='Ally' and cardtype!='Attachment' and cardtype!='Event' and cardtype!='Side Quest'): continue
        if (newcard.get("Encounter Set","")): continue
        allcards.append(newcard)				

for card in allcards:
     print json.dumps(card, sort_keys=True, indent=4, separators=(',', ': '))
