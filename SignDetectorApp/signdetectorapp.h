#ifndef SIGNDETECTORAPP_H
#define SIGNDETECTORAPP_H

#include <QtWidgets/QMainWindow>
#include "ui_signdetectorapp.h"
#include "MainClass.h"

class SignDetectorApp : public QMainWindow
{
	Q_OBJECT

public:
	SignDetectorApp(QWidget *parent = 0);
	~SignDetectorApp();
	void addText(String s);
public slots:
	//Passar video/imatge al detector
	void run();
	//Acaba l'execuci�
	void finishExec();
	//Modifica el m�tode de ROI
	void ChangeROIMethod(int i);
	//Crea unes noves xarxes neuronals
	void newClassifier();
	//S'ha modificat la direcci� de la base de dades
	void changeDataSetDir();
signals:

private:
	Ui::SignDetectorAppClass ui;
	MainClass mainClass;
	//Comprova si existeix un fitxer
	static bool fexists(String filename);
	//Direcci� del v�deo per defecte
	QString defaultPathVideo = "E:\\Usuario\\nuovo\\Documents\\videoX.mp4";
	//Direcci� de la base de dades
	QString defaultPathDataSet = "E:\\dataset\\";


};

#endif // SIGNDETECTORAPP_H
