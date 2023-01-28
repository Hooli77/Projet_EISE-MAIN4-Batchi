#include <iostream>
using namespace std;
#include "projet_cdm.hh"
#include <fstream>
#include <list>
#include <string>
#include <vector>

int Application::points = 0;

int check1 = 0; // check saisi du pays
int check2 = 0; // check saisi de la difficulté
int check = 0;  // check des 2 saisies

/* Constructeur Classe parent*/
Joueur::Joueur(string country, int level, list<string> countries)  {   
    for (string e : countries)
    {
        if (country.compare(e) == 0 )
        {
            pays = country;
            check1= 1;
        }
    }

    if (level == 1 || level == 2 || level == 3)
    {
        difficulty= level;
        check2 = 1;
    }
    check = check1 + check2;
}

string Joueur::getCountry(){
    return pays;
}

void Joueur::setCountry(string country){
    pays = country;
}

int Joueur::getDifficulty(){
    return difficulty;
}

void Joueur::setDifficulty(int lv){ // lv = difficulty
    difficulty = lv;
}

// Surcharge d'opérateur pour afficher la liste
ostream& operator<<(ostream& COUT, Application& myCollection) {  
    for (string country : myCollection.Countries)
        COUT << country <<"  ";
    return COUT;
}

/* Constructeurs :*/
/* Pour classes abstraites*/
Joueuroffensif::Joueuroffensif(string country, int difficulty, list<string> L): Joueur(country, difficulty, L){}
Joueurdefensif::Joueurdefensif(string country, int difficulty, list<string> L): Joueur(country, difficulty, L){}

/* Pour Classes filles*/
Attaquants::Attaquants(string country, int difficulty, list<string> L): Joueuroffensif(country, difficulty, L){}
Milieuxoffensif::Milieuxoffensif(string country, int difficulty, list<string> L): Joueuroffensif(country, difficulty, L){}
Milieuxdefensif::Milieuxdefensif(string country, int difficulty, list<string> L): Joueurdefensif(country, difficulty, L){}
Defenseurs::Defenseurs(string country, int difficulty, list<string> L): Joueurdefensif(country, difficulty, L){}
Gardiens::Gardiens(string country, int difficulty, list<string> L): Joueurdefensif(country, difficulty, L){}

/***********************************************/

/* Questionnaire */

void Joueur::questionsJoueur(){
    string rep1; // la réponse saisi par l'utilisateur
    char separator= ' ';

    fstream myFile;
    fstream rep;
    if (getCountry() == "France"){
        myFile.open("questionsJoueur_France.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueur_France.txt",ios::in); // read mode
    }

    if (getCountry() == "Allemagne"){
        myFile.open("questionsJoueur_Allemagne.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueur_Allemagne.txt",ios::in); // read mode
    }

    if (getCountry() == "Angleterre"){
        myFile.open("questionsJoueur_Angleterre.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueur_Angleterre.txt",ios::in); // read mode
    }

    if (getCountry() == "Italie"){
        myFile.open("questionsJoueur_Italie.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueur_Italie.txt",ios::in); // read mode
    }

    if (getCountry() == "Espagne"){
        myFile.open("questionsJoueur_Espagne.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueur_Espagne.txt",ios::in); // read mode
    }

    if  (myFile.is_open() && rep.is_open()) {
        vector<string> line_v;
        string line1;
        string line2;

        while (getline(myFile,line1) && getline(rep,line2)){
            cout << line1 << endl;
            cout << "Saisissez votre réponse : " ;
            cin >> rep1;
            cout << endl;

            string s; // chaine temporaire pour stocker des bouts de chaine
            int i = 0;
            while (line2[i] != '\0') {
                if (line2[i] != char (separator)) {
                    s += line2[i]; // On concatene avec la chaine temporaire
                } else {
                    line_v.push_back(s); 
                    s.clear();
                }
                i++;
            }
            line_v.push_back(s); 

            for (string elem : line_v) {
            if (rep1.compare(elem) == 0){
                points++;
                cout << "Bonne réponse !" << endl << endl;
                break;
                }
            }
            line_v.clear(); 
        }
        myFile.close(); // close
        rep.close(); // close
    }
}

void Joueur::vrai_faux_questions(){
    string rep1; // la réponse saisi par l'utilisateur
    char separator= ' ';

    fstream myFile;
    fstream rep;
    
    myFile.open("quuestionsVrai_Faux.txt",ios::in); // read mode
    rep.open("reponsesquestionsVrai_Faux.txt",ios::in); // read mode
    
    if  (myFile.is_open() && rep.is_open()) {
        vector<string> line_v;
        string line1;
        string line2;

        while (getline(myFile,line1) && getline(rep,line2)){
            cout << line1 << endl;
            cout << "Saisissez votre réponse : " ;
            cin >> rep1;
            cout << endl;

            string s; 
            int i = 0;
            while (line2[i] != '\0') {
                if (line2[i] != char (separator)) {
                    s += line2[i]; 
                } else {
                    //line_v.push_back(s); 
                    s.clear();
                }
                i++;
            }
            line_v.push_back(s); 

            for (string elem : line_v) {
            if (rep1.compare(elem) == 0){
                points++;
                cout << "Bonne réponse !" << endl << endl;
                break;
                }
            }
            line_v.clear();
        }
        myFile.close(); // close
        rep.close(); // close
    }
}

void Attaquants::questionsJoueuroffensif(){
    string rep1; // la réponse saisi par l'utilisateur
    char separator= ' ';

    fstream myFile;
    fstream rep;
    if (getCountry() == "France"){
        myFile.open("questionsJoueuroffensif_France.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueuroffensif_France.txt",ios::in); // read mode
    }

    if (getCountry() == "Allemagne"){
        myFile.open("questionsJoueuroffensif_Allemagne.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueuroffensif_Allemagne.txt",ios::in); // read mode
    }

    if (getCountry() == "Angleterre"){
        myFile.open("questionsJoueuroffensif_Angleterre.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueuroffensif_Angleterre.txt",ios::in); // read mode
    }

    if (getCountry() == "Italie"){
        myFile.open("questionsJoueuroffensif_Italie.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueuroffensif_Italie.txt",ios::in); // read mode
    }

    if (getCountry() == "Espagne"){
        myFile.open("questionsJoueuroffensif_Espagne.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueuroffensif_Espagne.txt",ios::in); // read mode
    }

    if  (myFile.is_open() && rep.is_open()) {
        vector<string> line_v;
        string line1;
        string line2;

        while (getline(myFile,line1) && getline(rep,line2)){
            cout << line1 << endl;
            cout << "Saisissez votre réponse : " ;
            cin >> rep1;
            cout << endl;

            string s; 
            int i = 0;
            while (line2[i] != '\0') {
                if (line2[i] != char (separator)) {
                    s += line2[i]; 
                } else {
                    line_v.push_back(s); 
                    s.clear();
                }
                i++;
            }
            line_v.push_back(s); 

            for (string elem : line_v) {
            if (rep1.compare(elem) == 0){
                points++;
                cout << "Bonne réponse !" << endl << endl;
                break;
                }
            }
            line_v.clear();
        }
        myFile.close(); // close
        rep.close(); // close
    }
}

void Milieuxoffensif::questionsJoueuroffensif(){
    string rep1; // la réponse saisi par l'utilisateur
    char separator= ' ';

    fstream myFile;
    fstream rep;
    if (getCountry() == "France"){
        myFile.open("questionsmilieuxoff_France.txt",ios::in); // read mode
        rep.open("reponses_questionsmilieuxoff_France.txt",ios::in); // read mode
    }

    if (getCountry() == "Allemagne"){
        myFile.open("questionsmilieuxoff_Allemagne.txt",ios::in); // read mode
        rep.open("reponses_questionsmilieuxoff_Allemagne.txt",ios::in); // read mode
    }

    if (getCountry() == "Angleterre"){
        myFile.open("questionsmilieuxoff_Angleterre.txt",ios::in); // read mode
        rep.open("reponses_questionsmilieuxoff_Angleterre.txt",ios::in); // read mode
    }

    if (getCountry() == "Italie"){
        myFile.open("questionsmilieuxoff_Italie.txt",ios::in); // read mode
        rep.open("reponses_questionsmilieuxoff_Italie.txt",ios::in); // read mode
    }

    if (getCountry() == "Espagne"){
        myFile.open("questionsmilieuxoff_Espagne.txt",ios::in); // read mode
        rep.open("reponses_questionsmilieuxoff_Espagne.txt",ios::in); // read mode
    }

    if  (myFile.is_open() && rep.is_open()) {
        vector<string> line_v;
        string line1;
        string line2;

        while (getline(myFile,line1) && getline(rep,line2)){
            cout << line1 << endl;
            cout << "Saisissez votre réponse : " ;
            cin >> rep1;
            cout << endl;

            string s; 
            int i = 0;
            while (line2[i] != '\0') {
                if (line2[i] != char (separator)) {
                    s += line2[i]; 
                } else {
                    line_v.push_back(s); 
                    s.clear();
                }
                i++;
            }
            line_v.push_back(s); 

            for (string elem : line_v) {
            if (rep1.compare(elem) == 0){
                points++;
                cout << "Bonne réponse !" << endl << endl;
                break;
                }
            }
            line_v.clear();
        }
        myFile.close(); // close
        rep.close(); // close
    }
}

void Milieuxdefensif::questionsJoueurdefensif(){
    string rep1; // la réponse saisi par l'utilisateur
    char separator= ' ';

    fstream myFile;
    fstream rep;
    if (getCountry() == "France"){
        myFile.open("questionsmilieuxdef_France.txt",ios::in); // read mode
        rep.open("reponses_questionsmilieuxdef_France.txt",ios::in); // read mode
    }

    if (getCountry() == "Allemagne"){
        myFile.open("questionsmilieuxdef_Allemagne.txt",ios::in); // read mode
        rep.open("reponses_questionsmilieuxdef_Allemagne.txt",ios::in); // read mode
    }

    if (getCountry() == "Angleterre"){
        myFile.open("questionsmilieuxdef_Angleterre.txt",ios::in); // read mode
        rep.open("reponses_questionsmilieuxdef_Angleterre.txt",ios::in); // read mode
    }

    if (getCountry() == "Italie"){
        myFile.open("questionsmilieuxdef_Italie.txt",ios::in); // read mode
        rep.open("reponses_questionsmilieuxdef_Italie.txt",ios::in); // read mode
    }

    if (getCountry() == "Espagne"){
        myFile.open("questionsmilieuxdef_Espagne.txt",ios::in); // read mode
        rep.open("reponses_questionsmilieuxdef_Espagne.txt",ios::in); // read mode
    }

    if  (myFile.is_open() && rep.is_open()) {
        vector<string> line_v;
        string line1;
        string line2;

        while (getline(myFile,line1) && getline(rep,line2)){
            cout << line1 << endl;
            cout << "Saisissez votre réponse : " ;
            cin >> rep1;
            cout << endl;

            string s; 
            int i = 0;
            while (line2[i] != '\0') {
                if (line2[i] != char (separator)) {
                    s += line2[i]; 
                } else {
                    line_v.push_back(s); 
                    s.clear();
                }
                i++;
            }
            line_v.push_back(s); 

            for (string elem : line_v) {
            if (rep1.compare(elem) == 0){
                points++;
                cout << "Bonne réponse !" << endl << endl;
                break;
                }
            }
            line_v.clear();
        }
        myFile.close(); // close
        rep.close(); // close
    }
}

void Defenseurs::questionsJoueurdefensif(){
    string rep1; // la réponse saisi par l'utilisateur
    char separator= ' ';

    fstream myFile;
    fstream rep;
    if (getCountry() == "France"){
        myFile.open("questionsJoueurdefensif_France.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueurdefensif_France.txt",ios::in); // read mode
    }

    if (getCountry() == "Allemagne"){
        myFile.open("questionsJoueurdefensif_Allemagne.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueurdefensif_Allemagne.txt",ios::in); // read mode
    }

    if (getCountry() == "Angleterre"){
        myFile.open("questionsJoueurdefensif_Angleterre.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueurdefensif_Angleterre.txt",ios::in); // read mode
    }

    if (getCountry() == "Italie"){
        myFile.open("questionsJoueurdefensif_Italie.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueurdefensif_Italie.txt",ios::in); // read mode
    }

    if (getCountry() == "Espagne"){
        myFile.open("questionsJoueurdefensif_Espagne.txt",ios::in); // read mode
        rep.open("reponses_questionsJoueurdefensif_Espagne.txt",ios::in); // read mode
    }

    if  (myFile.is_open() && rep.is_open()) {
        vector<string> line_v;
        string line1;
        string line2;

        while (getline(myFile,line1) && getline(rep,line2)){
            cout << line1 << endl;
            cout << "Saisissez votre réponse : " ;
            cin >> rep1;
            cout << endl;

            string s; 
            int i = 0;
            while (line2[i] != '\0') {
                if (line2[i] != char (separator)) {
                    s += line2[i]; 
                } else {
                    line_v.push_back(s); 
                    s.clear();
                }
                i++;
            }
            line_v.push_back(s); 

            for (string elem : line_v) {
            if (rep1.compare(elem) == 0){
                points++;
                cout << "Bonne réponse !" << endl << endl;
                break;
                }
            }
            line_v.clear();
        }
        myFile.close(); // close
        rep.close(); // close
    }
}

void Gardiens::questionsJoueurdefensif(){
    string rep1; // la réponse saisi par l'utilisateur
    char separator= ' ';

    fstream myFile;
    fstream rep;
    if (getCountry() == "France"){
        myFile.open("questionsgardiens_France.txt",ios::in); // read mode
        rep.open("reponses_questionsgardiens_France.txt",ios::in); // read mode
    }

    if (getCountry() == "Allemagne"){
        myFile.open("questionsgardiens_Allemagne.txt",ios::in); // read mode
        rep.open("reponses_questionsgardiens_Allemagne.txt",ios::in); // read mode
    }

    if (getCountry() == "Angleterre"){
        myFile.open("questionsgardiens_Angleterre.txt",ios::in); // read mode
        rep.open("reponses_questionsgardiens_Angleterre.txt",ios::in); // read mode
    }

    if (getCountry() == "Italie"){
        myFile.open("questionsgardiens_Italie.txt",ios::in); // read mode
        rep.open("reponses_questionsgardiens_Italie.txt",ios::in); // read mode
    }

    if (getCountry() == "Espagne"){
        myFile.open("questionsgardiens_Espagne.txt",ios::in); // read mode
        rep.open("reponses_questionsgardiens_Espagne.txt",ios::in); // read mode
    }

    if  (myFile.is_open() && rep.is_open()) {
        vector<string> line_v;
        string line1;
        string line2;

        while (getline(myFile,line1) && getline(rep,line2)){
            cout << line1 << endl;
            cout << "Saisissez votre réponse : " ;
            cin >> rep1;
            cout << endl;

            string s; 
            int i = 0;
            while (line2[i] != '\0') {
                if (line2[i] != char (separator)) {
                    s += line2[i]; 
                } else {
                    line_v.push_back(s); 
                    s.clear();
                }
                i++;
            }
            line_v.push_back(s); 

            for (string elem : line_v) {
            if (rep1.compare(elem) == 0){
                points++;
                cout << "Bonne réponse !" << endl << endl;
                break;
                }
            }
            line_v.clear();
        }
        myFile.close(); // close
        rep.close(); // close
    }
}

/***********************************************/


int main(){

    int input_difficulty;  // variable pour la saisi de la difficulté
    string input_country; // variable pour la saisi du pays
    string input_theme; // variable pour la saisi du theme quand difficulté = 2

/***** Remplissage de la liste de pays **********/
    const char* c1 = "France";
    string s1= c1;
    const char* c2 = "Allemagne";
    string s2= c2;
    const char* c3 = "Angleterre";
    string s3= c3;
    const char* c4 = "Italie";
    string s4= c4;
    const char* c5 = "Espagne";
    string s5= c5;

    Application myCountries_Collection;
    myCountries_Collection += s1;
    myCountries_Collection += s2;
    myCountries_Collection += s3;
    myCountries_Collection += s4;
    myCountries_Collection += s5;
/***********************************************/
    cout << "**********************************************************************************************" << endl << endl;
    cout << "BIENVENUE DANS CE QUIZZ SPECIAL FOOT POUR TESTER VOS CONNAISSANCES SUR LE MONDE DU BALLON ROND"<< endl << endl;
    cout << "**********************************************************************************************" << endl << endl;
    cout << "Avant de commencer lisez attentivement ce qui suit:"<< endl << endl;
    cout << "La plupart des réponses contiennent uniquement le nom le plus connu des joueurs, généralement leurs nom de familles."<< endl ;
    cout << "De plus les espaces sont proscrits dans ce jeu. Au lieu d'utiliser un espace, utiliser plutôt ce caractère : _ "<< endl ;
    cout << "Enfin, débutez toujours vos réponses ou mots par une lettre majuscule, idem pour les mots espacés."<< endl <<endl ;
    cout << "Exemple : Écrivez Maradona au lieu de maradona ; Écrivez De_Jong au lieu de De_jong ou de_jong"<< endl <<endl;
    cout << "**********************************************************************************************" << endl << endl;
    cout << "RÈGLES DU JEU: "<< endl ;
    cout << "Pour commencer choisissez un niveau de difficulté entre 1 et 3 :"<< endl;
    cin >> input_difficulty;
    cout << endl;
    cout << "À présent choisissez un pays dans la liste :"<< endl;
    cout << myCountries_Collection;
    cout << endl;
    cin >> input_country;
    
    Joueur j= Joueur(input_country, input_difficulty, myCountries_Collection.Countries);

    /************ Vérification des saisies**********/
    while(check != 2)
    {
        if (check2==0){
            do{
                cout << "Saisissez à nouveau le niveau de difficulté" <<endl;
                cin >> input_difficulty;
                Joueur j= Joueur(input_country, input_difficulty,myCountries_Collection.Countries);
            } while(check2 !=1);
        }

        if (check1==0){
            do{
                cout << "Le pays choisi est indisponible, choisissez un pays de la liste ou vérifiez le format !" << endl;
                cin >> input_country;
                Joueur j= Joueur(input_country, input_difficulty,myCountries_Collection.Countries); // le pays doit commencer par une lettre majuscule
            } while(check1 !=1);
        }
        j.setCountry(input_country);
        j.setDifficulty(input_difficulty);
    }
    /**************************************************/

    if (input_difficulty == 3){
        cout << endl << "----------------------------------------------------------------" << endl << endl;
        cout << "                          LET'S GO !        " << endl;
        cout << endl << "----------------------------------------------------------------" << endl << endl;
        j.questionsJoueur();
            cout << "Votre score est: "<< myCountries_Collection.points << "/10"<< endl << endl;
            cout << "MERCI D'AVOIR JOUÉ  !"<< endl<<endl;
    }

    if (input_difficulty == 2){
        cout << endl << "----------------------------------------------------------------" << endl << endl;
        cout << "Veuillez choisir un thème :" << " JoueurOffensif ou JoueurDefensif" << endl;
        cin >> input_theme;
        cout << endl;
        int check_theme = 0;

        do{
        if (input_theme.compare("JoueurOffensif")==0)
        {
            check_theme= 1;
            
            cout << "                           LET'S GO !" << endl;
            cout << endl << "----------------------------------------------------------------" << endl << endl;

            Attaquants a = Attaquants(input_country, input_difficulty, myCountries_Collection.Countries);
            Milieuxoffensif mo = Milieuxoffensif(input_country, input_difficulty, myCountries_Collection.Countries);

            a.questionsJoueuroffensif();
            mo.questionsJoueuroffensif();
            cout << "Votre score est: "<< myCountries_Collection.points << "/10"<< endl << endl;
            cout << "MERCI D'AVOIR JOUÉ  !"<< endl<<endl;
            break;
        }

        if (input_theme.compare("JoueurDefensif")==0)
        {
            check_theme= 1;

            cout << "                           LET'S GO !" << endl;
            cout << endl << "----------------------------------------------------------------" << endl << endl;

            Defenseurs d = Defenseurs(input_country, input_difficulty, myCountries_Collection.Countries);
            Milieuxdefensif md = Milieuxdefensif(input_country, input_difficulty, myCountries_Collection.Countries);
            Gardiens g = Gardiens(input_country, input_difficulty, myCountries_Collection.Countries);
            
            d.questionsJoueurdefensif();
            md.questionsJoueurdefensif();
            g.questionsJoueurdefensif();
            cout << "Votre score est: "<< myCountries_Collection.points << "/10"<< endl << endl;
            cout << "MERCI D'AVOIR JOUÉ  !"<< endl<<endl;
            break;
        }

        else{
            cout << "Veuilez saisir l'un des thèmes dans la liste" << endl;
            cin >> input_theme;
            cout << endl;
        }
        } while (check_theme != 1);
    }

    if (input_difficulty == 1){
        cout << endl << endl;
        cout << "Pour ce niveau de difficulté vous devez répondre Vrai ou Faux à chaque question" << endl << endl;
        cout << endl << "----------------------------------------------------------------" << endl << endl;
        cout << "                           LET'S GO !" << endl;
        cout << endl << "----------------------------------------------------------------" << endl << endl;
        j.vrai_faux_questions();
        cout << "Votre score est: "<< myCountries_Collection.points << "/10"<< endl << endl;
        cout << "MERCI D'AVOIR JOUÉ !"<< endl << endl;
    }

}