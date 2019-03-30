#include "Validator.h"

ostream& operator << (ostream& out, const validator& ex) {
	for (const auto& mes : ex.mes) {
		out << mes << " ";
	}
	return out;
}

void valid::validare(const Carti& c) {
	vector<string> mes;
	if (c.get_titlu().size() == 0) mes.push_back("Titlu vid !!!\n");
	if (c.get_autor().size() == 0) mes.push_back("Autor vid !!!\n");
	if (c.get_titlu().size() == 0) mes.push_back("Gen vid !!!\n");
	if (c.get_an() < 0) mes.push_back("An negativ !!!\n");
	if (mes.size() > 0) {
		throw validator(mes);
	}
}