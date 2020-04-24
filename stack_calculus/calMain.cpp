#include "stdafx.h"
#include "Change_postfixNotation.h"
#include "Stack.h"
#include "PNcalculation.h"

int main()
{
	//string Input = "1+2*3";
	string Input = "((1-2)+3)*(5-2)";
	postfixNotation pfn(Input);
	char* result = pfn.change();
	PNCalculation PNC(result);
	PNC.calculator();
	char result2 = PNC.GetData();

	cout << result << endl;
	cout << result2 << endl;
	return 0;
}