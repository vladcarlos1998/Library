#include "GUI.h"
#include <qboxlayout.h>
#include <qformlayout.h>
#include <qapplication.h>
#include <qmessagebox.h>
#include <qapplication.h>

GUI::GUI(serv& s, QWidget* p) : ui(s), QWidget{ p } {
	this->populateRepo();
	this->elemsRepo = this->ui.get_all();
	this->initGUI();
}

void GUI::initGUI() {
	//0
	QHBoxLayout *coloana = new QHBoxLayout;
	this->setLayout(coloana);

	//1
	QWidget *coloana1 = new QWidget;
	QVBoxLayout *coloana1_ = new QVBoxLayout;
	coloana1->setLayout(coloana1_);
	//1_1
	QWidget *coloana1_1 = new QWidget;
	QHBoxLayout *coloana1_1_ = new QHBoxLayout;
	coloana1_1->setLayout(coloana1_1_);
	this->txtfereastra = new QListWidget;
	coloana1_1_->addWidget(txtfereastra);
	coloana1_->addWidget(coloana1_1);
	//1_2
	QWidget *coloana1_2 = new QWidget;
	QHBoxLayout *coloana1_2_ = new QHBoxLayout;
	coloana1_2->setLayout(coloana1_2_);
	//1_2_1
	QWidget *coloana1_2_1 = new QWidget;
	QFormLayout *coloana1_2_1_ = new QFormLayout;
	coloana1_2_1->setLayout(coloana1_2_1_);
	this->lable_filtru = new QLabel("Element");
	this->line_filtru = new QLineEdit;
	this->line_filtru->setPlaceholderText("Element");
	coloana1_2_1_->addRow(lable_filtru, line_filtru);
	this->RBFCT = new QRadioButton("&Filtreaza cartile dupa titlu");
	this->RBFCA = new QRadioButton("&Filtreaza cartile dupa anul aparitiei");
	coloana1_2_1_->addRow(RBFCT, RBFCA);
	this->BFC = new QPushButton("&Filtreaza");
	coloana1_2_1_->addWidget(BFC);
	QPalette pal = this->BFC->palette();
	pal.setColor(QPalette::Button, QColor(Qt::red));
	this->BFC->setAutoFillBackground(true);
	this->BFC->setPalette(pal);
	this->BFC->update();
	coloana1_2_->addWidget(coloana1_2_1);
	//1_2_2
	QWidget *coloana1_2_2 = new QWidget;
	QVBoxLayout *coloana1_2_2_ = new QVBoxLayout;
	coloana1_2_2->setLayout(coloana1_2_2_);
	this->RBSCT = new QRadioButton("&Sorteaza cartile dupa titlu");
	this->RBSCA = new QRadioButton("&Sorteaza cartile dupa autor");
	this->RBSCAG = new QRadioButton("&Sorteaza cartile dupa anul aparitiei si dupa gen");
	coloana1_2_2_->addWidget(RBSCT);
	coloana1_2_2_->addWidget(RBSCA);
	coloana1_2_2_->addWidget(RBSCAG);
	this->BSC = new QPushButton("&Sorteaza");
	coloana1_2_2_->addWidget(BSC);
	QPalette pal2 = this->BSC->palette();
	pal2.setColor(QPalette::Button, QColor(Qt::red));
	this->BSC->setAutoFillBackground(true);
	this->BSC->setPalette(pal2);
	this->BSC->update();
	coloana1_2_->addWidget(coloana1_2_2);
	coloana1_->addWidget(coloana1_2);
	//1_3
	QWidget *coloana1_3 = new QWidget;
	QHBoxLayout *coloana1_3_ = new QHBoxLayout;
	coloana1_3->setLayout(coloana1_3_);
	this->BP = new QPushButton("&Afisare");
	coloana1_3_->addWidget(BP);
	QPalette pal3 = this->BP->palette();
	pal3.setColor(QPalette::Button, QColor(Qt::red));
	this->BP->setAutoFillBackground(true);
	this->BP->setPalette(pal3);
	this->BP->update();
	coloana1_->addWidget(coloana1_3);

	coloana->addWidget(coloana1);

	//2
	QWidget *coloana2 = new QWidget;
	QVBoxLayout *coloana2_ = new QVBoxLayout;
	coloana2->setLayout(coloana2_);
	//2_1
	QWidget *coloana2_1 = new QWidget;
	QFormLayout *coloana2_1_ = new QFormLayout;
	coloana2_1->setLayout(coloana2_1_);
	this->label_titlu = new QLabel("Titlu");
	this->line_titlu = new QLineEdit;
	this->line_titlu->setPlaceholderText("Titlu");
	coloana2_1_->addRow(label_titlu, line_titlu);
	this->label_autor = new QLabel("Autor");
	this->line_autor = new QLineEdit;
	line_autor->setPlaceholderText("Autor");
	coloana2_1_->addRow(label_autor, line_autor);
	this->label_gen = new QLabel("Gen");
	this->line_gen = new QLineEdit;
	line_gen->setPlaceholderText("Gen");
	coloana2_1_->addRow(label_gen, line_gen);
	this->label_an = new QLabel("An aparitie");
	this->line_an = new QLineEdit;
	line_an->setPlaceholderText("An aparitie");
	coloana2_1_->addRow(label_an, line_an);
	//2_2
	QWidget *coloana2_2 = new QWidget;
	QVBoxLayout *coloana2_2_ = new QVBoxLayout;
	coloana2_2->setLayout(coloana2_2_);
	this->ADD = new QPushButton("&Adaugare");
	coloana2_2_->addWidget(ADD);
	QPalette pal4 = this->ADD->palette();
	pal4.setColor(QPalette::Button, QColor(Qt::blue));
	this->ADD->setAutoFillBackground(true);
	this->ADD->setPalette(pal4);
	this->ADD->update();
	coloana2_1_->addWidget(coloana2_2);
	coloana2_->addWidget(coloana2_1);
	//2_3
	QWidget *coloana2_3 = new QWidget;
	QVBoxLayout *coloana2_3_ = new QVBoxLayout;
	coloana2_3->setLayout(coloana2_3_);
	//1
	QWidget *rand = new QWidget;
	QFormLayout *rand_ = new QFormLayout;
	rand->setLayout(rand_);
	this->label_rem_titlu = new QLabel("Titlu");
	this->line_rem_titlu = new QComboBox;
	rand_->addRow(label_rem_titlu, line_rem_titlu);
	this->label_rem_autor = new QLabel("Autor");
	this->line_rem_autor = new QComboBox;
	rand_->addRow(label_rem_autor, line_rem_autor);
	coloana2_3_->addWidget(rand);
	//2
	QWidget *randd = new QWidget;
	QFormLayout *randd_ = new QFormLayout;
	randd->setLayout(randd_);
	this->REM = new QPushButton("Scoatere");
	randd_->addWidget(REM);
	QPalette pal5 = this->REM->palette();
	pal5.setColor(QPalette::Button, QColor(Qt::blue));
	this->REM->setAutoFillBackground(true);
	this->REM->setPalette(pal5);
	this->REM->update();
	coloana2_3_->addWidget(randd);

	coloana2_->addWidget(coloana2_3);
	//2_4
	QWidget *coloana2_4 = new QWidget;
	QVBoxLayout *coloana2_4_ = new QVBoxLayout;
	coloana2_4->setLayout(coloana2_4_);
	//1
	QWidget* rand1 = new QWidget;
	QFormLayout* rand1_ = new QFormLayout;
	rand1->setLayout(rand1_);
	this->label_upd_titlu = new QLabel("Titlu");
	this->line_upd_titlu = new QLineEdit;
	this->line_upd_titlu->setPlaceholderText("Titlu");
	this->label_upd_autor = new QLabel("Autor");
	this->line_upd_autor = new QLineEdit;
	this->line_upd_autor->setPlaceholderText("Autor");
	rand1_->addRow(label_upd_titlu, line_upd_titlu);
	rand1_->addRow(label_upd_autor, line_upd_autor);
	coloana2_4_->addWidget(rand1);
	//2
	QWidget* rand2 = new QWidget;
	QFormLayout* rand2_ = new QFormLayout;
	rand2->setLayout(rand2_);
	this->label_upd = new QLabel("Element");
	this->linie_upd = new QLineEdit;
	this->linie_upd->setPlaceholderText("Element");
	rand2_->addRow(label_upd, linie_upd);
	coloana2_4_->addWidget(rand2);
	//3
	QWidget* rand3 = new QWidget;
	QFormLayout* rand3_ = new QFormLayout;
	rand3->setLayout(rand3_);
	this->RBUT = new QRadioButton("&Titlu");
	this->RBUA = new QRadioButton("&Autor");
	this->RBUG = new QRadioButton("&Gen");
	this->RBUAA = new QRadioButton("&Anul aparitiei");
	rand3_->addRow(RBUT, RBUA);
	rand3_->addRow(RBUG, RBUAA);
	coloana2_4_->addWidget(rand3);
	//4
	QWidget* rand4 = new QWidget;
	QFormLayout* rand4_ = new QFormLayout;
	rand4->setLayout(rand4_);
	this->UPD = new QPushButton("&Modificare");
	rand4_->addWidget(UPD);
	QPalette pal6 = this->UPD->palette();
	pal6.setColor(QPalette::Button, QColor(Qt::blue));
	this->UPD->setAutoFillBackground(true);
	this->UPD->setPalette(pal6);
	this->UPD->update();
	coloana2_4_->addWidget(rand4);

	coloana2_->addWidget(coloana2_4);
	//2_5
	QWidget *coloana2_5 = new QWidget;
	QVBoxLayout *coloana2_5_ = new QVBoxLayout;
	coloana2_5->setLayout(coloana2_5_);
	this->UNDO = new QPushButton("Undo");
	coloana2_5_->addWidget(UNDO);
	QPalette pal7 = this->UNDO->palette();
	pal7.setColor(QPalette::Button, QColor(Qt::blue));
	this->UNDO->setAutoFillBackground(true);
	this->UNDO->setPalette(pal7);
	this->UNDO->update();
	this->COS = new QPushButton("Gestionare cos");
	coloana2_5_->addWidget(COS);
	QPalette pal8 = this->COS->palette();
	pal8.setColor(QPalette::Button, QColor(Qt::blue));
	this->COS->setAutoFillBackground(true);
	this->COS->setPalette(pal8);
	this->COS->update();
	this->HIS = new QPushButton("Istoric");
	coloana2_5_->addWidget(HIS);
	QPalette pal14 = this->HIS->palette();
	pal14.setColor(QPalette::Button, QColor(Qt::blue));
	this->HIS->setAutoFillBackground(true);
	this->HIS->setPalette(pal14);
	this->HIS->update();
	coloana2_->addWidget(coloana2_5);
	//2_6
	QWidget *coloana2_6 = new QWidget;
	QVBoxLayout *coloana2_6_ = new QVBoxLayout;
	coloana2_6->setLayout(coloana2_6_);
	this->EXIT = new QPushButton("EXIT");
	coloana2_6_->addWidget(EXIT);
	QPalette pal9 = this->EXIT->palette();
	pal9.setColor(QPalette::Button, QColor(Qt::blue));
	this->EXIT->setAutoFillBackground(true);
	this->EXIT->setPalette(pal9);
	this->EXIT->update();
	coloana2_->addWidget(coloana2_6);

	coloana->addWidget(coloana2);

	/*//3
	QWidget* coloana3 = new QWidget;
	QVBoxLayout* coloana3_ = new QVBoxLayout;
	coloana3->setLayout(coloana3_);
	//3_1
	QWidget* coloana3_1 = new QWidget;
	QFormLayout* coloana3_1_ = new QFormLayout;
	coloana3_1->setLayout(coloana3_1_);
	this->label_cos_titlu = new QLabel("Titlu");
	this->line_cos_titlu = new QComboBox;
	coloana3_1_->addRow(label_cos_titlu, line_cos_titlu);
	this->label_cos_autor = new QLabel("Autor");
	this->line_cos_autor = new QComboBox;
	coloana3_1_->addRow(label_cos_autor, line_cos_autor);
	this->ADDC = new QPushButton("&Adaugare");
	coloana3_1_->addWidget(ADDC);
	QPalette pal10 = this->ADDC->palette();
	pal10.setColor(QPalette::Button, QColor(Qt::green));
	this->ADDC->setAutoFillBackground(true);
	this->ADDC->setPalette(pal10);
	this->ADDC->update();
	coloana3_->addWidget(coloana3_1);
	//3_2
	QWidget* coloana3_2 = new QWidget;
	QFormLayout* coloana3_2_ = new QFormLayout;
	coloana3_2->setLayout(coloana3_2_);
	this->label_pop_cos = new QLabel("Nr. Elemente");
	this->line_pop_cos = new QComboBox;
	coloana3_2_->addRow(label_pop_cos, line_pop_cos);
	this->POP = new QPushButton("&Populare");
	coloana3_2_->addWidget(POP);
	QPalette pal11 = this->POP->palette();
	pal11.setColor(QPalette::Button, QColor(Qt::green));
	this->POP->setAutoFillBackground(true);
	this->POP->setPalette(pal11);
	this->POP->update();
	coloana3_->addWidget(coloana3_2);
	//3_3
	QWidget* coloana3_3 = new QWidget;
	QVBoxLayout* coloana3_3_ = new QVBoxLayout;
	coloana3_3->setLayout(coloana3_3_);
	this->REMC = new QPushButton("&Stergere");
	coloana3_3_->addWidget(REMC);
	QPalette pal12 = this->REMC->palette();
	pal12.setColor(QPalette::Button, QColor(Qt::green));
	this->REMC->setAutoFillBackground(true);
	this->REMC->setPalette(pal12);
	this->REMC->update();
	this->BPC = new QPushButton("&Afisare");
	coloana3_3_->addWidget(BPC);
	QPalette pal13 = this->BPC->palette();
	pal13.setColor(QPalette::Button, QColor(Qt::green));
	this->BPC->setAutoFillBackground(true);
	this->BPC->setPalette(pal13);
	this->BPC->update();
	coloana3_->addWidget(coloana3_3);

	coloana3_->addStretch();
	coloana->addWidget(coloana3);*/

	this->connectSignalsAndSlots();
	this->print();
	this->initstergereGUI();
	//this->initadauga_cos();
	//this->initpopulareGUI();
	this->cosGUI();
}

void GUI::populateRepo() {
	this->ui.adauga("Inferno", "Dan_Brown", "Mystery", 2013);
	this->ui.adauga("Eragon", "Christopher_Paolini", "Fantasy", 2002);
	this->ui.adauga("Exorcistul", "William_Peter_Blatty", "Horror", 1971);
	this->ui.adauga("Catarul", "Stanislaw_Lem", "Mystery", 2014);
	this->ui.adauga("Sobolanii", "James_Herbert", "Thriller", 1974);
	this->ui.adauga("Ultimul_Templier", "Raymond_Khoury", "Mystery", 2005);
	this->ui.adauga("Shogun", "James_Clavell", "Historical_fiction", 1975);
	this->ui.adauga("Dracula", "Bram_Stoker", "Horror", 1897);
	this->ui.adauga("Notre-Dame_de_Paris", "Victor_Hugo", "Romanticism", 1831);
	this->ui.adauga("A_Connecticut_Yankee_in_King_Arthur's_Court", "Mark_Twain", "Humor", 1889);
}

void GUI::print() {
	this->txtfereastra->clear();
	for (const auto& c : this->ui.get_all()) {
		this->txtfereastra->addItem(">> " + QString::fromStdString(c.get_titlu()) + "   " + QString::fromStdString(c.get_autor()) + "  " + QString::fromStdString(c.get_gen()) + "  " + QString::number(c.get_an()));
	}
}

void GUI::adaugaGUI() {
	try {
		this->ui.adauga(this->line_titlu->text().toStdString(), this->line_autor->text().toStdString(), this->line_gen->text().toStdString(), this->line_an->text().toInt());
	}
	catch (RepoException& ex) {
		QMessageBox mess;
		mess.critical(0, "ERROR", "Problema legata de existenta elementului");
		return;
	}
	catch(validator& ex){
		QMessageBox mess;
		mess.critical(0, "ERROR", "Problema legata de corectitudinea parametrilor elementului");
		return;
	}
	this->line_rem_titlu->clear();
	this->line_rem_autor->clear();
	this->initstergereGUI();
	this->initadauga_cos();
	this->initpopulareGUI();
	this->line_titlu->clear();
	this->line_autor->clear();
	this->line_gen->clear();
	this->line_an->clear();
	this->print();
}

void GUI::stergeGUI() {
	try{
		this->ui.sterge(this->line_rem_titlu->currentText().toStdString(), this->line_rem_autor->currentText().toStdString());
	}
	catch (RepoException& ex) {
		QMessageBox mess;
		mess.critical(0, "ERROR", "Problema legata de inexistenta elementului");
		return;
	}
	catch (validator& ex) {
		QMessageBox mess;
		mess.critical(0, "ERROR", "Problema legata de corectitudinea parametrilor elementului");
		return;
	}
	this->line_rem_titlu->clear();
	this->line_rem_autor->clear();
	this->initstergereGUI();
	this->initadauga_cos();
	this->initpopulareGUI();
	this->print();
}

void GUI::filtrareGUI() {
	if (this->RBFCT->isChecked() == true) {
		vector<Carti>lst = this->ui.filtru_titlu(this->line_filtru->text().toStdString());
		this->line_filtru->clear();
		this->txtfereastra->clear();
		for (const auto& c : lst) {
			this->txtfereastra->addItem(">> " + QString::fromStdString(c.get_titlu()) + "   " + QString::fromStdString(c.get_autor()) + "  " + QString::fromStdString(c.get_gen()) + "  " + QString::number(c.get_an()));
		}
	}
	if (this->RBFCA->isChecked() == true) {
		vector<Carti>lst = this->ui.filtru_anul_aparitiei(this->line_filtru->text().toInt());
		this->line_filtru->clear();
		this->txtfereastra->clear();
		for (const auto& c : lst) {
			this->txtfereastra->addItem(">> " + QString::fromStdString(c.get_titlu()) + "   " + QString::fromStdString(c.get_autor()) + "  " + QString::fromStdString(c.get_gen()) + "  " + QString::number(c.get_an()));
		}
	}
}

void GUI::sortareGUI() {
	if (this->RBSCT->isChecked() == true) {
		vector<Carti> lst = this->ui.sort_titlu();
		this->txtfereastra->clear();
		for (const auto& c : lst) {
			this->txtfereastra->addItem(">> " + QString::fromStdString(c.get_titlu()) + "   " + QString::fromStdString(c.get_autor()) + "  " + QString::fromStdString(c.get_gen()) + "  " + QString::number(c.get_an()));
		}
	}
	if (this->RBSCA->isChecked() == true) {
		vector<Carti> lst = this->ui.sort_autor();
		this->txtfereastra->clear();
		for (const auto& c : lst) {
			this->txtfereastra->addItem(">> " + QString::fromStdString(c.get_titlu()) + "   " + QString::fromStdString(c.get_autor()) + "  " + QString::fromStdString(c.get_gen()) + "  " + QString::number(c.get_an()));
		}
	}
	if (this->RBSCAG->isChecked() == true) {
		vector<Carti> lst = this->ui.sort_an_gen();
		this->txtfereastra->clear();
		for (const auto& c : lst) {
			this->txtfereastra->addItem(">> " + QString::fromStdString(c.get_titlu()) + "   " + QString::fromStdString(c.get_autor()) + "  " + QString::fromStdString(c.get_gen()) + "  " + QString::number(c.get_an()));
		}
	}
}

void GUI::modificaGUI() {
	if (this->RBUT->isChecked() == true) {
		try {
			this->Histori.push_back(this->ui.cauta(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), this->ui.get_all()));
		this->ui.modificare(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), '1', this->linie_upd->text().toStdString(), 0);
		}
		catch (RepoException& ex) {
			QMessageBox mess;
			mess.critical(0, "ERROR", "Problema legata de inexistenta elementului");
			return;
		}
		catch (validator& ex) {
			QMessageBox mess;
			mess.critical(0, "ERROR", "Problema legata de corectitudinea parametrilor elementului");
			return;
		}
		this->line_rem_titlu->clear();
		this->line_rem_autor->clear();
		this->initstergereGUI();
		this->initadauga_cos();
		this->initpopulareGUI();
		this->line_upd_titlu->clear();
		this->line_upd_titlu->insert(this->linie_upd->text());
		this->linie_upd->clear();
		this->print();
		this->Histori.push_back(this->ui.cauta(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), this->ui.get_all()));
	}
	if (this->RBUA->isChecked() == true) {
		try {
			this->Histori.push_back(this->ui.cauta(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), this->ui.get_all()));
		this->ui.modificare(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), '2', this->linie_upd->text().toStdString(), 0);
		}
		catch (RepoException& ex) {
			QMessageBox mess;
			mess.critical(0, "ERROR", "Problema legata de inexistenta elementului");
			return;
		}
		catch (validator& ex) {
			QMessageBox mess;
			mess.critical(0, "ERROR", "Problema legata de corectitudinea parametrilor elementului");
			return;
		}
		this->line_rem_titlu->clear();
		this->line_rem_autor->clear();
		this->initstergereGUI();
		this->initadauga_cos();
		this->initpopulareGUI();
		this->line_upd_autor->clear();
		this->line_upd_autor->insert(this->linie_upd->text());
		this->linie_upd->clear();
		this->print();
		this->Histori.push_back(this->ui.cauta(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), this->ui.get_all()));
	}
	if (this->RBUG->isChecked() == true) {
		try {
			this->Histori.push_back(this->ui.cauta(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), this->ui.get_all()));
		this->ui.modificare(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), '3', this->linie_upd->text().toStdString(), 0);
		}
		catch (RepoException& ex) {
			QMessageBox mess;
			mess.critical(0, "ERROR", "Problema legata de inexistenta elementului");
			return;
		}
		catch (validator& ex) {
			QMessageBox mess;
			mess.critical(0, "ERROR", "Problema legata de corectitudinea parametrilor elementului");
			return;
		}
		this->line_rem_titlu->clear();
		this->line_rem_autor->clear();
		this->initstergereGUI();
		this->initadauga_cos();
		this->initpopulareGUI();
		this->linie_upd->clear();
		this->print();
		this->Histori.push_back(this->ui.cauta(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), this->ui.get_all()));
	}
	if (this->RBUAA->isChecked() == true) {
		try {
			this->Histori.push_back(this->ui.cauta(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), this->ui.get_all()));
		this->ui.modificare(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), '4', "", this->linie_upd->text().toInt());
		}
		catch (RepoException& ex) {
			QMessageBox mess;
			mess.critical(0, "ERROR", "Problema legata de inexistenta elementului");
			return;
		}
		catch (validator& ex) {
			QMessageBox mess;
			mess.critical(0, "ERROR", "Problema legata de corectitudinea parametrilor elementului");
			return;
		}
		this->line_rem_titlu->clear();
		this->line_rem_autor->clear();
		this->initstergereGUI();
		this->initadauga_cos();
		this->initpopulareGUI();
		this->linie_upd->clear();
		this->print();
		this->Histori.push_back(this->ui.cauta(this->line_upd_titlu->text().toStdString(), this->line_upd_autor->text().toStdString(), this->ui.get_all()));
	}
}

void GUI::initstergereGUI() {
	for (const auto& c : this->ui.get_all()) {
		this->line_rem_titlu->addItem(QString::fromStdString(c.get_titlu()));
		this->line_rem_autor->addItem(QString::fromStdString(c.get_autor()));
	}
}

void GUI::undoGUI() {
	try {
		this->ui.Undo();
	}
	catch (RepoException& ex) {
		QMessageBox mes;
		mes.critical(0, "ERROR", "Lista goala");
		return;
	}
	this->line_rem_titlu->clear();
	this->line_rem_autor->clear();
	this->initstergereGUI();
	this->initadauga_cos();
	this->initpopulareGUI();
	this->print();
}


/*void GUI::cosGUI() {
	QWidget* fereastra2 = new QWidget;

	GUI_COS gui_cos{ this->ui, fereastra2 };

	gui_cos.setModel(true);

	fereastra2->show();
	fereastra2->setWindowTitle(QApplication::translate("Cos", "Cos"));
}*/

void GUI::printC() {
	this->list_cos->clear();
	for (const auto& c : this->ui.get_cos()) {
		this->list_cos->addItem(">> " + QString::fromStdString(c.get_titlu()) + "   " + QString::fromStdString(c.get_autor()) + "  " + QString::fromStdString(c.get_gen()) + "  " + QString::number(c.get_an()));
	}
	this->p.close();
	this->p.set_cate(this->ui.size_get_cos());
	this->p.show();
}

void GUI::initadauga_cos() {
	this->line_cos_titlu->clear();
	this->line_cos_autor->clear();
	for (const auto& c : this->ui.get_all()) {
		this->line_cos_titlu->addItem(QString::fromStdString(c.get_titlu()));
		this->line_cos_autor->addItem(QString::fromStdString(c.get_autor()));
	}
}

void GUI::adauga_cosGUI() {
	try {
		this->ui.adauga_cos(this->line_cos_titlu->currentText().toStdString(), this->line_cos_autor->currentText().toStdString());

	}
	catch (RepoException ex) {
		QMessageBox mess;
		mess.critical(0, "ERROR", "Problema legata de existenta elementului");
		return;
	}
	this->printC();

}

void GUI::initpopulareGUI() {
	int i = 1;
	this->line_pop_cos->clear();
	for (const auto& c : this->ui.get_all()) {
		this->line_pop_cos->addItem(QString::fromStdString(to_string(i)));
		i++;
	}
}

void GUI::populareGUI() {
	this->ui.sterge_cos();
	try {
		this->ui.pop_cos(this->line_pop_cos->currentText().toInt());
	}
	catch (RepoException ex) {
		QMessageBox mess;
		mess.critical(0, "ERROR", "Problema legata de existenta elementului");
		return;
	}
	this->printC();
}

void GUI::sterge_cosGUI() {
	this->ui.sterge_cos();
	this->printC();
}

void GUI::exitGUI() {
	this->ui.afis_fis();
	this->ui.rem_Undo();
	//this->ui.sterge_cos();
	GUI::close();
}

void GUI::cosGUI() {
	//this->DLog = new QDialog(this);
	this->DLog = new QWidget;
	this->DLog->setWindowTitle("cos");
	QHBoxLayout* lay = new QHBoxLayout;
	this->DLog->setLayout(lay);
	this->list_cos = new QListWidget;
	lay->addWidget(this->list_cos);
	//3
	QWidget* coloana3 = new QWidget;
	QVBoxLayout* coloana3_ = new QVBoxLayout;
	coloana3->setLayout(coloana3_);
	//3_1
	QWidget* coloana3_1 = new QWidget;
	QFormLayout* coloana3_1_ = new QFormLayout;
	coloana3_1->setLayout(coloana3_1_);
	this->label_cos_titlu = new QLabel("Titlu");
	this->line_cos_titlu = new QComboBox;
	coloana3_1_->addRow(label_cos_titlu, line_cos_titlu);
	this->label_cos_autor = new QLabel("Autor");
	this->line_cos_autor = new QComboBox;
	coloana3_1_->addRow(label_cos_autor, line_cos_autor);
	this->ADDC = new QPushButton("&Adaugare");
	coloana3_1_->addWidget(ADDC);
	QPalette pal10 = this->ADDC->palette();
	pal10.setColor(QPalette::Button, QColor(Qt::green));
	this->ADDC->setAutoFillBackground(true);
	this->ADDC->setPalette(pal10);
	this->ADDC->update();
	coloana3_->addWidget(coloana3_1);
	//3_2
	QWidget* coloana3_2 = new QWidget;
	QFormLayout* coloana3_2_ = new QFormLayout;
	coloana3_2->setLayout(coloana3_2_);
	this->label_pop_cos = new QLabel("Nr. Elemente");
	this->line_pop_cos = new QComboBox;
	coloana3_2_->addRow(label_pop_cos, line_pop_cos);
	this->POP = new QPushButton("&Populare");
	coloana3_2_->addWidget(POP);
	QPalette pal11 = this->POP->palette();
	pal11.setColor(QPalette::Button, QColor(Qt::green));
	this->POP->setAutoFillBackground(true);
	this->POP->setPalette(pal11);
	this->POP->update();
	coloana3_->addWidget(coloana3_2);
	//3_3
	QWidget* coloana3_3 = new QWidget;
	QVBoxLayout* coloana3_3_ = new QVBoxLayout;
	coloana3_3->setLayout(coloana3_3_);
	this->REMC = new QPushButton("&Stergere");
	coloana3_3_->addWidget(REMC);
	QPalette pal12 = this->REMC->palette();
	pal12.setColor(QPalette::Button, QColor(Qt::green));
	this->REMC->setAutoFillBackground(true);
	this->REMC->setPalette(pal12);
	this->REMC->update();
	this->BPC = new QPushButton("&Afisare");
	coloana3_3_->addWidget(BPC);
	QPalette pal13 = this->BPC->palette();
	pal13.setColor(QPalette::Button, QColor(Qt::green));
	this->BPC->setAutoFillBackground(true);
	this->BPC->setPalette(pal13);
	this->BPC->update();
	coloana3_->addWidget(coloana3_3);

	coloana3_->addStretch();
	lay->addWidget(coloana3);
	this->connectSignalsAndSlots_cos();
	this->initadauga_cos();
	this->initpopulareGUI();
	//DLog->exec();
	this->p.set_cate(this->ui.size_get_cos());

	DLog->show();

	//this->p.show();
}

/*void GUI::paintEvent(QPaintEvent* ev) {
	QPainter painter(this);
	QLineF line(10, 10, 100, 100);
	painter.drawLine(line);
}*/

void GUI::istoricGUI() {
	this->txtfereastra->clear();
	for (int i = 0; i < this->Histori.size(); i = i + 2) {
		this->txtfereastra->addItem(">> " + QString::fromStdString(this->Histori[i].get_titlu()) + "   " + QString::fromStdString(this->Histori[i].get_autor()) + "  " + QString::fromStdString(this->Histori[i].get_gen()) + "  " + QString::number(this->Histori[i].get_an()) + " -> " + QString::fromStdString(this->Histori[i + 1].get_titlu()) + "   " + QString::fromStdString(this->Histori[i + 1].get_autor()) + "  " + QString::fromStdString(this->Histori[i + 1].get_gen()) + "  " + QString::number(this->Histori[i + 1].get_an()));
	}
}

void GUI::connectSignalsAndSlots() {
	QObject::connect(this->BP, SIGNAL(clicked()), this, SLOT(print()));
	QObject::connect(this->ADD, SIGNAL(clicked()), this, SLOT(adaugaGUI()));
	QObject::connect(this->REM, SIGNAL(clicked()), this, SLOT(stergeGUI()));
	QObject::connect(this->BFC, SIGNAL(clicked()), this, SLOT(filtrareGUI()));
	QObject::connect(this->BSC, SIGNAL(clicked()), this, SLOT(sortareGUI()));
	QObject::connect(this->UPD, SIGNAL(clicked()), this, SLOT(modificaGUI()));
	QObject::connect(this->UNDO, SIGNAL(clicked()), this, SLOT(undoGUI()));
	//QObject::connect(this->COS, SIGNAL(clicked()), this, SLOT(cosGUI()));
	/*QObject::connect(this->BPC, SIGNAL(clicked()), this, SLOT(printC()));
	QObject::connect(this->ADDC, SIGNAL(clicked()), this, SLOT(adauga_cosGUI()));
	QObject::connect(this->POP, SIGNAL(clicked()), this, SLOT(populareGUI()));
	QObject::connect(this->REMC, SIGNAL(clicked()), this, SLOT(sterge_cosGUI()));*/
	QObject::connect(this->COS, SIGNAL(clicked()), this, SLOT(cosGUI()));
	QObject::connect(this->HIS, SIGNAL(clicked()), this, SLOT(istoricGUI()));
	QObject::connect(this->EXIT, SIGNAL(clicked()), this, SLOT(exitGUI()));
}

void GUI::connectSignalsAndSlots_cos() {
	QObject::connect(this->BPC, SIGNAL(clicked()), this, SLOT(printC()));
	QObject::connect(this->ADDC, SIGNAL(clicked()), this, SLOT(adauga_cosGUI()));
	QObject::connect(this->POP, SIGNAL(clicked()), this, SLOT(populareGUI()));
	QObject::connect(this->REMC, SIGNAL(clicked()), this, SLOT(sterge_cosGUI()));
}