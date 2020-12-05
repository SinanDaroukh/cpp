// Entetes //---------------------------------------------------------------------------------------
#include <ctime>
#include <cstdlib>
#include <controleur_texte.hpp>

#ifdef WITH_QT
 #include <QApplication>
 #include <controleur_graphique.hpp>
#endif

//-----------------------------------------------------------------------------------CreerControleur
#ifdef WITH_QT
 Controleur * creerControleur(const std::string & type,Solitaire & solitaire,QApplication & appli) {
  if (type=="txt") return new ControleurTexte(solitaire);
  else if (type=="gui") return new ControleurGraphique(solitaire,appli);

  return 0;
 }
#else
 Controleur * creerControleur(const std::string & type,Solitaire & solitaire) {
  if (type=="txt") return new ControleurTexte(solitaire);

  return 0;
 }
#endif

//----------------------------------------------------------------------------------------------Main
int main(int argc,char ** argv) {
 Solitaire    solitaire;
 std::string  typeInterface = (argc>=2 ? argv[1] : "txt");

 #ifdef WITH_QT
  QApplication appli(argc,argv);

  Controleur * controleur = creerControleur(typeInterface,solitaire,appli);
 #else
  Controleur * controleur = creerControleur(typeInterface,solitaire);
 #endif

 if (controleur==0) {
  std::cout << "Option d'affichage invalide." << std::endl;
  return 1;
 }

 std::srand(time(0));
 solitaire.setControleur(*controleur);
 controleur->demarrer();

 delete controleur;

 return 0;
}

// Fin //-------------------------------------------------------------------------------------------
