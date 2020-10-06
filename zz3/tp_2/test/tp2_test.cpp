// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"

#include <cmath>

//#include <cosinus.hpp>
//#include <exponentielle.hpp>
//#include <nuage.hpp>

// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
/*TEST_CASE ( "TP2_Nuage::Ajout" ) {
 Nuage<Cartesien> n;

 REQUIRE ( n.size() == 0u );

 n.ajouter(Cartesien(12,34));
 n.ajouter(Cartesien(56,78));
 n.ajouter(Cartesien(90,12));
 n.ajouter(Cartesien(34,56));

 REQUIRE ( n.size() == 4u );
}*/

//------------------------------------------------------------------------------------------------ 2
/*TEST_CASE ( "TP2_Nuage::Iterateurs" ) {
 Polaire p1(12,34);
 Polaire p2(56,78);
 Polaire p3(90,12);
 Polaire p4(34,56);

 Nuage<Polaire> n;

 n.ajouter(p1);
 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Polaire t[4];
 unsigned i = 0;
 Nuage<Polaire>::const_iterator it = n.begin();

 while (it!=n.end()) t[i++]=*(it++);

 REQUIRE ( t[0].getAngle() == Approx(p1.getAngle()) );
 REQUIRE ( t[0].getDistance() == Approx(p1.getDistance()) );
 REQUIRE ( t[1].getAngle() == Approx(p2.getAngle()) );
 REQUIRE ( t[1].getDistance() == Approx(p2.getDistance()) );
 REQUIRE ( t[2].getAngle() == Approx(p3.getAngle()) );
 REQUIRE ( t[2].getDistance() == Approx(p3.getDistance()) );
 REQUIRE ( t[3].getAngle() == Approx(p4.getAngle()) );
 REQUIRE ( t[3].getDistance() == Approx(p4.getDistance()) );
}*/

//------------------------------------------------------------------------------------------------ 3
/*TEST_CASE ( "TP2_Nuage::BarycentreCartesien_V1" ) {
 Nuage<Cartesien> n;

 Cartesien p1(12,34);
 Cartesien p2(56,78);
 Cartesien p3(90,12);
 Cartesien p4(34,56);

 Cartesien b1 = barycentre_v1(n);

 REQUIRE ( b1.getX() == Approx(0.0) );
 REQUIRE ( b1.getY() == Approx(0.0) );

 n.ajouter(p1);

 Cartesien b2 = barycentre_v1(n);

 REQUIRE ( b2.getX() == Approx(p1.getX()) );
 REQUIRE ( b2.getY() == Approx(p1.getY()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesien b3 = barycentre_v1(n);

 REQUIRE ( b3.getX() == Approx((p1.getX()+p2.getX()+p3.getX()+p4.getX())/4) );
 REQUIRE ( b3.getY() == Approx((p1.getY()+p2.getY()+p3.getY()+p4.getY())/4) );
}*/

//----------------------------------------------------------------------------------------------- 4a
/*TEST_CASE ( "TP2_Nuage::BarycentrePolaire_V1" ) {
 Nuage<Polaire> n;

 Polaire p1(12,34);
 Polaire p2(56,78);
 Polaire p3(90,12);
 Polaire p4(34,56);

 Polaire b1 = barycentre_v1(n);

 REQUIRE ( b1.getAngle() == Approx(0.0) );
 REQUIRE ( b1.getDistance() == Approx(0.0) );

 n.ajouter(p1);

 Polaire b2 = barycentre_v1(n);

 REQUIRE ( b2.getAngle() == Approx(p1.getAngle()) );
 REQUIRE ( b2.getDistance() == Approx(p1.getDistance()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Polaire b3 = barycentre_v1(n);

 REQUIRE ( b3.getAngle() == Approx(43.017260).epsilon(1e-3) );
 REQUIRE ( b3.getDistance() == Approx(42.159772).epsilon(1e-3) );
}*/

//----------------------------------------------------------------------------------------------- 4b
/*TEST_CASE ( "TP2_Nuage::BarycentrePolaire_V1" ) {
 Nuage<Polaire> n;

 Polaire p1(12,34);
 Polaire p2(56,78);
 Polaire p3(90,12);
 Polaire p4(34,56);

 Polaire b1 = barycentre_v1(n);

 REQUIRE ( b1.getAngle() == Approx(0.0) );
 REQUIRE ( b1.getDistance() == Approx(0.0) );

 n.ajouter(p1);

 Polaire b2 = barycentre_v1(n);

 REQUIRE ( b2.getAngle() == Approx(p1.getAngle()) );
 REQUIRE ( b2.getDistance() == Approx(p1.getDistance()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Polaire b3 = barycentre_v1(n);

 REQUIRE ( b3.getAngle() == Approx((p1.getAngle()+p2.getAngle()
                                   +p3.getAngle()+p4.getAngle())/4) );

 REQUIRE ( b3.getDistance() == Approx((p1.getDistance()+p2.getDistance()
                                      +p3.getDistance()+p4.getDistance())/4) );
}*/

//------------------------------------------------------------------------------------------------ 5
/*TEST_CASE ( "TP2_Nuage::BarycentreCartesien_V2" ) {
 Nuage<Cartesien> n;

 Cartesien p1(12,34);
 Cartesien p2(56,78);
 Cartesien p3(90,12);
 Cartesien p4(34,56);

 Cartesien b1 = barycentre_v2(n);

 REQUIRE ( b1.getX() == Approx(0.0) );
 REQUIRE ( b1.getY() == Approx(0.0) );

 n.ajouter(p1);

 Cartesien b2 = barycentre_v2(n);

 REQUIRE ( b2.getX() == Approx(p1.getX()) );
 REQUIRE ( b2.getY() == Approx(p1.getY()) );

 n.ajouter(p2);
 n.ajouter(p3);
 n.ajouter(p4);

 Cartesien b3 = barycentre_v2(n);

 REQUIRE ( b3.getX() == Approx((p1.getX()+p2.getX()+p3.getX()+p4.getX())/4) );
 REQUIRE ( b3.getY() == Approx((p1.getY()+p2.getY()+p3.getY()+p4.getY())/4) );
}*/

//------------------------------------------------------------------------------------------------ 6
/*TEST_CASE ( "TP2_Nuage::BarycentreCartesienVecteur" ) {
 std::vector<Cartesien> n;

 Cartesien p1(12,34);
 Cartesien p2(56,78);
 Cartesien p3(90,12);
 Cartesien p4(34,56);

 Cartesien b1 = barycentre_v2(n);

 REQUIRE ( b1.getX() == Approx(0.0) );
 REQUIRE ( b1.getY() == Approx(0.0) );

 n.push_back(p1);

 Cartesien b2 = barycentre_v2(n);

 REQUIRE ( b2.getX() == Approx(p1.getX()) );
 REQUIRE ( b2.getY() == Approx(p1.getY()) );

 n.push_back(p2);
 n.push_back(p3);
 n.push_back(p4);

 Cartesien b3 = barycentre_v2(n);

 REQUIRE ( b3.getX() == Approx((p1.getX()+p2.getX()+p3.getX()+p4.getX())/4) );
 REQUIRE ( b3.getY() == Approx((p1.getY()+p2.getY()+p3.getY()+p4.getY())/4) );
}*/

//------------------------------------------------------------------------------------------------ 7
/*TEST_CASE ( "TP2_Nuage::BarycentrePolaire_V2" ) {
 std::vector<Polaire> n;

 Polaire p1(12,34);
 Polaire p2(56,78);
 Polaire p3(90,12);
 Polaire p4(34,56);

 Polaire b1 = barycentre_v2(n);

 REQUIRE ( b1.getAngle() == Approx(0.0) );
 REQUIRE ( b1.getDistance() == Approx(0.0) );

 n.push_back(p1);

 Polaire b2 = barycentre_v2(n);

 REQUIRE ( b2.getAngle() == Approx(p1.getAngle()) );
 REQUIRE ( b2.getDistance() == Approx(p1.getDistance()) );

 n.push_back(p2);
 n.push_back(p3);
 n.push_back(p4);

 Polaire b3 = barycentre_v2(n);

 REQUIRE ( b3.getAngle() == Approx(43.017260).epsilon(1e-3) );
 REQUIRE ( b3.getDistance() == Approx(42.159772).epsilon(1e-3) );
}*/

//------------------------------------------------------------------------------------------------ 8
/*TEST_CASE ( "TP2_Metaprog::Factorielle" ) {
 unsigned long f1 = Factorielle<1>::valeur;
 unsigned long f5 = Factorielle<5>::valeur;

 REQUIRE ( f1 == 1u );
 REQUIRE ( f5 == 5u*4u*3u*2u );
}*/

//------------------------------------------------------------------------------------------------ 9
/*TEST_CASE ( "TP2_Metaprog::Puissance" ) {
 REQUIRE ( Puissance<0>::valeur(3.0) == Approx(1.0) );
 REQUIRE ( Puissance<1>::valeur(3.0) == Approx(3.0) );
 REQUIRE ( Puissance<4>::valeur(3.0) == Approx(3.0*3.0*3.0*3.0) );
}*/

//----------------------------------------------------------------------------------------------- 10
/*TEST_CASE ( "TP2_Metaprog::Exponentielle" ) {
 REQUIRE ( Exponentielle<4>::valeur(0.0) == Approx(std::exp(0.0)).epsilon(1e-3) );
 REQUIRE ( Exponentielle<12>::valeur(-2.5) == Approx(std::exp(-2.5)).epsilon(1e-3) );
 REQUIRE ( Exponentielle<7>::valeur(1.4) == Approx(std::exp(1.4)).epsilon(1e-3) );
}*/

//----------------------------------------------------------------------------------------------- 11
/*TEST_CASE ( "TP2_Metaprog::Cosinus" ) {
 REQUIRE ( Cosinus<1>::valeur(0.0) == Approx(std::cos(0.0)).epsilon(1e-3) );
 REQUIRE ( Cosinus<4>::valeur(-2.0) == Approx(std::cos(-2.0)).epsilon(1e-3) );
 REQUIRE ( Cosinus<3>::valeur(1.0) == Approx(std::cos(1.0)).epsilon(1e-3) );
}*/

//----------------------------------------------------------------------------------------------- 12
/*TEST_CASE ( "TP2_Metaprog::Sinus" ) {
 REQUIRE ( Sinus<3>::valeur(0.0) == Approx(std::sin(0.0)).epsilon(1e-3) );
 REQUIRE ( Sinus<5>::valeur(-2.0) == Approx(std::sin(-2.0)).epsilon(1e-3) );
 REQUIRE ( Sinus<4>::valeur(1.0) == Approx(std::sin(1.0)).epsilon(1e-3) );
}*/

// Fin //-------------------------------------------------------------------------------------------
