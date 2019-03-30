#pragma once
#include "Controller.h"
//#include "GUI_COS.h"
#include <qwidget.h>
#include <qpushbutton.h>
#include <qlabel.h>
#include <qlistwidget.h>
#include <qlineedit.h>
#include <qtextedit.h>
#include <qradiobutton.h>
#include <qcombobox.h>
#include <qpainter.h>

class pain : public QWidget{
public:
	pain(int cate) :cate{ cate } {}

	void set_cate(int c) { cate = c; }
private:
	int cate;
protected:
	void paintEvent(QPaintEvent* ev) {
		QPainter p{ this };
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		for (int i = 0; i < this->cate; i++) {
			x1 = x1 + 10;
			y1 = y1 + 10;
			x2 = x2 + 20;
			y2 = y2 + 20;
			p.drawRect(x1, y1, x2, y2);
		}
	}
};

class GUI : public QWidget {
	Q_OBJECT
public:
	GUI(serv& srv, QWidget* p = 0);
	~GUI() {}

private:
	QListWidget * txtfereastra;

	QLabel* lable_filtru;
	QLineEdit* line_filtru;
	QRadioButton* RBFCT;
	QRadioButton* RBFCA;
	QPushButton *BFC;
	QRadioButton *RBSCT;
	QRadioButton *RBSCA;
	QRadioButton *RBSCAG;
	QPushButton *BSC;

	QPushButton *BP;

	QLabel *label_titlu;
	QLineEdit *line_titlu;
	QLabel *label_autor;
	QLineEdit *line_autor;
	QLabel *label_gen;
	QLineEdit *line_gen;
	QLabel *label_an;
	QLineEdit *line_an;

	QPushButton *ADD;
	QPushButton *REM;
	QPushButton *UPD;
	QPushButton *UNDO;
	QPushButton *COS;
	QPushButton *HIS;

	QPushButton *EXIT;

	QLabel* label_upd_titlu;
	QLineEdit* line_upd_titlu;
	QLabel* label_upd_autor;
	QLineEdit* line_upd_autor;
	QLabel* label_upd;
	QLineEdit* linie_upd;
	QRadioButton* RBUT;
	QRadioButton* RBUA;
	QRadioButton* RBUG;
	QRadioButton* RBUAA;

	QLabel* label_rem_titlu;
	QComboBox* line_rem_titlu;
	QLabel* label_rem_autor;
	QComboBox* line_rem_autor;

	QLabel* label_cos_titlu;
	QComboBox* line_cos_titlu;
	QLabel* label_cos_autor;
	QComboBox* line_cos_autor;
	QPushButton* ADDC;
	QLabel* label_pop_cos;
	QComboBox* line_pop_cos;
	QPushButton* POP;
	QPushButton* REMC;
	QPushButton* BPC;

	//QDialog* DLog;
	QWidget* DLog;
	QListWidget* list_cos;
	pain p{ 0 };

	serv& ui;

	void initGUI();
	vector<Carti> elemsRepo;
	vector<Carti> Histori;
	void populateRepo();
	//void paintEvent(QPaintEvent* ev);

	private slots:

	void adaugaGUI();

	void stergeGUI();

	void initstergereGUI();

	//void initmodificare();

	void modificaGUI();

	//void findGUI();

	void filtrareGUI();

	void sortareGUI();

	void print();

	void undoGUI();

	void printC();

	void initadauga_cos();

	void adauga_cosGUI();

	void initpopulareGUI();

	void populareGUI();

	void sterge_cosGUI();

	void cosGUI();

	void exitGUI();

	void istoricGUI();

	void connectSignalsAndSlots();
	void connectSignalsAndSlots_cos();
};