#include "DM_Application.h"

#include "DM_Window.h"
#include "DM_UI_Manager.h"
#include "DM_Input.h"

#include "DM_GameObject.h"
#include "DM_SpriteRenderer.h"
#include "DM_ResourceManager.h"


namespace DM
{
	Window* Application::mainWindow			= nullptr;

	HDC Application::device_context			= nullptr;
	HDC Application::device_context_back	= nullptr;
	HBITMAP Application::buffer_back		= nullptr;

	GameObject* Application::testObject = nullptr;
}





void DM::Application::Initialize(Window* mainWindow)
{

	Application::mainWindow = mainWindow;

	Application::initializeWindow();
	Input::Initialize();

	UI_Manager::Initialize();




	testObject = new GameObject(L"TEST");
	testObject->GetComponentHolder()->AddComponent<SpriteRenderer>();

	auto spriteRenderer = testObject->GetComponentHolder()->GetComponent<SpriteRenderer>();
	spriteRenderer->SetTexture(
		ResourceManager::GetResource<Texture>(DM_TEST_TEXTURE_BMP_NAME)
	);
	spriteRenderer->Initialize();

	int a = 0;





	return;
}





void DM::Application::Update()
{

	Input::Update();

	UI_Manager::Update();

	return;
}





void DM::Application::Render()
{

	Application::clearRenderTarget(
		Application::getDeviceContext_Back()
	);

	// render all objects
	UI_Manager::Render(Application::getDeviceContext_Back());

	auto spriteRenderer = testObject->GetComponentHolder()->GetComponent<SpriteRenderer>();
	if (spriteRenderer) { spriteRenderer->Render(Application::getDeviceContext_Back()); }

	Application::copyRenderTarget(
		Application::getDeviceContext_Back(),
		Application::GetDeviceContext()
	);

	return;
}





void DM::Application::Run()
{

	Application::Update();
	Application::Render();

	return;
}





void DM::Application::initializeWindow()
{

	Application::device_context = GetDC(
		Application::GetMainWindow()->GetHandle()
	);

	Application::buffer_back = CreateCompatibleBitmap(
		Application::GetDeviceContext(),
		Application::GetMainWindow()->GetSize().x,
		Application::GetMainWindow()->GetSize().y
	);

	Application::device_context_back = CreateCompatibleDC(
		Application::GetDeviceContext()
	);

	HBITMAP oldBitMap = (HBITMAP)SelectObject(
		Application::device_context_back,
		Application::buffer_back
	);

	DeleteObject(oldBitMap);

	return;
}





void DM::Application::clearRenderTarget(HDC hdc)
{

	HBRUSH brush = (HBRUSH)CreateSolidBrush(RGB(128, 128, 128));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

	Rectangle(hdc, -1, -1,
		Application::GetMainWindow()->GetSize().x + 1,
		Application::GetMainWindow()->GetSize().y + 1);

	SelectObject(hdc, oldBrush);
	DeleteObject(brush);

	return;
}





void DM::Application::copyRenderTarget(HDC sourceDC, HDC destDC)
{

	BitBlt(
		destDC, 0, 0,
		Application::GetMainWindow()->GetSize().x,
		Application::GetMainWindow()->GetSize().y,
		sourceDC, 0, 0, SRCCOPY
	);

	return;
}