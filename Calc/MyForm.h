#pragma once
#include <msclr/marshal_cppstd.h>
#include <stdlib.h>
#include <string.h>
#include <iostream> 
#include <string>  
#include <math.h>

std::string exp(std::string expression) {
	int k = 0;
	int point_amount = 0;
	std::string *expression_list = new std::string[expression.length()];
	std::string сurrent_number = "";
	for (int i = 0; i < expression.length(); i++) {
		if (expression[i] == '^' && i != 0) {
			expression_list[k] = сurrent_number;
			expression_list[k + 1] = expression[i];
			сurrent_number.clear();
			k = k + 2;
		}
		else {
			сurrent_number = сurrent_number + expression[i];
		}
	}

	if (сurrent_number != "") {
			expression_list[k] = сurrent_number;
		}
	else { throw "Input incorrect!"; }



	for (int i = 0; i <= k; i = i + 2) {
		for (int j = 0; j <= expression_list[i].length(); j++) {
				if ((j == 0) && (expression_list[i][j] == '+' || expression_list[i][j] == '*' || expression_list[i][j] == '^' || expression_list[i][j] == '.' || expression_list[i][j] == '/')) {
					throw "Input incorrect!";
				}
				else if ((j > 0) && (expression_list[i][j] == '+' || expression_list[i][j] == '*' || expression_list[i][j] == '^' || expression_list[i][j] == '/')) {
					throw "Input incorrect!";
				}
		}
	}


	for (int i = 0; i <= k; i = i + 2) {
		point_amount = 0;
		for (int j = expression_list[i].find(".", 0); j != std::string::npos; j = expression_list[i].find(".", j)) {
			point_amount++;
			j++;
		}
			if (point_amount > 1) {
				throw "Input incorrect!";
			}
	}

	for (int i = k; i >= 0; i = i - 1) {
		if (expression_list[i] == "^") {
				if (std::stof(expression_list[i - 1].c_str(), 0) <= 0) {
					throw "Base of the exponential function can only be positive!";
				}
				else {
					expression_list[i - 1] = std::to_string(pow(std::stof(expression_list[i - 1].c_str(), 0), std::stof(expression_list[i + 1].c_str(), 0)));
				}
		}
	}

	return expression_list[0];
}


std::string multiplication(std::string expression) {
	int k = 0;
	int point_amount = 0;
	std::string *expression_list = new std::string[expression.length()];
	std::string сurrent_number = "";
	for (int i = 0; i < expression.length(); i++) {
		if ((expression[i] == '*' || expression[i] == '/') && (i != 0)) {
			expression_list[k] = сurrent_number;
			expression_list[k + 1] = expression[i];
			сurrent_number.clear();
			k = k + 2;
		}
		else {
			сurrent_number = сurrent_number + expression[i];
		}
	}
		if (сurrent_number != "") {
			expression_list[k] = сurrent_number;
		}
		else { throw "Input incorrect!"; }

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < expression_list[i].length(); j++) {
			if (expression_list[i][j] == '^') {
				try {
					expression_list[i] = exp(expression_list[i]);
					break;
				}
				catch (const char* msg) {
					throw msg;
				}
			}
		}
	}

	for (int i = 0; i <= k; i = i + 2) {
		for (int j = 0; j <= expression_list[i].length(); j++) {
				if ((j == 0) && (expression_list[i][j] == '+' || expression_list[i][j] == '*' || expression_list[i][j] == '^' || expression_list[i][j] == '.' || expression_list[i][j] == '/')) {
					throw "Input incorrect!";
				}
				else if ((j > 0) && (expression_list[i][j] == '+' || expression_list[i][j] == '*' || expression_list[i][j] == '^' || expression_list[i][j] == '/')) {
					throw "Input incorrect!";
				}
		}
	}


	for (int i = 0; i <= k; i = i + 2) {
		point_amount = 0;
		for (int j = expression_list[i].find(".", 0); j != std::string::npos; j = expression_list[i].find(".", j)) {
			point_amount++;
			j++;
		}
			if (point_amount > 1) {
				throw "Input incorrect!";
			}
	}

	for (int i = 0; i <= k; i++) {
		if (expression_list[i] == "*") {
			expression_list[i + 1] = std::to_string(std::stof(expression_list[i - 1].c_str(), 0)*std::stof(expression_list[i + 1].c_str(), 0));
		}
		else if (expression_list[i] == "/") {
				if (std::stof(expression_list[i + 1].c_str(), 0) == 0) {
					throw "Division by zero!";
				}
				else {
					expression_list[i + 1] = std::to_string(std::stof(expression_list[i - 1].c_str(), 0) / std::stof(expression_list[i + 1].c_str(), 0));
				}
		}

	}
	return expression_list[k];
}

std::string addition(std::string expression) {
	int k = 0;
	int point_amount = 0;
	std::string *expression_list = new std::string[expression.length()];
	std::string сurrent_number = "";
	for (int i = 0; i < expression.length(); i++) {
		if ((expression[i] == '+') || ((expression[i] == '-') && (i != 0) && (expression[i - 1] != '-' && expression[i - 1] != '+' && expression[i - 1] != '*' && expression[i - 1] != '/' && expression[i - 1] != '^'))) {
			expression_list[k] = сurrent_number;
			expression_list[k + 1] = expression[i];
			сurrent_number.clear();
			k = k + 2;
		}
		else {
			сurrent_number = сurrent_number + expression[i];
		}
	}

		if (сurrent_number != "") {
			expression_list[k] = сurrent_number;
		}
		else { throw "Input incorrect!"; }

	for (int i = 0; i <= k; i++) {
		for (int j = 0; j < expression_list[i].length(); j++) {
			if (expression_list[i][j] == '*' || expression_list[i][j] == '/' || expression_list[i][j] == '^') {
				try {
					expression_list[i] = multiplication(expression_list[i]);
					break;
				}
				catch (const char* msg) {
					throw msg;
				}
			}
		}
	}


	for (int i = 0; i <= k; i = i + 2) {
		for (int j = 0; j <= expression_list[i].length(); j++) {
				if ((j == 0) && (expression_list[i][j] == '+' || expression_list[i][j] == '*' || expression_list[i][j] == '^' || expression_list[i][j] == '.' || expression_list[i][j] == '/')) {
					throw "Input incorrect!";
				}
				else if ((j > 0) && (expression_list[i][j] == '+' || expression_list[i][j] == '*' || expression_list[i][j] == '^' || expression_list[i][j] == '/')) {
					throw "Input incorrect!";
				}
		}
	}


	for (int i = 0; i <= k; i = i + 2) {
		point_amount = 0;
		for (int j = expression_list[i].find(".", 0); j != std::string::npos; j = expression_list[i].find(".", j)) {
			point_amount++;
			j++;
		}
			if (point_amount > 1) {
				throw "Input incorrect!";
			}
	}

	for (int i = 0; i <= k; i++) {
		if (expression_list[i] == "+") {
			expression_list[i + 1] = std::to_string(std::stof(expression_list[i - 1].c_str(), 0) + std::stof(expression_list[i + 1].c_str(), 0));
		}
		else if (expression_list[i] == "-") {
			expression_list[i + 1] = std::to_string(std::stof(expression_list[i - 1].c_str(), 0) - std::stof(expression_list[i + 1].c_str(), 0));
		}

	}
	return expression_list[k];
}


std::string purger(std::string expression) {
	int i = expression.find(" ");
	while (i != -1) {
		expression.erase(i, 1);
		i = expression.find(" ");
	}
	return expression;
}

std::string calculate(std::string user_input) {
	std::string current_expression;
	int current_opening_bracket = 0, current_closing_bracket = 0;
	int any_brackets = 1;
	int closing_bracket_number = 0, opening_bracket_number = 0;
	int last_opening_bracket = 0, last_closing_bracket;
	int i = 0;


	user_input = purger(user_input);
	for (i = 0; i < user_input.length(); i++) {
		switch (user_input[i]) {
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':
		case'+':
		case'-':
		case'*':
		case'/':
		case'^':
		case'.':
		case')':
		case'(':
			break;
		case',':
			user_input[i] = '.';
			break;
		default:
			return"Incorrect input! Please, enter only arithmetical expressions.";
		}
	}

	for (i = user_input.find("(", 0); i != std::string::npos; i = user_input.find("(", i)) {
		opening_bracket_number++;
		i++;
	}
	for (i = user_input.find(")", 0); i != std::string::npos; i = user_input.find(")", i)) {
		closing_bracket_number++;
		i++;
	}
	try {
		if (closing_bracket_number > opening_bracket_number) {
			throw(closing_bracket_number - opening_bracket_number);
		}
	}
	catch (int e) {
		return "Number of closing brackets is greater than number of opening brackets by " + std::to_string(e);
	}

	try {
		if (closing_bracket_number < opening_bracket_number) {
			throw(opening_bracket_number - closing_bracket_number);
		}
	}
	catch (int e) {
		return "Number of opening brackets is greater than number of closing brackets by " + std::to_string(e);

	}



	while (any_brackets == 1) {
		current_closing_bracket = user_input.find(")");
		current_opening_bracket = user_input.substr(0, current_closing_bracket).rfind("(");
		if (current_opening_bracket == current_closing_bracket) {
			any_brackets = 0;
			current_expression = user_input;
			try {
				user_input = addition(current_expression);
			}
			catch (const char* msg) {
				return msg;
			}
			break;
		}
		try {
			last_opening_bracket = user_input.rfind("(");
			last_closing_bracket = user_input.rfind(")");
			if (last_closing_bracket < last_opening_bracket) {
				throw "Bracket error!";
			}

		}
		catch (const char* msg) {
			return msg;
		}
		current_expression = user_input.substr(current_opening_bracket + 1, current_closing_bracket - current_opening_bracket - 1);
		user_input.erase(current_opening_bracket, current_closing_bracket - current_opening_bracket + 1);
		try {
			user_input.insert(current_opening_bracket, addition(current_expression));
		}
		catch (const char* msg) {
			return msg;
		}

	}
	
	return user_input;
}


namespace Calc {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBoxmain;
	protected:

	private: System::Windows::Forms::Button^  buttonobracket;

	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	protected:



	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  buttoncbracket;







	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;


	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  buttonplus;


	private: System::Windows::Forms::Button^  buttonmin;

	private: System::Windows::Forms::Button^  buttonmult;

	private: System::Windows::Forms::Button^  buttonpoint;
	private: System::Windows::Forms::Button^  buttondiv;
	private: System::Windows::Forms::Button^  buttoneq;



	private: System::Windows::Forms::Button^  buttonexp;
	private: System::Windows::Forms::Button^  button0;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  buttonclear;
	private: System::Windows::Forms::Button^  Cr;




	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBoxmain = (gcnew System::Windows::Forms::TextBox());
			this->buttonobracket = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->buttoncbracket = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->buttonplus = (gcnew System::Windows::Forms::Button());
			this->buttonmin = (gcnew System::Windows::Forms::Button());
			this->buttonmult = (gcnew System::Windows::Forms::Button());
			this->buttonpoint = (gcnew System::Windows::Forms::Button());
			this->buttondiv = (gcnew System::Windows::Forms::Button());
			this->buttoneq = (gcnew System::Windows::Forms::Button());
			this->buttonexp = (gcnew System::Windows::Forms::Button());
			this->button0 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->buttonclear = (gcnew System::Windows::Forms::Button());
			this->Cr = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBoxmain
			// 
			this->textBoxmain->Location = System::Drawing::Point(24, 12);
			this->textBoxmain->Name = L"textBoxmain";
			this->textBoxmain->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->textBoxmain->Size = System::Drawing::Size(384, 20);
			this->textBoxmain->TabIndex = 0;
			this->textBoxmain->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// buttonobracket
			// 
			this->buttonobracket->Location = System::Drawing::Point(234, 165);
			this->buttonobracket->Name = L"buttonobracket";
			this->buttonobracket->Size = System::Drawing::Size(34, 34);
			this->buttonobracket->TabIndex = 1;
			this->buttonobracket->Text = L"(";
			this->buttonobracket->UseVisualStyleBackColor = true;
			this->buttonobracket->Click += gcnew System::EventHandler(this, &MyForm::buttonobracket_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(234, 45);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(34, 34);
			this->button7->TabIndex = 2;
			this->button7->Text = L"7";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(274, 45);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(34, 34);
			this->button8->TabIndex = 3;
			this->button8->Text = L"8";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(314, 45);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(34, 34);
			this->button9->TabIndex = 4;
			this->button9->Text = L"9";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(234, 85);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(34, 34);
			this->button4->TabIndex = 5;
			this->button4->Text = L"4";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(274, 85);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(34, 34);
			this->button5->TabIndex = 6;
			this->button5->Text = L"5";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(314, 85);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(34, 34);
			this->button6->TabIndex = 7;
			this->button6->Text = L"6";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// buttoncbracket
			// 
			this->buttoncbracket->Location = System::Drawing::Point(314, 165);
			this->buttoncbracket->Name = L"buttoncbracket";
			this->buttoncbracket->Size = System::Drawing::Size(34, 34);
			this->buttoncbracket->TabIndex = 8;
			this->buttoncbracket->Text = L")";
			this->buttoncbracket->UseVisualStyleBackColor = true;
			this->buttoncbracket->Click += gcnew System::EventHandler(this, &MyForm::buttoncbracket_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(314, 125);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(34, 34);
			this->button3->TabIndex = 9;
			this->button3->Text = L"3";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(274, 125);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(34, 34);
			this->button2->TabIndex = 10;
			this->button2->Text = L"2";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(234, 125);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(34, 34);
			this->button1->TabIndex = 11;
			this->button1->Text = L"1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// buttonplus
			// 
			this->buttonplus->Location = System::Drawing::Point(374, 45);
			this->buttonplus->Name = L"buttonplus";
			this->buttonplus->Size = System::Drawing::Size(34, 34);
			this->buttonplus->TabIndex = 12;
			this->buttonplus->Text = L"+";
			this->buttonplus->UseVisualStyleBackColor = true;
			this->buttonplus->Click += gcnew System::EventHandler(this, &MyForm::buttonplus_Click);
			// 
			// buttonmin
			// 
			this->buttonmin->Location = System::Drawing::Point(374, 85);
			this->buttonmin->Name = L"buttonmin";
			this->buttonmin->Size = System::Drawing::Size(34, 34);
			this->buttonmin->TabIndex = 13;
			this->buttonmin->Text = L"-";
			this->buttonmin->UseVisualStyleBackColor = true;
			this->buttonmin->Click += gcnew System::EventHandler(this, &MyForm::buttonmin_Click);
			// 
			// buttonmult
			// 
			this->buttonmult->Location = System::Drawing::Point(374, 125);
			this->buttonmult->Name = L"buttonmult";
			this->buttonmult->Size = System::Drawing::Size(34, 34);
			this->buttonmult->TabIndex = 14;
			this->buttonmult->Text = L"*";
			this->buttonmult->UseVisualStyleBackColor = true;
			this->buttonmult->Click += gcnew System::EventHandler(this, &MyForm::buttonmult_Click);
			// 
			// buttonpoint
			// 
			this->buttonpoint->Location = System::Drawing::Point(234, 205);
			this->buttonpoint->Name = L"buttonpoint";
			this->buttonpoint->Size = System::Drawing::Size(34, 34);
			this->buttonpoint->TabIndex = 15;
			this->buttonpoint->Text = L".";
			this->buttonpoint->UseVisualStyleBackColor = true;
			this->buttonpoint->Click += gcnew System::EventHandler(this, &MyForm::buttonpoint_Click);
			// 
			// buttondiv
			// 
			this->buttondiv->Location = System::Drawing::Point(374, 165);
			this->buttondiv->Name = L"buttondiv";
			this->buttondiv->Size = System::Drawing::Size(34, 34);
			this->buttondiv->TabIndex = 16;
			this->buttondiv->Text = L"/";
			this->buttondiv->UseVisualStyleBackColor = true;
			this->buttondiv->Click += gcnew System::EventHandler(this, &MyForm::buttondiv_Click);
			// 
			// buttoneq
			// 
			this->buttoneq->Location = System::Drawing::Point(274, 205);
			this->buttoneq->Name = L"buttoneq";
			this->buttoneq->Size = System::Drawing::Size(74, 34);
			this->buttoneq->TabIndex = 17;
			this->buttoneq->Text = L"=";
			this->buttoneq->UseVisualStyleBackColor = true;
			this->buttoneq->Click += gcnew System::EventHandler(this, &MyForm::buttoneq_Click);
			// 
			// buttonexp
			// 
			this->buttonexp->Location = System::Drawing::Point(374, 205);
			this->buttonexp->Name = L"buttonexp";
			this->buttonexp->Size = System::Drawing::Size(34, 34);
			this->buttonexp->TabIndex = 18;
			this->buttonexp->Text = L"^";
			this->buttonexp->UseVisualStyleBackColor = true;
			this->buttonexp->Click += gcnew System::EventHandler(this, &MyForm::buttonexp_Click);
			// 
			// button0
			// 
			this->button0->Location = System::Drawing::Point(274, 165);
			this->button0->Name = L"button0";
			this->button0->Size = System::Drawing::Size(34, 34);
			this->button0->TabIndex = 19;
			this->button0->Text = L"0";
			this->button0->UseVisualStyleBackColor = true;
			this->button0->Click += gcnew System::EventHandler(this, &MyForm::button0_Click);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(21, 45);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(190, 72);
			this->label1->TabIndex = 20;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// buttonclear
			// 
			this->buttonclear->Location = System::Drawing::Point(194, 205);
			this->buttonclear->Name = L"buttonclear";
			this->buttonclear->Size = System::Drawing::Size(34, 34);
			this->buttonclear->TabIndex = 21;
			this->buttonclear->Text = L"CL";
			this->buttonclear->UseVisualStyleBackColor = true;
			this->buttonclear->Click += gcnew System::EventHandler(this, &MyForm::button10_Click_1);
			// 
			// Cr
			// 
			this->Cr->Location = System::Drawing::Point(194, 165);
			this->Cr->Name = L"Cr";
			this->Cr->Size = System::Drawing::Size(34, 34);
			this->Cr->TabIndex = 22;
			this->Cr->Text = L"C";
			this->Cr->UseVisualStyleBackColor = true;
			this->Cr->Click += gcnew System::EventHandler(this, &MyForm::Cr_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(430, 262);
			this->Controls->Add(this->Cr);
			this->Controls->Add(this->buttonclear);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button0);
			this->Controls->Add(this->buttonexp);
			this->Controls->Add(this->buttoneq);
			this->Controls->Add(this->buttondiv);
			this->Controls->Add(this->buttonpoint);
			this->Controls->Add(this->buttonmult);
			this->Controls->Add(this->buttonmin);
			this->Controls->Add(this->buttonplus);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->buttoncbracket);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->buttonobracket);
			this->Controls->Add(this->textBoxmain);
			this->Name = L"MyForm";
			this->Text = L"Calculator";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "8";
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "1";
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "2";
}
private: System::Void button3_Click_1(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "3";
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "4";
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "5";
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "6";
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "7";
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "9";
}
private: System::Void button0_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "0";
}
private: System::Void buttonpoint_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + ".";
}
private: System::Void buttoncbracket_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + ")";
}
private: System::Void buttonobracket_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "(";
}
private: System::Void buttonplus_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "+";
}
private: System::Void buttonmin_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "-";
}
private: System::Void buttonmult_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "*";
}
private: System::Void buttondiv_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "/";
}
private: System::Void buttonexp_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = textBoxmain->Text + "^";
}
private: System::Void buttoneq_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string basic_input = msclr::interop::marshal_as< std::string >(textBoxmain->Text);
	std::string answer = calculate(msclr::interop::marshal_as< std::string >(textBoxmain->Text));
	int last_zero = answer.rfind("0");
	if (last_zero > 0) {
		while (answer[last_zero] == '0') {
			answer.erase(last_zero);
			last_zero = last_zero - 1;
		}
	}
	if (answer[answer.length() - 1] == '.') {
		answer.erase(answer.length() - 1);
	}
	textBoxmain->Text = msclr::interop::marshal_as<System::String^>(answer);
	for (int p = 0; p < answer.length(); p++) {
		switch (answer[p]) {
		case'i':
		case'r':
			label1->Text = msclr::interop::marshal_as<System::String^>(answer);
			textBoxmain->Text = msclr::interop::marshal_as<System::String^>(basic_input);
			break;
		default:
			break;
		}
	}
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void button10_Click_1(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = "";
	label1->Text = "";
}
private: System::Void Cr_Click(System::Object^  sender, System::EventArgs^  e) {
	textBoxmain->Text = msclr::interop::marshal_as<System::String^>(msclr::interop::marshal_as< std::string >(textBoxmain->Text).erase(msclr::interop::marshal_as< std::string >(textBoxmain->Text).length()-1));
	label1->Text = "";
}
};
}
