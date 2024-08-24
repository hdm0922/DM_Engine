#include "DM_Texture.h"

#include "DM_Application.h"





DM::Texture::Texture(const std::wstring& path, const std::wstring& name)
	: Resource(path, name)
	, textureType(Texture::getTextureTypeByExtension(path))
{
}





DM::Texture::~Texture()
{
}





void DM::Texture::Load()
{

	switch (this->GetTextureType())
	{
	case Enums::TextureType::bmp: this->loadImage_bmp(); break;
	case Enums::TextureType::png: this->loadImage_png(); break;
	}

	return;
}





DM::Enums::TextureType DM::Texture::getTextureTypeByExtension(const std::wstring& path)
{
	const std::wstring& extension = path.substr(path.find_last_of(L".") + 1);

	if (extension == L"bmp") return Enums::TextureType::bmp;
	if (extension == L"png") return Enums::TextureType::png;

	return Enums::TextureType::None;
}





void DM::Texture::loadImage_bmp()
{

	this->bitmap = (HBITMAP)LoadImageW(
		nullptr, this->GetPath().c_str(), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	BITMAP info = {};
	GetObject(this->bitmap, sizeof(BITMAP), &info);

	this->SetSize(info.bmWidth, info.bmHeight);

	HBITMAP oldBitmap =

		(HBITMAP)SelectObject(
		CreateCompatibleDC(Application::GetDeviceContext()),
			this->bitmap
		);

	DeleteObject(oldBitmap);

	return;
}





void DM::Texture::loadImage_png()
{

	this->image = Gdiplus::Image::FromFile(this->GetPath().c_str());

	this->SetWidth(this->image->GetWidth());
	this->SetHeight(this->image->GetHeight());

	return;
}
