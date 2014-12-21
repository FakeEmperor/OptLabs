#include <sstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <vector>
#include "tree.h"

using namespace std;

namespace LabOptimizations {
	//TYPEDEFS AND FORWARD DECLARATIONS
	typedef TreeNode<float**> FloatTreeNode;
	typedef std::vector<std::vector<float>> Matrix;
	class SimplexMatrix;
	typedef TreeNode<SimplexMatrix> SimplexMatrixNode;

	//ENUMS

	enum Labs
	{
		LAB_1,
		LAB_2,
		LAB_3,
		LAB_5,
		LAB_MAX = LAB_5
	};

	enum SolutionStatus {
		SS_NONE = 0x00,
		SS_INTEGER_FUNCTION_VALUE = 0x10,
		SS_INTEGER_BASE_COEFFICIENTS = 0x20,
	};
	//PUBLIC UTILS FUNCTIONS

	
	
	bool CloseToZero(double a);
	//is_f_integer - является ли f - целым
	bool IsInteger(float a);
	//возвращает тру, если весь первый столбец - целочисленный

	//CLASSES

	class SimplexMatrix : public Matrix {
		int max_x;
		
		std::vector<int> line_labels;
		std::vector<int> row_labels;
	protected:
		void addLineLabel();
		void addRowLabel();
		void genLabels();
		void swapLabels(size_t line, size_t row);
	public:
		//базовый оверрайд
		SimplexMatrix(const Matrix& m);
		SimplexMatrix(const SimplexMatrix& m);
		SimplexMatrix();
		SimplexMatrix& operator = (const Matrix& m);
		//В строку
		std::string toString() const;
		//Дефолтный конструктор - не нужно самим ничего удалять
		//ПУБЛИЧНЫЕ МЕТОДЫ
		void addLabelsFrom(const SimplexMatrix& sm);
		SimplexMatrix SimplexInvert() const;
		void SplitChildren(SimplexMatrixNode &node);
		float SimplexSolve(bool &is_failed, bool to_min, bool show_progress = true, bool show_final_tab = true);
	};

	//интерфейс для всех решений
	class SolverBase {
	public:
		virtual void Solve() = 0;
		virtual std::string Output() = 0;
	};

	// SOLVERS FOR SPECIFIC LAB
	class SolverLab1 : SolverBase {
		SimplexMatrix sm;
		bool is_failed;
		bool is_solved;
	public:
		SolverLab1();

		void Input(SimplexMatrix &sm);

		virtual std::string Output();
		virtual void Solve();
	};

	class SolverLab3 : SolverBase {

	};
	
	class SolverLab6 : SolverBase {
		Matrix m;
	public:
		virtual void Bernulli(Matrix &m, int rows, int lines);
		virtual void MaxMin(Matrix &m, int rows, int lines);
		virtual void MaxMax(Matrix &m, int rows, int lines);
		virtual void Gurvic(Matrix &m, int rows, int lines);
		virtual void Risks(Matrix &m, int rows, int lines);
	};

}















