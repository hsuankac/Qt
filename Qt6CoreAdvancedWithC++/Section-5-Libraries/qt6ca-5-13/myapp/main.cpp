/*
 * What
 * Application plugins
 *
 * Why
 * We want to extedn out application
 *
 * How
 * QPluginLoader
 * Make the plugin
 * Build it
 * Include the plugin.h file
 * Add the compiled plugin to a sub folder called "plugins" in the build directory
 *
 *
 */


#include <QCoreApplication>
#include <QDebug>
#include <QString>
#include <QPluginLoader>
#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include "plugin.h"

QStringList getPlugins(QString path)
{
    QStringList plugins;

    QStringList filter;
    filter << "*.dll" << "*.so" << "*.dylib";

    QDir dir(path);
    QFileInfoList list = dir.entryInfoList(filter);
    foreach(QFileInfo file, list)
    {
        plugins.append(file.filePath());
    }

    return plugins;
}

void testPlugins(QStringList plugins)
{
    foreach (QString file, plugins)
    {
        qInfo() << "Loading...." << file;

        QPluginLoader loader(file);
        if(!loader.load())
        {
            qInfo() << "Error: " << loader.fileName() << " Error: " << loader.errorString();
            continue;
        }

        qInfo() << "Loaded: " << loader.fileName();
        Plugin *plugin = qobject_cast<Plugin*>(loader.instance());
        if(plugin)
        {
            plugin->test("Bryan");
            loader.unload();
        }
        else
        {
            qInfo() << "Could not case: " << loader.fileName();
        }
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo()<< "Hello Plugins";
    QDir dir = QDir::current();
    dir.cd("plugins");
    qInfo() << "Path: " << dir.path();

    QStringList plugins = getPlugins(dir.path());
    qInfo() << "Plugins: " << plugins;

    testPlugins(plugins);
    qInfo() << "Done!";

    return a.exec();
}













