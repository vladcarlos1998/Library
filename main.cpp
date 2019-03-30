#include "Proiect4.h"
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qpushbutton.h>
#include <qlistwidget.h>
#include <QHBoxLayout>
#include <qformlayout.h>
#include "Validator.h"
#include "Repository.h"
#include "Repository_file.h"
#include "Controller.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
	test_repo();
	test_ctrl();

	Repo repo;
	valid val;
	Repo_F fis;
	serv ser{ repo, val, fis };
	QApplication a(argc, argv);
	
	QWidget* fereastra = new QWidget;

	GUI gui{ ser, fereastra };

	fereastra->show();
	fereastra->setWindowTitle(QApplication::translate("Biblioteca", "Biblioteca"));
	fereastra->setMinimumHeight(720);
	fereastra->setMinimumWidth(1010);

	return a.exec();
}
