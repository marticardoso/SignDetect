#ifndef MAINCLASS_H
#define MAINCLASS_H
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "ComputeROI.h"
#include "SignDetector.h"
#include "FeaturesFinder.h"
#include "Classifier.h"
#include "QTTerminal.h"
#include "QOpenGLWCustom.h"


#include <time.h> 

class MainClass
{
public:
	MainClass();
	~MainClass();
	//Executa el detector amb el video del path
	void visualitzaVideo(String path);
	//Executa el detector amb la imatge del path
	void visualitzaImatge(String path);
	//Estableix el directori de la base de dades
	void setNewDirectoryDataset(String path);
	//Acaba execuci� del v�deo
	void finishExec();
	//Genera un nou classificador
	void generateNewClassifier();
	//Selecciona el m�tode de ROI
	void setRoiMethod(int m);
	// Genera una nova xarxa neuronal
	void newClassifier();
	//Estableix el QTerminal
	void setTerminal(QTTerminal* t);
	//Estableix la finestra OpenGL
	void setOpenGl(QOpenGLWCustom* ogl);
private:
	//Tracta un frame
	void tractarFrame(Mat& frame);
	//Dibuixa un frame a la finestra
	void drawFrame(Mat& frame, vector<pair<Rect, Mat> >& detSigns);

	ComputeROI cROI;
	SignDetector signDet;
	Classifier classifier;

	//Indica si s'est� reproduint un v�deo
	bool isRunning = false;

	int numFrames = 0;
	int clocIni = 0;

	QTTerminal* terminal = NULL;
	QOpenGLWCustom* openGl = NULL;
};
#endif
