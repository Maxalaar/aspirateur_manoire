#ifndef ENVIRONNEMENT_MANOIR_H
#define ENVIRONNEMENT_MANOIR_H

#include <QVector>
#include <QThread>
#include <QRandomGenerator>

#include "salle_manoir.h"
#include "entite_simulation.h"
#include "deplacement_thread.h"
#include "vision_thread.h"

class Environnement_manoir : public QObject/* : public QThread*/
{
    Q_OBJECT
public:
    Environnement_manoir(QVector<int> taille_manoir);
    QVector<QVector<Salle_manoir>> get_tableau();
    void placer_entite(int positon_x, int positon_y, Entite_simulation* entite);
    int temps_deplacement_ms = 500;
    int temps_vision_ms = 5000;
    int temps_recuperation_ms = 5000;
    int temps_aspiration_ms = 6000;
    int nombre_poussiere_initiale = 10;
    int nombre_bijou_initiale = 4;

//    void run() override;

private:
    QVector<QVector<Salle_manoir>> tableau;
    QVector<Entite_simulation> liste_aspirateur;
    
public slots:
    void deplacement_entite(Entite_simulation* entite, int position_x, int position_y);

    void deplacement_haut_entite(Entite_simulation* entite);
    void deplacement_bas_entite(Entite_simulation* entite);
    void deplacement_gauche_entite(Entite_simulation* entite);
    void deplacement_droite_entite(Entite_simulation* entite);

    void mise_jour_manoire(Entite_simulation* entite);
    void envoi_mise_jour_manoire(Entite_simulation* entite);

signals:
    void rafraichissement_image(void);
    void fin_action(Entite_simulation* entite);
    void mise_jour_manoir(Entite_simulation* entite, QVector<QVector<Salle_manoir>> tableau);
};

#endif // ENVIRONNEMENT_MANOIR_H
