#include "main_aspirateur_manoir.h"

//    qDebug() << "Markeur 1 : " << thread()->currentThreadId();

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    main_windows_aspirateur_manoir w;
//    w.show();
    QVector<int> taille_manoir;
    //On fixe la taille en X
    taille_manoir.push_back(5);
    //On fixe la taille en Y
    taille_manoir.push_back(5);
    //On fixe le nombre d'aspirateur
    int nombre_aspirateur = 1;
    //On fixe le nombre de poussier
    int nombre_poussiere_initiale = 3;
    //On fixe le nombre de bijou
    int nombre_bijou_initiale = 2;
    //On fixe le temps d'apparition entre chaque poussiere
    int apparation_poussiere_ms = 1000;
    //On fixe le temps d'apparition entre chaque bijou
    int apparation_bijou_ms = 1000;
    //On fixe le nombre de tour avant la syncronisation de la vision pour l'aspirateur
    int sycro_vision = 10;
    //On fixe recherche informer (true) ou non informer (false) pour les aspirateurs
    bool exploration_informees = true;

    Environnement_manoir* manoir_1 = new Environnement_manoir(taille_manoir, nombre_poussiere_initiale, nombre_bijou_initiale, apparation_poussiere_ms, apparation_bijou_ms);

    for(int i = 0; i < nombre_aspirateur; i++)
    {
        Aspirateur_agent* aspirateur_prov = new Aspirateur_agent(QRandomGenerator::global()->bounded(manoir_1->get_tableau()[0].size()), QRandomGenerator::global()->bounded(manoir_1->get_tableau().size()), manoir_1, sycro_vision, exploration_informees);
    }

    Fenetre_affichage_manoir* fenetre_manoir_1 = new Fenetre_affichage_manoir(manoir_1);


    fenetre_manoir_1->show();
    qDebug() << "L'initialisation de la simulation est fini";
    return a.exec();
}
