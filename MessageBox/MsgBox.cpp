// Quando o Windows.h foi executar e ver que o win32 está definido então o Windows.h não vai incluir essa parte de 16Bits a gnt nao vai usar isso, isso é coisa antiga
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <sstream>
// Stringstream é como se fosse o cout se eu mando uma coisa para o stringstream ele guarda em uma string
using std::stringstream;

int APIENTRY main(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {


	int resp = MessageBox(NULL, "Vamos calcular o tamanho da tela? ", "Mensagem", MB_YESNO | MB_DEFBUTTON2 | MB_ICONQUESTION);

	if (resp == IDYES)
	{

		int cxScreen = GetSystemMetrics(SM_CXSCREEN);
		int cyScreen = GetSystemMetrics(SM_CYSCREEN);
		
		stringstream text;
		text << "Resolução: " << cxScreen << "x" << cyScreen;
		//str() é para você obter uma string porém o MessageBox nao é compativel com string então utilizamos um outro metodo que é c_str()
		//ele obtem uma string no formato da linguagem c por isso que ela se chama c_str()
		MessageBox(NULL, text.str().c_str(), "Tamanho da tela ", MB_OK | MB_ICONINFORMATION);

	}
	else {

		MessageBox(NULL, "Proximo", "Mensagem", MB_OK | MB_ICONWARNING);
	}
	return 0;
}