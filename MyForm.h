#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include "listaDoble.h"
namespace ProyectoAlgoritmosDeOrden {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using std::ifstream;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		listaDoble^ pokédexNum = gcnew listaDoble;
		listaDoble^ pokédexName = gcnew listaDoble;
	private: System::Windows::Forms::Button^ button_numero;
	public:
	private: System::Windows::Forms::Button^ button_gen;
	private: System::Windows::Forms::Button^ button_nombre;
	private: System::Windows::Forms::ListBox^ listBox2;
		   listaDoble^ pokédexGen = gcnew listaDoble;
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_leer;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button_leer = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button_numero = (gcnew System::Windows::Forms::Button());
			this->button_gen = (gcnew System::Windows::Forms::Button());
			this->button_nombre = (gcnew System::Windows::Forms::Button());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// button_leer
			// 
			this->button_leer->Location = System::Drawing::Point(168, 385);
			this->button_leer->Name = L"button_leer";
			this->button_leer->Size = System::Drawing::Size(75, 23);
			this->button_leer->TabIndex = 0;
			this->button_leer->Text = L"Leer";
			this->button_leer->UseVisualStyleBackColor = true;
			this->button_leer->Click += gcnew System::EventHandler(this, &MyForm::button_leer_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(26, 43);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(217, 95);
			this->listBox1->TabIndex = 1;
			// 
			// button_numero
			// 
			this->button_numero->Location = System::Drawing::Point(26, 356);
			this->button_numero->Name = L"button_numero";
			this->button_numero->Size = System::Drawing::Size(75, 23);
			this->button_numero->TabIndex = 2;
			this->button_numero->Text = L"Numero";
			this->button_numero->UseVisualStyleBackColor = true;
			this->button_numero->Click += gcnew System::EventHandler(this, &MyForm::button_numero_Click);
			// 
			// button_gen
			// 
			this->button_gen->Location = System::Drawing::Point(26, 414);
			this->button_gen->Name = L"button_gen";
			this->button_gen->Size = System::Drawing::Size(75, 23);
			this->button_gen->TabIndex = 3;
			this->button_gen->Text = L"Gen";
			this->button_gen->UseVisualStyleBackColor = true;
			this->button_gen->Click += gcnew System::EventHandler(this, &MyForm::button_gen_Click);
			// 
			// button_nombre
			// 
			this->button_nombre->Location = System::Drawing::Point(26, 385);
			this->button_nombre->Name = L"button_nombre";
			this->button_nombre->Size = System::Drawing::Size(75, 23);
			this->button_nombre->TabIndex = 4;
			this->button_nombre->Text = L"Nombre";
			this->button_nombre->UseVisualStyleBackColor = true;
			this->button_nombre->Click += gcnew System::EventHandler(this, &MyForm::button_nombre_Click);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(26, 180);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(217, 95);
			this->listBox2->TabIndex = 5;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 454);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->button_nombre);
			this->Controls->Add(this->button_gen);
			this->Controls->Add(this->button_numero);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button_leer);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);

		}
#pragma endregion
		void split_str(std::string const& str, const char delim,
			std::vector <std::string>& out)
		{
			// create a stream from the string  
			std::stringstream s(str);

			std::string s2;
			while (std::getline(s, s2, delim))
			{
				out.push_back(s2); // store the string in s2  
			}
		}
		int letraAValor(String^ letra)
		{
			if (letra == "A" || letra == "a")
			{
				return 1;
			}
			if (letra == "B" || letra == "b")
			{
				return 2;
			}
			if (letra == "C" || letra == "c")
			{
				return 3;
			}
			if (letra == "D" || letra == "d")
			{
				return 4;
			}
			if (letra == "E" || letra == "e")
			{
				return 5;
			}
			if (letra == "F" || letra == "f")
			{
				return 6;
			}
			if (letra == "G" || letra == "g")
			{
				return 7;
			}
			if (letra == "H" || letra == "h")
			{
				return 8;
			}
			if (letra == "I" || letra == "i")
			{
				return 9;
			}
			if (letra == "J" || letra == "j")
			{
				return 10;
			}
			if (letra == "K" || letra == "k")
			{
				return 11;
			}
			if (letra == "L" || letra == "l")
			{
				return 12;
			}
			if (letra == "M" || letra == "m")
			{
				return 13;
			}
			if (letra == "N" || letra == "n")
			{
				return 14;
			}
			if (letra == "O" || letra == "o")
			{
				return 15;
			}
			if (letra == "P" || letra == "p")
			{
				return 16;
			}
			if (letra == "Q" || letra == "q")
			{
				return 17;
			}
			if (letra == "R" || letra == "r")
			{
				return 18;
			}
			if (letra == "S" || letra == "s")
			{
				return 19;
			}
			if (letra == "T" || letra == "t")
			{
				return 20;
			}
			if (letra == "U" || letra == "u")
			{
				return 21;
			}
			if (letra == "V" || letra == "v")
			{
				return 22;
			}
			if (letra == "W" || letra == "w")
			{
				return 23;
			}
			if (letra == "X" || letra == "x")
			{
				return 24;
			}
			if (letra == "Y" || letra == "y")
			{
				return 25;
			}
			if (letra == "Z" || letra == "z")
			{
				return 26;
			}
		}
	private: System::Void button_leer_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			button_leer->Enabled = false;
			String^ archivo = openFileDialog1->FileName;
			string datos = "";
			String^ numDex = "";
			String^ nomDex = "";
			String^ genDex = "";
			int numero;
			int conversion = 0;
			ifstream hoja (msclr::interop::marshal_as<std::string >(archivo));
			ofstream resultados("resultados");
			while (getline(hoja, datos))
			{
				std::vector <std::string> out;
				split_str(datos, ',', out);
				for (const auto& s2 : out)
				{
					std::cout << "," << s2;
					datos = s2 +","+datos;
					if (numDex == "")
					{
						numDex = msclr::interop::marshal_as<String^ >(s2);
						//listBox1->Items->Add(msclr::interop::marshal_as<String^ >(s2));
					}
					else if (nomDex == "")
					{
						nomDex = msclr::interop::marshal_as<String^ >(s2);
						//listBox1->Items->Add(msclr::interop::marshal_as<String^ >(s2));
					}
					else if (genDex == "")
					{
						genDex = msclr::interop::marshal_as<String^ >(s2);
						//listBox1->Items->Add(msclr::interop::marshal_as<String^ >(s2));
						listBox1->Items->Add(numDex + "." + nomDex + "." + genDex + "\n");
						pokédexGen->InsertarNuevo(genDex);
						pokédexNum->InsertarNuevo(numDex);
						pokédexName->InsertarNuevo(nomDex);
						numDex = "";
						nomDex = "";
						genDex = "";
					}
				}
			}
		}
	}
	private: System::Void button_numero_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		if (pokédexNum->dimension() != 0)
		{
			listBox2->Items->Clear();
			int size = pokédexNum->dimension();
			for (int z = 0; z < size; z++)
			{
				for (int i = 0; i < size - 1; i++)
				{
					for (int j = 0; j < size - i; j++)
					{
						int a = Convert::ToInt16(pokédexNum->Ver(i));
						int b = Convert::ToInt16(pokédexNum->Ver(i + 1));
						if (a > b)
						{
							String^ temporal = pokédexNum->Ver(i);
							pokédexNum->reemplazar(pokédexNum->Ver(i + 1), i);
							pokédexNum->reemplazar(temporal, i + 1);
							//-------------------------------------------------
							String^ temporal1 = pokédexGen->Ver(i);
							pokédexGen->reemplazar(pokédexGen->Ver(i + 1), i);
							pokédexGen->reemplazar(temporal1, i + 1);
							//------------------------------------------------
							String^ temporal2 = pokédexName->Ver(i);
							pokédexName->reemplazar(pokédexName->Ver(i + 1), i);
							pokédexName->reemplazar(temporal2, i + 1);
						}
					}
				}
			}
			for (int h = 0; h < size; h++)
			{
				listBox2->Items->Add(pokédexNum->Ver(h) + "." + pokédexName->Ver(h) + "." + pokédexGen->Ver(h) + "\n");
			}
		}
	}
private: System::Void button_gen_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//BubbleSort
	if (pokédexGen->dimension() != 0)
	{
		listBox2->Items->Clear();
		int success = 0;
		int size = pokédexGen->dimension();
		for (int z = 0; z < size; z++)
		{
			for (int i = 0; i < size - 1; ++i)
			{
				for (int j = 0; j < size; ++j)
				{
					int a = Convert::ToInt16(pokédexGen->Ver(i));
					int b = Convert::ToInt16(pokédexGen->Ver(i + 1));
					if (a > b)
					{
						String^ temporal = pokédexNum->Ver(i);
						pokédexNum->reemplazar(pokédexNum->Ver(i + 1), i);
						pokédexNum->reemplazar(temporal, i + 1);
						//---------------------------------------
						String^ temporal1 = pokédexGen->Ver(i);
						pokédexGen->reemplazar(pokédexGen->Ver(i + 1), i);
						pokédexGen->reemplazar(temporal1, i + 1);
						//---------------------------------------
						String^ temporal2 = pokédexName->Ver(i);
						pokédexName->reemplazar(pokédexName->Ver(i + 1), i);
						pokédexName->reemplazar(temporal2, i + 1);
					}
				}
			}
		}
		for (int h = 0; h < size; h++)
		{
			listBox2->Items->Add(pokédexNum->Ver(h) + "." + pokédexName->Ver(h) + "." + pokédexGen->Ver(h) + "\n");
		}
	}
}
private: System::Void button_nombre_Click(System::Object^ sender, System::EventArgs^ e) 
{
	if (pokédexGen->dimension() != 0)
	{
		listBox2->Items->Clear();
		int size = pokédexGen->dimension();
		for (int y = 0; y < size; y++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				for (int j = 0; j < size - i; j++)
				{
					String^ abc1 = (pokédexName->Ver(i));
					String^ abc2 = (pokédexName->Ver(i + 1));
					string k = msclr::interop::marshal_as<string >(abc1);
					string l = msclr::interop::marshal_as<string >(abc2);
					String^ a = Convert::ToString(k[1]);
					String^ b = Convert::ToString(l[1]);
					/*int a = letraAValor((x));
					int b = letraAValor(y);*/
					if (Convert::ToInt16(a) > Convert::ToInt16(b))
					{
						String^ temporal = pokédexNum->Ver(i);
						pokédexNum->reemplazar(pokédexNum->Ver(i + 1), i);
						pokédexNum->reemplazar(temporal, i + 1);
						String^ temporal1 = pokédexGen->Ver(i);
						pokédexGen->reemplazar(pokédexGen->Ver(i + 1), i);
						pokédexGen->reemplazar(temporal1, i + 1);
						String^ temporal2 = pokédexName->Ver(i);
						pokédexName->reemplazar(pokédexName->Ver(i + 1), i);
						pokédexName->reemplazar(temporal2, i + 1);
					}
				}
			}
		}
		for (int h = 0; h < size; h++)
		{
			listBox2->Items->Add(pokédexNum->Ver(h) + "." + pokédexName->Ver(h) + "." + pokédexGen->Ver(h) + "\n");
		}
	}
}
};
}
