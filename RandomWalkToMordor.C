#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;



int output(int NumHeroes) {
  vector<string> Heroes;
  vector<string> Quests;
  vector<string> Selected;

  // List of Quests. Comment out the quests that you don't want to have appear.
  Quests.push_back("Passage Through Mirkwood");
  Quests.push_back("Journey Along the Anduin");
  Quests.push_back("Escape from Dol Guldur");

  Quests.push_back("The Hunt for Gollum");
  Quests.push_back("Conflict at the Carrock");
  Quests.push_back("A Journey to Rhosgobel");
  Quests.push_back("The Hills of Emyn Muil");
  Quests.push_back("The Dead Marshes");
  Quests.push_back("Return to Mirkwood");

  Quests.push_back("Into the Pit");
  Quests.push_back("The Seventh Level");
  Quests.push_back("Flight from Moria");

  Quests.push_back("The Redhorn Gate");
  Quests.push_back("Road to Rivendell");
  Quests.push_back("The Watcher in the Water");
  Quests.push_back("The Long Dark");
  Quests.push_back("Foundations of Stone");
  Quests.push_back("Shadow and Flame");

  Quests.push_back("Peril in Pelargir");
  Quests.push_back("Into Ithilien");
  Quests.push_back("The Siege of Cair Andros");

  Quests.push_back("The Steward's Fear");
  Quests.push_back("The Druadan Forest");
  Quests.push_back("Encounter at Amon Din");
  Quests.push_back("Assault on Osgiliath");
  Quests.push_back("The Blood of Gondor");
  Quests.push_back("The Morgul Vale");

  Quests.push_back("The Fords of Isen");
  Quests.push_back("To Catch an Orc");
  Quests.push_back("Into Fangorn");

  Quests.push_back("The Dunland Trap");
  Quests.push_back("The Three Trials");
  Quests.push_back("Trouble in Tharbad");
  Quests.push_back("The Nin-in-Eilph");
  Quests.push_back("Celebrimbor's Secret");
  Quests.push_back("The Antlered Crown");

  Quests.push_back("Intruders in Chetwood");
  Quests.push_back("The Weather Hills");
  Quests.push_back("Deadmen's Dike");

  Quests.push_back("The Wastes of Eriador");
  Quests.push_back("Escape from Mount Gram");
  Quests.push_back("Across the Ettenmoors");
  Quests.push_back("The Treachery of Rhudaur");

  Quests.push_back("We Must Away, Ere Break of Day");
  Quests.push_back("Over the Misty Mountains Grim");
  Quests.push_back("Dungeons Deep and Caverns Dim");
  Quests.push_back("Flies and Spiders");
  Quests.push_back("The Lonely Mountain");
  Quests.push_back("The Battle of Five Armies");

  Quests.push_back("A Shadow of the Past");
  Quests.push_back("A Knife in the Dark");
  Quests.push_back("Flight to the Ford");
  Quests.push_back("The Ring Goes South");
  Quests.push_back("Journey in the Dark");
  Quests.push_back("Breaking of the Fellowship");
  Quests.push_back("The Uruk-hai");
  Quests.push_back("Helm's Deep");
  Quests.push_back("The Road to Isengard");
  //  Quests.push_back("The Passage of the Marshes");
  //  Quests.push_back("Journey to the Cross-roads");
  //  Quests.push_back("Shelob's Lair");

  Quests.push_back("The Massing at Osgiliath");
  Quests.push_back("The Battle of Lake-Town");
  Quests.push_back("The Stone of Erech");
  Quests.push_back("The Old Forest");
  Quests.push_back("Fog on the Barrow-downs");
  Quests.push_back("The Ruins of Belegost");

  int r = rand() % Quests.size();
  string Quest = Quests[r];
  cout<<left<<setw(31)<<Quest;

  // List of Heroes. Comment out the heroes that you don't want to have appear.
  Heroes.push_back("Amarthiul");
  Heroes.push_back("Aragorn (Le)");
  Heroes.push_back("Aragorn (Lo)");
  Heroes.push_back("Aragorn (Ta)");
  Heroes.push_back("Balin");
  Heroes.push_back("Bard");
  Heroes.push_back("Beorn");
  Heroes.push_back("Beravor");
  Heroes.push_back("Beregond");
  Heroes.push_back("Bifur");
  Heroes.push_back("Bilbo Baggins");
  Heroes.push_back("Bombur");
  //  Heroes.push_back("Boromir (Le)");
  Heroes.push_back("Boromir (Ta)");
  Heroes.push_back("Brand");
  //  Heroes.push_back("Caldara");
  //  Heroes.push_back("Celeborn");
  //  Heroes.push_back("Dáin Ironfoot");
  Heroes.push_back("Damrod");
  Heroes.push_back("Denethor");
  Heroes.push_back("Dori");
  Heroes.push_back("Dunhere");
  Heroes.push_back("Dwalin");
  Heroes.push_back("Eleanor");
  Heroes.push_back("Elladan         Elrohir         "); // This ensures Elladan and Elrohir always appear together.
  //  Heroes.push_back("Elrohir");
  Heroes.push_back("Elrond");
  Heroes.push_back("Eomer");
  Heroes.push_back("Eowyn");
  Heroes.push_back("Erestor");
  Heroes.push_back("Erkenbrand");
  Heroes.push_back("Faramir (Le)");
  Heroes.push_back("Faramir (Lo)");
  Heroes.push_back("Fatty Bolger");
  Heroes.push_back("Frodo Baggins");
  Heroes.push_back("Galadriel");
  Heroes.push_back("Gandalf");
  Heroes.push_back("Gimli");
  Heroes.push_back("Gloin");
  Heroes.push_back("Glorfindel (Lo)");
  //  Heroes.push_back("Glorfindel (Sp)");
  Heroes.push_back("Grima");
  Heroes.push_back("Halbarad");
  Heroes.push_back("Haldir");
  Heroes.push_back("Hama");
  //  Heroes.push_back("Hirluin the Fair");
  Heroes.push_back("Idraen");
  Heroes.push_back("Legolas");
  Heroes.push_back("Mablung");
  Heroes.push_back("Merry (Sp)");
  Heroes.push_back("Merry (Ta)");
  //  Heroes.push_back("Mirlonde");
  Heroes.push_back("Nori");
  //  Heroes.push_back("Oin");
  //  Heroes.push_back("Ori");
  Heroes.push_back("Pippin (Lo)");
  //  Heroes.push_back("Pippin (Sp)");
  Heroes.push_back("Prince Imrahil");
  Heroes.push_back("Rossiel");
  Heroes.push_back("Sam Gamgee");
  Heroes.push_back("Thalin");
  Heroes.push_back("Theoden (Ta)");
  //  Heroes.push_back("Théoden (Sp)");
  Heroes.push_back("Theodred");
  //  Heroes.push_back("Thorin Oakenshield");
  
  for (int i=0;i<NumHeroes;i++) {
    // Pick random number
    int r = rand() % Heroes.size();
    // Find hero corresponding to that index
    string Hero = Heroes[r];
    // Add that hero to selected
    Selected.push_back(Hero);
    // Print hero name
    cout<<left<<setw(16)<<Hero;
    // If Elladan+Elrodir was chosen, decrease NumHeroes needed by 1.
    if (Hero=="Elladan         Elrohir         ") NumHeroes--;
    // Remove the chosen hero from the list
    Heroes.erase(Heroes.begin()+r);
    // Remove heroes with the same name from the list
    if (Hero=="Aragorn (Le)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Aragorn (Lo)"), Heroes.end());
    if (Hero=="Aragorn (Le)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Aragorn (Ta)"), Heroes.end());
    if (Hero=="Aragorn (Lo)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Aragorn (Le)"), Heroes.end());
    if (Hero=="Aragorn (Lo)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Aragorn (Ta)"), Heroes.end());
    if (Hero=="Aragorn (Ta)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Aragorn (Le)"), Heroes.end());
    if (Hero=="Aragorn (Ta)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Aragorn (Lo)"), Heroes.end());
    if (Hero=="Faramir (Le)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Faramir (Lo)"), Heroes.end());
    if (Hero=="Faramir (Lo)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Faramir (Le)"), Heroes.end());
    if (Hero=="Boromir (Le)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Boromir (Ta)"), Heroes.end());
    if (Hero=="Boromir (Ta)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Boromir (Le)"), Heroes.end());
    if (Hero=="Merry (Sp)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Merry (Ta)"), Heroes.end());
    if (Hero=="Merry (Ta)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Merry (Sp)"), Heroes.end());
    if (Hero=="Glorfindel (Sp)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Glorfindel (Lo)"), Heroes.end());
    if (Hero=="Glorfindel (Lo)") Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Glorfindel (Sp)"), Heroes.end());
    // If there is only one more hero left to choose, remove Elladan+Elrohir from the list
    if (i==NumHeroes-2) Heroes.erase(std::remove(Heroes.begin(), Heroes.end(), "Elladan         Elrohir         "), Heroes.end());
  }
  cout<<endl;
}

int main(int argc, char** argv) {
  // This program accepts an integer as input, where n is th number of times to generate a list of 6 heroes. If no input is specified, n=1
  int n = 1; 
  if (argc==2) n = std::atoi(argv[1]); 
  // Set random seed
  srand (time(NULL));
  for (int i=1; i<=n; i++) {
    std::cout<<right<<setw(2)<<i<<". ";
    // Generate random quest and 6 heroes
    output(6);
  }
}

