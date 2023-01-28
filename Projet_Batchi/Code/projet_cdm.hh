#ifndef __PROJETCDM_HH__
#define __PROJETCDM_HH__

#include <string>
#include <vector>
#include <list>
using namespace std;


struct Application {
    
    list<string> Countries;
	static int points;

    void operator +=(string& country) {			// Surcharge d'opérateur pour ajouter un pays dans la liste
        Countries.push_back(country);
    }

};

class Joueur : public Application {
protected: 
	string pays;			// le pays dont on souhaite tester ses connaissances
	int difficulty;			// le niveau de difficulté des questions
	
public:
	Joueur(string country, int difficulty, list<string> L);
	string getCountry();
	int getDifficulty();
	void setDifficulty(int);
	void setCountry(string country);
	void questionsJoueur();   // 3 // 10 q
	void vrai_faux_questions(); // 2

};

class Joueuroffensif: public Joueur { // Abstraite
public:
	Joueuroffensif(string country, int difficulty, list<string> L);
	virtual void questionsJoueuroffensif() =0 ;  // 2

};

class Joueurdefensif: public Joueur { // Abstraite
public:
	Joueurdefensif(string country, int difficulty, list<string> L);
	virtual void questionsJoueurdefensif() =0 ;  // 2
};

class Attaquants: public Joueuroffensif { 
public:
	Attaquants(string country, int difficulty, list<string> L);
	void questionsJoueuroffensif(); // 2 // 5q
};

class Milieuxoffensif: public Joueuroffensif { 
public:
	Milieuxoffensif(string country, int difficulty, list<string> L);
	void questionsJoueuroffensif(); // 2  // 5q
	 
};

class Milieuxdefensif: public Joueurdefensif { 
public:
	Milieuxdefensif(string country, int difficulty, list<string> L);
	void questionsJoueurdefensif(); // 2  // 5q
};

class Defenseurs: public Joueurdefensif { 
public:
	 Defenseurs(string country, int difficulty, list<string> L);
	 void questionsJoueurdefensif() ; // 2 // 5q 
};

class Gardiens: public Joueurdefensif { 
public:
	 Gardiens(string country, int difficulty, list<string> L);
	 void questionsJoueurdefensif(); // 1
};

#endif