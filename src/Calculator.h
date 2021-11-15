#pragma once
class Calculator
{
protected:
	Stack<double> operands;
	Stack<std::string> operators;
	bool morePrioritOp;
	//
	void GetOperands(int, std::string&);
	void GetOperator(int, std::string&);
	void RetrieveNum(int&, std::string&);
	double CalculateFormula();
	//
	bool CheckPriority(int, std::string&);
	bool IsDigit(char&);
	void ReverseStacks();
	//
	double SinOf(std::string&); // sin(string)
	double CosOf(std::string&); // cos(string)
	double TanOf(std::string&); // tan(string)
	double LogOf(std::string&); // log10(string)
	double LnOf(std::string&); // ln(string)
public:
	Calculator();
	Calculator  (const Calculator&);
	Calculator& operator = (const Calculator&);
	virtual ~Calculator();
	//
	double Calculate(std::string&);
};

