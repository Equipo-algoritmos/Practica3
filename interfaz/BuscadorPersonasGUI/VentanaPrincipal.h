#pragma once
#include "RegistroPersonas.h"
#include <msclr/marshal_cppstd.h>
namespace BuscadorPersonasGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VentanaPrincipal
	/// </summary>
	public ref class VentanaPrincipal : public System::Windows::Forms::Form
	{
	public:
		VentanaPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
	private: RegistroPersonas* registro = nullptr;
		~VentanaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnSeleccionarArchivo;
	private: System::Windows::Forms::Label^ lblArchivo;
	private: System::Windows::Forms::OpenFileDialog^ dialogoArchivo;
	private: System::Windows::Forms::Label^ lblClave;
	private: System::Windows::Forms::MaskedTextBox^ txtClave;

	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::DataGridView^ tablaPersonas;


	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colClave;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colNombre;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEdad;





	protected:


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
			this->btnSeleccionarArchivo = (gcnew System::Windows::Forms::Button());
			this->lblArchivo = (gcnew System::Windows::Forms::Label());
			this->dialogoArchivo = (gcnew System::Windows::Forms::OpenFileDialog());
			this->lblClave = (gcnew System::Windows::Forms::Label());
			this->txtClave = (gcnew System::Windows::Forms::MaskedTextBox());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->tablaPersonas = (gcnew System::Windows::Forms::DataGridView());
			this->colClave = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colNombre = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEdad = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaPersonas))->BeginInit();
			this->SuspendLayout();
			// 
			// btnSeleccionarArchivo
			// 
			this->btnSeleccionarArchivo->Location = System::Drawing::Point(17, 25);
			this->btnSeleccionarArchivo->Name = L"btnSeleccionarArchivo";
			this->btnSeleccionarArchivo->Size = System::Drawing::Size(166, 23);
			this->btnSeleccionarArchivo->TabIndex = 0;
			this->btnSeleccionarArchivo->Text = L"Seleccionar archivo";
			this->btnSeleccionarArchivo->UseVisualStyleBackColor = true;
			this->btnSeleccionarArchivo->Click += gcnew System::EventHandler(this, &VentanaPrincipal::btnSeleccionarArchivo_Click);
			// 
			// lblArchivo
			// 
			this->lblArchivo->AutoSize = true;
			this->lblArchivo->Location = System::Drawing::Point(189, 30);
			this->lblArchivo->Name = L"lblArchivo";
			this->lblArchivo->Size = System::Drawing::Size(145, 13);
			this->lblArchivo->TabIndex = 1;
			this->lblArchivo->Text = L"Ningun archivo seleccionado";
			// 
			// dialogoArchivo
			// 
			this->dialogoArchivo->FileName = L"openFileDialog1";
			this->dialogoArchivo->Filter = L"Archivos de texto (*.txt)|*.txt";
			this->dialogoArchivo->Title = L"Seleccionar archivo";
			// 
			// lblClave
			// 
			this->lblClave->AutoSize = true;
			this->lblClave->Location = System::Drawing::Point(54, 90);
			this->lblClave->Name = L"lblClave";
			this->lblClave->Size = System::Drawing::Size(152, 13);
			this->lblClave->TabIndex = 2;
			this->lblClave->Text = L"Ingrese la clave del trabajador:";
			// 
			// txtClave
			// 
			this->txtClave->Location = System::Drawing::Point(225, 87);
			this->txtClave->Mask = L"L00000";
			this->txtClave->Name = L"txtClave";
			this->txtClave->Size = System::Drawing::Size(44, 20);
			this->txtClave->TabIndex = 4;
			this->txtClave->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &VentanaPrincipal::txtClave_KeyDown);
			// 
			// btnBuscar
			// 
			this->btnBuscar->Location = System::Drawing::Point(284, 87);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(75, 23);
			this->btnBuscar->TabIndex = 5;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = true;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &VentanaPrincipal::btnBuscar_Click);
			// 
			// tablaPersonas
			// 
			this->tablaPersonas->AllowUserToOrderColumns = true;
			this->tablaPersonas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->tablaPersonas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->colClave,
					this->colNombre, this->colEdad
			});
			this->tablaPersonas->Location = System::Drawing::Point(27, 126);
			this->tablaPersonas->Name = L"tablaPersonas";
			this->tablaPersonas->Size = System::Drawing::Size(444, 150);
			this->tablaPersonas->TabIndex = 6;
			// 
			// colClave
			// 
			this->colClave->HeaderText = L"Clave";
			this->colClave->Name = L"colClave";
			this->colClave->ReadOnly = true;
			// 
			// colNombre
			// 
			this->colNombre->HeaderText = L"Nombre";
			this->colNombre->Name = L"colNombre";
			this->colNombre->ReadOnly = true;
			this->colNombre->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->colNombre->Width = 200;
			// 
			// colEdad
			// 
			this->colEdad->HeaderText = L"Edad";
			this->colEdad->Name = L"colEdad";
			this->colEdad->ReadOnly = true;
			// 
			// VentanaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(677, 372);
			this->Controls->Add(this->tablaPersonas);
			this->Controls->Add(this->btnBuscar);
			this->Controls->Add(this->txtClave);
			this->Controls->Add(this->lblClave);
			this->Controls->Add(this->lblArchivo);
			this->Controls->Add(this->btnSeleccionarArchivo);
			this->Name = L"VentanaPrincipal";
			this->Text = L"Buscar persona";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->tablaPersonas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void btnSeleccionarArchivo_Click(System::Object^ sender, System::EventArgs^ e) {
		if (dialogoArchivo->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//lblArchivo->Text = dialogoArchivo->FileName;
			System::String^ ruta = dialogoArchivo->FileName;

			lblArchivo->Text = System::IO::Path::GetFileName(ruta);

			std::string rutaCpp = msclr::interop::marshal_as<std::string>(ruta);

			if (registro != nullptr)
			{
				tablaPersonas->Rows->Clear();
				delete registro;
			}

			registro = new RegistroPersonas(rutaCpp);
		}
		txtClave->Focus();
	}

	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		if (registro == nullptr)
		{
			MessageBox::Show(
				"Primero seleccione un archivo.",
				"Aviso",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);

			return;
		}

		std::string clave =
			msclr::interop::marshal_as<std::string>(
				txtClave->Text
			);

		int posicion = registro->buscar(clave);

		if (posicion == -1)
		{
			MessageBox::Show(
				"Persona no encontrada.",
				"Resultado",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			return;
		}

		Persona persona =
			registro->getPersona(posicion);

		//tablaPersonas->Rows->Clear();

		tablaPersonas->Rows->Add(
			gcnew System::String(
				persona.getClave().c_str()
			),
			gcnew System::String(
				persona.getNombre().c_str()
			),
			persona.getEdad()
		);
		txtClave->Text = "";
	}
private: System::Void txtClave_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter)
	{
		btnBuscar->PerformClick();
	}
}
};
}


