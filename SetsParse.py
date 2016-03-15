#!/usr/bin/python                                                                                                                                                                                                                                      

import os
import re
import xml.etree.ElementTree as ET
import csv
allcards=[]
for folder in next(os.walk('Sets'))[1]:
    tree = ET.parse('Sets/'+folder+"/set.xml")
    root = tree.getroot()
    setname = root.get('name')
    if 'Custom' in setname: continue
    for card in root.getiterator('card'):
        # Reset variables                                                                                                                                                                                                                              
        cardname=''
        cardid=''
        cardtype=''
        cardsphere=''
        cardcost=''
        cardwillpower=''
        cardattack=''
        carddefense=''
        cardhealth=''
        cardtraits=''
        cardunique=''

        # Set variables.                                                                                                                                                                                                                               
        cardname = card.get('name')
        cardid = card.get('id')

        # Ignore encounter cards.                                                                                                                                                                                                                      
        cardback = card.get('size')
        if (cardback=='EncounterCard'): continue

        for property in card.getiterator('property'):
            propname = property.get('name')
            if (propname=='Type'):
                cardtype = property.get('value')
            if (propname=='Sphere'):
                cardsphere = property.get('value')
            if (propname=='Cost'):
                cardcost = property.get('value')
            if (propname=='Willpower'):
                cardwillpower = property.get('value')
            if (propname=='Attack'):
                cardattack = property.get('value')
            if (propname=='Defense'):
                carddefense = property.get('value')
            if (propname=='Health'):
                cardhealth = property.get('value')
            if (propname=='Traits'):
                cardtraits = property.get('value')
            if (propname=='Unique'):
                cardunique = property.get('value')
				
        if (cardtype!='Hero' and cardtype!='Ally' and cardtype!='Attachment' and cardtype!='Event'): continue
        if (cardtype=='Hero'): print cardname
        newcard = {"name" : cardname, "id" : card, "type" : cardtype, "sphere" : cardsphere, "cost" : cardcost, "willpower" : cardwillpower, "attack" : cardattack, "defense" : carddefense, "health" : cardhealth, "traits" : cardtraits, "unique" : \
cardunique}
        # print shadow                                                                                                                                                                                                                                 
        # print newcard                                                                                                                                                                                                                                
        allcards.append(newcard)				