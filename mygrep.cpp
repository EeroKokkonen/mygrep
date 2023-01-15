#include "Application.h"

Application application = Application();

int main(int argc, const char* argv[])
{
    application.Alku(argv);
    
    if (application.ValintaBool[6])
        application.TekstinEtsiminenTiedostosta(argv[2], argv[3]);
    else if (application.ValintaBool[1])
        application.TekstinEtsiminenTiedostosta(argv[1], argv[2]);
    else if (application.ValintaBool[0])
        application.Inkrementti1();
    
    return 0;
}


