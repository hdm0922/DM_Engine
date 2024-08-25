#pragma once
#include "DM_Resource.h"





namespace DM
{
    class Texture;
}





class DM::Texture :
    public Resource
{

public:

    Texture(const std::wstring& path, const std::wstring& name = L"");
    virtual ~Texture() override;

    virtual void Load() override;


public:

    void SetHeight(UINT height) { this->SetSize({ this->size.x, height }); }
    void SetWidth(UINT width) { this->SetSize({ width, this->size.y }); }
    void SetSize(UINT width, UINT height) { this->SetSize({ width, height }); }
    void SetSize(const Math::Vector2<UINT>& size) { this->size = size; }

    HDC GetDeviceContext() const { return this->bitmap_device_context; }
    Gdiplus::Image* GetImage() const { return this->image; }
    UINT GetHeight() const { return this->size.y; }
    UINT GetWidth() const { return this->size.x; }
    Math::Vector2<UINT> GetSize() const { return this->size; }
    const Enums::TextureType GetTextureType() const { return this->textureType; }


private:

    static Enums::TextureType getTextureTypeByExtension(const std::wstring& path);

    void loadImage_bmp();
    void loadImage_png();


private:

    // bmp
    HBITMAP bitmap;
    HDC bitmap_device_context;

    // png
    Gdiplus::Image* image;

    // image attributes
    const Enums::TextureType textureType;
    Math::Vector2<UINT> size;
};

