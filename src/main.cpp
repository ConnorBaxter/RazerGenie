/*
 * Copyright (C) 2016-2018  Luca Weiss <luca (at) z3ntu (dot) xyz>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "config.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QTranslator>
#include <QDebug>

#include "razergenie.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QApplication::setApplicationName("RazerGenie");
    QApplication::setApplicationVersion(RAZERGENIE_VERSION);
    QApplication::setOrganizationName("razergenie"); // for QSettings

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();

    parser.process(app);

    QTranslator translator;
    bool ret = translator.load(QLocale::system(), QString(), QString(), QString(RAZERGENIE_DATADIR) + "/translations/");
    qDebug() << "Translation loaded:" << ret;
    app.installTranslator(&translator);

    RazerGenie w;
    w.show();

    return app.exec();
}
