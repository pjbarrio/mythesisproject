/*
 * DWTAlgorithm.cpp
 *
 *  Created on: 24/01/2009
 *      Author: Pablo
 */

#include "DTWAlgorithm.h"
#include "math.h"
#include "DTWDataHandler.h"
#include "vector.h"

#define INF 9999999.9;

/*
 * This method saves the DistanceCalculator instance.
 */

DTWAlgorithm::DTWAlgorithm(DistanceCalculator *distanceCalculator)
{
	cout << "Hello DTWAlgorithm\n";
	this->distanceCalculator = distanceCalculator;
}

/*
 * This method dereferences the distance calculator object.
 */

DTWAlgorithm::~DTWAlgorithm()
{
	cout << "Bye DTWAlgorithm\n";

	distanceCalculator = 0;
}
/*
 * This mehod returns de DTW value that has been computed from the parameter data.
 */

double DTWAlgorithm::computeDTWValue(DTWData *fstSerie, DTWData *scdSerie)
{
	int n1 = fstSerie->getXYPairCount() + 1;
	int n2 = scdSerie->getXYPairCount() + 1;

	vector<vector<double> > matrix;

	calculateMatrix(fstSerie,scdSerie,matrix);


	matrix[0][0] = 0.0;

	int infj;
	int supj;

	//For monotonicity

	int i;
	int j;

	for(i = 1;i < n1 ; i++){

		infj = getInfValue(i,n1,n2);

		supj = getSupValue(i,n1,n2);



		for (j=infj ; j<=supj ; j++){

			matrix[i][j] = min(matrix[i-1][j] , min(matrix[i-1][j-1], matrix[i][j-1])) + matrix[i][j];

		}

	}


	return matrix[i-1][j-1];

}




/*
 * This method generates the distance matrix used to calculate dtwValue.
 * The first row and the first column have INF value
 */

void DTWAlgorithm::calculateMatrix(DTWData *fstSerie, DTWData *scdSerie,vector<vector<double> > &ret)
{
	/*
	 * matriz = new TIPO* [fil];
	 * for (i = 0; i < fil; ++i)
	 * matriz[i] = new TIPO [col];
	 */

	int n1 = fstSerie->getXYPairCount()+1;
	int n2 = scdSerie->getXYPairCount()+1;

	/*double **ret = new double*[n1];
	for (int var = 0; var < n1; ++var) {
		ret[n1] = new double[n2];
	}*/


	// Set up sizes. (n1 x n2)
	ret.resize(n1);
	for (int i = 0; i < n1; ++i)
	    ret[i].resize(n2);

	int i;
	int j;

	//Init Matrix


	for(i=0;i<n1;i++)
		for(j=0;j<n2;j++)
		{
			ret[i][j] = INF;
		}


	double x1,y1,x2,y2;
	double *x1s,*y1s,*x2s,*y2s;

	DTWDataHandler::DTWDataToDouble(fstSerie,x1s,y1s);
	DTWDataHandler::DTWDataToDouble(scdSerie,x2s,y2s);

	int infj;
	int supj;

	for(i=1;i<n1;i++){
		x1 = x1s[i];
		y1 = y1s[i];
		infj = getInfValue(i,n1,n2);
		supj = getSupValue(i,n1,n2);
		for(j=infj;j<=supj;j++)
		{
			x2 = x2s[j];
			y2 = y2s[j];
			ret[i][j] = calculateDistance(x1,y1,x2,y2);
		}
	}
}


/*
 * This method returns the distance calculated by DistanceCalculator given
 * in the constructor method
 */

double DTWAlgorithm::calculateDistance(double x1, double y1, double x2, double y2)
{
	return getDistanceCalculator()->calculateDistance(x1,y1,x2,y2);
}



















