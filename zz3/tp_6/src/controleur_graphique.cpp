// Entetes //---------------------------------------------------------------------------------------
#include <QApplication>
#include <controleur_graphique.hpp>

// Implementation  V u e G r a p h i q u e //-------------------------------------------------------

//--------------------------------------------------------------------------------------Constructeur
ControleurGraphique::ControleurGraphique(Solitaire & solitaire,QApplication & appli)
: QObject(),Controleur(solitaire),appli_(appli),fenetre_() {}

//------------------------------------------------------------------------------------------Demarrer
void ControleurGraphique::demarrer(void) {
 fenetre_.show();
 appli_.exec();
}

//----------------------------------------------------------------------------------------Rafraichir
void ControleurGraphique::rafraichir(void) {}

// Fin //-------------------------------------------------------------------------------------------
