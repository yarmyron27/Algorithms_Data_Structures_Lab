#include <QCoreApplication>
#include "test.h"

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test m_test;
    m_test.allTest(1000000, 6);

    return 0;
}
