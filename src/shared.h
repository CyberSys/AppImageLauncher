/* central file for utility functions */

// system headers
#include <string>
#include <memory>

// library headers
#include <QDir>
#include <QString>
#include <QSettings>

enum IntegrationState {
    INTEGRATION_FAILED = 0,
    INTEGRATION_SUCCESSFUL,
    INTEGRATION_ABORTED
};

// standard location for integrated AppImages
// currently hardcoded, can not be changed by users
static const auto DEFAULT_INTEGRATION_DESTINATION = QString(getenv("HOME")) + "/Applications/";

// update desktop database and icon caches of desktop environments
// this makes sure that:
//   - outdated entries are removed from the launcher
//   - icons of freshly integrated AppImages are displayed in the launcher
bool updateDesktopDatabaseAndIconCaches();

// load config file and return it
std::shared_ptr<QSettings> getConfig();

// return directory into which the integrated AppImages will be moved
QDir integratedAppImagesDestination();

// build path to standard location for integrated AppImages
QString buildPathToIntegratedAppImage(const QString& pathToAppImage);

// get AppImage MD5 digest
// extracts the digest embedded in the file
// if no such digest has been embedded, it calculates it using libappimage
QString getAppImageDigestMd5(const QString& path);

// checks whether AppImage has been integrated already
bool hasAlreadyBeenIntegrated(const QString& pathToAppImage);

// clean up old desktop files (and related resources, such as icons)
bool cleanUpOldDesktopIntegrationResources(bool verbose = false);
