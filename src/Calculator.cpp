#include "stdafx.h"
#include "Calculator.h"

void Calculator::GetOperands(int n, std::string& formula)
{
	bool check = false;
	--n;
	RetrieveNum(n, formula);
	n += 2;
	if (n < formula.size() && formula[n] == '-')
		++n;
	while (n < formula.size() && (IsDigit(formula[n]) || formula[n] == '.')) // determine If there is a second number
	{
		check = true;
		++n;
	}
	--n;
	if (check) // If there is a seconds number
		RetrieveNum(n, formula);
	if (n < 0) // If we went out of string
		formula.erase(0, 1);
	else
		formula.erase(n, 1);
}

void Calculator::GetOperator(int n, std::string& formula)
{
	if (formula[n] == '*')
	{
		if (n - 1 >= 0 && IsDigit(formula[n - 1])) // 1 num exists
		{
			if (n + 1 < formula.size() && (IsDigit(formula[n + 1]) || formula[n + 1] == '-')) // 1 and 2 nums exist
				operators.Push("* ");
			else
				operators.Push("$*"); // only 1 num exist
		}
		else
		{
			if (n + 1 < formula.size() && (IsDigit(formula[n + 1]) || formula[n + 1] == '-')) // only 2 num exists
				operators.Push("$*");
			else // none of nums exists
				operators.Push("@*");
		}
	}
	else if (formula[n] == '/')
	{
		if (n - 1 >= 0 && IsDigit(formula[n - 1])) // 1 num exists
		{
			if (n + 1 < formula.size() && (IsDigit(formula[n + 1]) || formula[n + 1] == '-')) // 1 and 2 nums exist
				operators.Push("/ ");
			else
				operators.Push("/$"); // only 1 num exist
		}
		else
		{
			if (n + 1 < formula.size() && (IsDigit(formula[n + 1]) || formula[n + 1] == '-')) // only 2 num exists
				operators.Push("$/");
			else // none of nums exists
				operators.Push("@/");
		}
	}
	else if (formula[n] == '+')
	{
		if (n - 1 >= 0 && IsDigit(formula[n - 1])) // 1 num exists
		{
			if (n + 1 < formula.size() && (IsDigit(formula[n + 1]) || formula[n + 1] == '-')) // 1 and 2 nums exist
				operators.Push("+ ");
			else
				operators.Push("$+"); // only 1 num exist
		}
		else
		{
			if (n + 1 < formula.size() && (IsDigit(formula[n + 1]) || formula[n + 1] == '-')) // only 2 num exists
				operators.Push("$+");
			else // none of nums exists
				operators.Push("@+");
		}
	}
	else if (formula[n] == '-')
	{
		if (n - 1 >= 0 && IsDigit(formula[n - 1])) // 1 num exists
		{
			if (n + 1 < formula.size() && (IsDigit(formula[n + 1]) || formula[n + 1] == '-')) // 1 and 2 nums exist
				operators.Push("- ");
			else
				operators.Push("-$"); // only 1 num exist
		}
		else
		{
			if (n + 1 < formula.size() && (IsDigit(formula[n + 1]) || formula[n + 1] == '-')) // only 2 num exists
				operators.Push("$-");
			else // none of nums exists
				operators.Push("@-");
		}
	}
}

void Calculator::RetrieveNum(int& n, std::string& formula)
{
	double res = 0.0;
	int power = 0, counter = 0;
	while (n >= 0 && (IsDigit(formula[n]) || formula[n] =='.' || (formula[n] == '-' && n - 1 >= 0 &&
		(formula[n - 1] == '*' || formula[n - 1] == '/' || formula[n - 1] == '+'|| formula[n - 1] == '-')))) // Getting a number
	{
		if (formula[n] == '.')
		{
			res /= pow(10, power);
			power = 0;
		}
		else if (formula[n] == '-')
			res *= -1.0;
		else
		{
			res += (formula[n] - '0') * pow(10, power);
			++power;
		}
		--n;
		++counter;
	}
	if (power)
	{
		operands.Push(res);
		if (n < 0) // If we went out of string
			formula.erase(0, counter);
		else
			formula.erase(n + 1, counter);
	}
}

double Calculator::CalculateFormula()
{
	ReverseStacks();
	std::vector<double> result;
	// Commit operations 
	// +- -- ќпераци€ производитс€ между двум€ операндами
	// */ -- ќпераци€ производитс€ между двум€ значени€м result, если операндов больше нет, или между двум€ операндами
	// $+-*/ -- ќпераци€ производитс€ между последним значением result и последним операндом в соотвествующем пор€дке
	// -/$ -- ќпераци€ производитс€ между последним значением result и последним операндом в обратном пор€дке
	// @+- -- ќпераци€ производитс€ между двум€ последними значени€ми result
	std::string tmp;
	while (operators.GetLen())
	{
		tmp = operators.Pop();
		if (tmp == "* ")
		{
			if (!operands.GetLen())
			{
				result[0] *= result[1];
				result.erase(result.begin() + 1);
			}
			else
				result.push_back(operands.Pop() * operands.Pop());
		}
		else if (tmp == "$*")
			result[result.size() - 1] *= operands.Pop();
		else if (tmp == "/ ")
		{
			if (!operands.GetLen())
			{
				result[0] /= result[1];
				result.erase(result.begin() + 1);
			}
			else
				result.push_back(operands.Pop() / operands.Pop());
		}
		else if (tmp == "$/")
			result[result.size() - 1] /= operands.Pop();
		else if (tmp == "/$")
			result[result.size() - 1] = operands.Pop() / result[result.size() - 1];
		else if (tmp == "+ ")
			result.push_back(operands.Pop() + operands.Pop());
		else if (tmp == "$+")
			result[result.size() - 1] += operands.Pop();
		else if (tmp == "@+")
		{
			result[0] += result[1];
			result.erase(result.begin() + 1);
		}
		else if (tmp == "- ")
			result.push_back(operands.Pop() - operands.Pop());
		else if (tmp == "$-")
			result[result.size() - 1] -= operands.Pop();
		else if (tmp == "-$")
			result[result.size() - 1] = operands.Pop() - result[result.size() - 1];
		else if (tmp == "@-")
		{
			result[0] -= result[1];
			result.erase(result.begin() + 1);
		}
	}
	return result[0];
}

bool Calculator::CheckPriority(int n, std::string& formula)
{
	for (int i = n; i < formula.size(); ++i)
		if (formula[i] == '*' || formula[i] == '/')
			return true;
	return false;
}

bool Calculator::IsDigit(char& ch)
{
	if (ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' || ch == '9' ||
		ch == '0') return true;

	return false;
}

void Calculator::ReverseStacks()
{
	Stack<double> num_tmp;
	Stack<std::string> signs_tmp;
	while (operands.GetLen())
		num_tmp.Push(operands.Pop());
	while (operators.GetLen())
		signs_tmp.Push(operators.Pop());
	operators = signs_tmp;
	operands = num_tmp;
}

double Calculator::SinOf(std::string& ss)
{
	return sin(Calculate(ss));
}

double Calculator::CosOf(std::string& ss)
{
	return cos(Calculate(ss));
}

double Calculator::TanOf(std::string& ss)
{
	return tan(Calculate(ss));
}

double Calculator::LogOf(std::string& ss)
{
	return log10(Calculate(ss));
}

double Calculator::LnOf(std::string& ss)
{
	return log(Calculate(ss));
}

Calculator::Calculator() : operands(Stack<double>()), operators(Stack<std::string>()), morePrioritOp(false)
{
}

Calculator::Calculator(const Calculator& G) : operators(G.operators), operands(G.operands), morePrioritOp(G.morePrioritOp)
{
}

Calculator& Calculator::operator=(const Calculator& G)
{
	if (this == &G)
		return *this;
	operators = G.operators;
	operands = G.operands;
	morePrioritOp = G.morePrioritOp;
	return *this;
}


Calculator::~Calculator()
{
}

double Calculator::Calculate(std::string& formula)
{
	int i = 0, j = 0;
	if (formula[0] == '-')
		formula.insert(formula.begin(), '0');
	for (i = 1; i < formula.size(); ++i) // Change minus on +-
		if (formula[i] == '-' && (formula[i - 1] != '+' && formula[i - 1] != '*' && formula[i - 1] != '/' && formula[i - 1] != '('))
		{
			formula.insert(i, 1, '+');
			++i;
		}
	for (i = formula.size() - 1; i >= 0; --i)
		if (formula[i] == '(')
		{
			j = i + 1;
			while (formula[j] != ')' && j < formula.size()) //»щем закрывающую скобку, а если ее нет, то выражение до конца беретс€ в скобки
				++j;
			std::string s = formula.substr(i + 1, j - i - 1); // ѕолучаем подстроку в скобках
			if (j < formula.size()) // ”дал€ем ее из основной строки
				formula.erase(i, j - i + 1);
			else
				formula.erase(i, j - i);

			if (!formula.size()) // ≈сли в строке больше ничего нет, то возвращаем результат подстроки, иначе вставл€ем результат подстроку на ее место
				return Calculate(s);
			else if (i > 1 && formula[i - 2] == 'i') // Sin of 
			{
				formula.insert(i, std::to_string(SinOf(s)));
				formula.erase(i - 3, 3);
			}
			else if (i > 1 && formula[i - 1] == 'g') // log10 of
			{
				formula.insert(i, std::to_string(LogOf(s)));
				formula.erase(i - 3, 3);
			}
			else if (i > 1 && formula[i - 2] == 'a') // Tan of
			{
				formula.insert(i, std::to_string(TanOf(s)));
				formula.erase(i - 3, 3);
			}
			else if (i > 1 && formula[i - 2] == 'o') // Cos of
			{
				formula.insert(i, std::to_string(CosOf(s)));
				formula.erase(i - 3, 3);
			}
			else if (i > 1 && formula[i - 1] == 'n') // Ln of
			{
				formula.insert(i, std::to_string(LnOf(s)));
				formula.erase(i - 2, 2);
			}
			else
				formula.insert(i, std::to_string(Calculate(s)));
			if (formula[0] == '-')
				formula.insert(formula.begin(), '0');
		}
	i = 0;
	while (i < formula.size())
	{
		if (formula[i] == '*' || (formula[i] == '/' || (formula[i] == '+' && !CheckPriority(i + 1, formula))
			|| (formula[i] == '-' && !CheckPriority(i + 1, formula))))
		{
			GetOperator(i, formula);
				GetOperands(i, formula);
				i = 0;
		}
		else
			++i;
	}
	if (!operators.GetLen())
		return std::stod(formula);
	return CalculateFormula();
}
