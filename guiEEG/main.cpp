#include "guieegUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	guiEEG w;
	w.show();

	return a.exec();
}
