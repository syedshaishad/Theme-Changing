#include <bb/cascades/Application>

#include <QLocale>
#include <QTranslator>
#include "applicationui.hpp"
#include <Qt/qdeclarativedebug.h>

// INCLUDE ----------Settings.hpp-------------
#include "Settings.hpp"

using namespace bb::cascades;
//---------------------------------ADDED THIS LITTLE CODE----------------------//
QString getValue() {

    //
	Settings settings;
	// use "theme" key for property showing what theme to use on application start
	return settings.getValueFor("theme", "");
}

//-----------------------------------------End line 1---------------------------//

Q_DECL_EXPORT int main(int argc, char **argv)
{


    //---------------------------ADD This Code too----------------------------//
	// update env variable before an application instance created
	qputenv("CASCADES_THEME", getValue().toUtf8());
//-------------------------------------endline 2-----------------------------//



    Application app(argc, argv);

    // Create the Application UI object, this is where the main.qml file
    // is loaded and the application scene is set.
    new ApplicationUI(&app);

    // Enter the application main event loop.
    return Application::exec();
}
