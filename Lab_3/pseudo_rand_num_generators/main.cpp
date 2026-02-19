#include <QCoreApplication>
#include "randgenerator.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Randgenerator rand;

    cout << "Generatory psevdovypadkovykh chysel" << endl;

    cout << "Park-Miller:" << endl;
    for (int counter = 0; counter < 5; ++counter) {
        cout << rand.getParkMiller() << endl;
    }
    cout << endl;

    cout << "L'Ecuyer:" << endl;
    for (int counter = 0; counter < 5; ++counter) {
        cout << rand.getLEcuyer() << endl;
    }
    cout << endl;

    cout << "Liniynyi Kongruentnyi:" << endl;
    for (int counter = 0; counter < 5; ++counter) {
        cout << rand.getLinearCongruential() << endl;
    }
    cout << endl;

    cout << "Blum-Blum-Shub (BBS):" << endl;
    for (int counter = 0; counter < 5; ++counter) {
        cout << rand.getBlumBlumShub() << endl;
    }

    return 0;
}
