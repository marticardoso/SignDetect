#include "FeaturesReduction.h"


FeaturesReduction::FeaturesReduction()
{
}


FeaturesReduction::~FeaturesReduction()
{
}

/**
* Realitza una reducci� de PCA
*/
void FeaturesReduction::makePCA(Mat& features, int numFeat){
	pca = new PCA(features, Mat(), CV_PCA_DATA_AS_ROW, numFeat);
	typeReduction = 1;
}
/**
* Realitza una reducci� de LDA
*/
void FeaturesReduction::makeLDA(Mat& features, Mat& labels){
	lda = new LDA(features, labels);
	typeReduction = 2;
}

/**
* Executa sense reducci�
*/
void FeaturesReduction::noReduction(){
	typeReduction = 0;
}
/**
* Projecta caracteristiques 
*/
void FeaturesReduction::project(Mat& feat, Mat& featOut){

	if (typeReduction == 1) pca->project(feat, featOut);

	if (typeReduction == 2) featOut = lda->project(feat);

	if (typeReduction == 0)	featOut = feat;
}

/**
* Obte el tipus de reducci�
*/
int FeaturesReduction::getType(){
	return typeReduction;
}
/**
* Estableix el tipus de reducci�
*/
void FeaturesReduction::setType(int i){
	if (i >= 0 && i <= 3) 
		typeReduction = i;
}
/**
* Genera reduccio a partir de les caracteristiques i els labels
*/
void FeaturesReduction::generate(Mat& features, Mat& labels){
	if (typeReduction == 1)
		makePCA(features, 0);
	else if (typeReduction == 2)
		makeLDA(features, labels);
	else
		noReduction();
}