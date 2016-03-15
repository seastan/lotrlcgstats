#!/usr/bin/python
import os
import re
import xml.etree.ElementTree as ET
import csv
import json


# Open JSON dictionary of all cards
with open('Dictionary.json') as infile:    
    allcards = json.load(infile)

# Loop over quests
directories = ['Easy','Quests','Nightmare']
for directory in directories:
    for o8dfile in os.listdir(directory):
        tree = ET.parse(directory+'/'+o8dfile)
        root = tree.getroot()
        stats = {
            "EnemyTotal": 0,
            "EnemyThreatTotal": 0
        }
        for card in root.getiterator('card'):
            OctgnID = card.get('id',0)
            Quantity = int(card.get('qty',0))
            cardObject = allcards.get(OctgnID,{});
            if (cardObject.get("Type","") == "Enemy"):
                stats["EnemyTotal"] = stats["EnemyTotal"] + Quantity
                # Calculate threat
                Threat = cardObject.get("Threat",0)
                try:
                    Threat = int(Threat)
                except: # in case Threat == 'X' or '-'
                    Threat = 0
                
                stats["EnemyThreatTotal"] = stats["EnemyThreatTotal"] + Threat*Quantity
                stats["EnemyThreatAverage"] = float(stats["EnemyThreatTotal"])/stats["EnemyTotal"]
        print o8dfile
        print stats

