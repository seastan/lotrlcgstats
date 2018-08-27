#!/usr/bin/python
import os
import re
import xml.etree.ElementTree as ET
import csv
import json
import operator
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.colors import LogNorm

# Open JSON dictionary of all cards
with open('Dictionary.json') as infile:    
    allcards = json.load(infile)

# Loop over quests
allstats={}
ecosts=[]
ecosts1=[]
attacks=[]
#directories = ['Easy','Quests','Nightmare']
directories = ['Quests']
for directory in directories:
    for o8dfile in os.listdir(directory):
        tree = ET.parse(directory+'/'+o8dfile)
        root = tree.getroot()
        stats = {
            "QuestName": o8dfile,
            "EnemyTotal": 0,
            "EnemyThreatTotal": 0,
            "NumType": 0
        }
        if o8dfile=='Quest-909-Epic-The-Siege-of-Annuminas.o8d': continue
        print(o8dfile)
        for card in root.getiterator('card'):
            OctgnID = card.get('id',0)
            Quantity = int(card.get('qty',0))
            cardObject = allcards.get(OctgnID,{});
            if (cardObject.get("Type","") == "Enemy"):
                stats["EnemyTotal"] = stats["EnemyTotal"] + Quantity
                # Calculate threat
                Threat = cardObject.get("Threat",0)
                ECost = cardObject.get("Engagement Cost",0)
                Attack = cardObject.get("Attack",0)
                if (cardObject.get("Unique",0)!=0): continue
                if (Threat.isdigit()): 
                    Threat = int(Threat)
                else:  # in case Threat == 'X' or '-'
                    Threat = 0;
                if (ECost.isdigit()): 
                    ECost = int(ECost)
                else:  # in case Threat == 'X' or '-'
                    ECost = 0;
                if (Attack.isdigit()): 
                    Attack = int(Attack)
                else:  # in case Threat == 'X' or '-'
                    Attack = 0;
                
                stats["EnemyThreatTotal"] = stats["EnemyThreatTotal"] + Threat*Quantity
                ecosts += [ECost]*Quantity
                ecosts1 += [ECost]
                attacks += [Attack]*Quantity
            if (cardObject.get("Type","") == "Location") and cardObject.get("Unique","") == "":
                # print cardObject.get("Name","")
                stats["NumType"] = stats["NumType"] + Quantity
                # Calculate threat
        
        # Calculate averages
        stats["EnemyThreatAverage"] = float(stats["EnemyThreatTotal"])/stats["EnemyTotal"]
        # Print
        #print o8dfile
        #print stats["NumType"]
        allstats[o8dfile]=stats["NumType"]

        
sorted_allstats = sorted(allstats.items(), key=operator.itemgetter(1))
#print sorted_allstats
print(ecosts)

# the histogram of the data
# n, bins, patches = plt.hist(ecosts, 50, range=(0,50), normed=0, color='g',label='Including multiples')#='step')
# n1, bins1, patches1 = plt.hist(ecosts1, 50, range=(0,50), normed=0, color='b',label='Not including multiples')#='step')

# plt.xlabel('Engagement Cost')
# plt.ylabel('Number')
# plt.axis([0, 50, 0, 240])
# plt.grid(True)
# plt.legend(prop={'size': 10})
# plt.show()

plt.hist2d(ecosts, attacks, bins=(51,10), range=np.array([(0, 51), (0, 10)]),cmap='YlOrBr',norm=LogNorm())#, normed=False, weights=None, cmin=None, cmax=None, hold=None, data=None)
#plt.scatter(ecosts, attacks,cmap='Blues')#norm=LogNorm())#, normed=False, weights=None, cmin=None, cmax=None, hold=None, data=None)
plt.title('Non-unique enemies in normal mode')
plt.xlabel('Engagement Cost')
plt.ylabel('Attack')
cb = plt.colorbar()
cb.set_label("Number (including duplicates)")
plt.show()

print(bins)
